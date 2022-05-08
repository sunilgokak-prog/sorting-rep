/******************************************************************************

Insertion Sorting Algorithm
Complexity O(n^2)
Inplace, astable
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

static void swap(int *x, int *y)
{
    size_t tmp = 0;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

static void insert_sort(int *arr, size_t n)
{
    size_t i = 0;
    size_t j = 0;
    if (arr) {
        
        for (i= 0 ; i < n; i++)
        {
            for (j = i + 1;  (j > 0) && (j<n); j--)
            {
                if (arr[j-1] >  arr[j]) {
                    swap(&arr[j], &arr[j -1]);
                }
            }
        }
        
    } else {
        printf("Array does not exist");
    }
}

static int * convert_to_int_arr(size_t n, char **argv)
{
    size_t i = 0;
    size_t sum = 0;
    size_t len = 0;
    size_t k  = 0;
    size_t count = 0;
    
    int *arr = calloc (1, sizeof(int)* (n - 1));
    if (arr) {
        for (i = 1; i < n; i++)
        {
          arr[count++] = atoi(argv[i]);
        }
        
    } else {
        printf("\nMemory allocation failed\n");
    }
    
    return arr;
}

static void print_sorted_arr(int *arr, int args)
{
    size_t i = 0;
    printf("\n sorted array\n");
    for (i = 0; i  < args; i++)
    {
        printf("%d ", arr[i]);
    }
    
}
static size_t check_int_arr(size_t n, char **argv )
{
    size_t count = 0;
    size_t i = 1;
    size_t err_flag = 0;
    char *ptr = argv[1];
    while (count   <   (n -1) )
    {
        while(*ptr  != '\0') 
        {
            if (((*argv[i]  - abs('0' - 0)) >= 0) &&  ((*argv[i] - abs('0' - 0) <= 9))) {
                ptr++;
                printf("%c\n", *argv[i]);
                continue;
              } else {
                err_flag = 1;
                break;
            }
        }
        
        if (err_flag == 1) {
          break;
        }
        count++;
        i++;
    }
    if (err_flag) {
        printf("Input validation failed");
    }
    return err_flag;
}

int main(int argc, char *argv[])
{
    int *arr;
    size_t err_flag = 0;
    if (argc > 1 ) {
       err_flag = check_int_arr((size_t) argc, argv);
       if (err_flag == 0) {
        arr =  convert_to_int_arr((size_t) argc, argv);  
        if (arr) {
            print_sorted_arr(arr, argc -1);
            insert_sort(arr, argc -1);
            print_sorted_arr(arr, argc -1);
            free(arr);
        } else {
            printf("Memory could not be allocated to create the array");
        }
        
       } else {
           printf("\n Cannot sort bad array\n");
       }
    } else {
        printf("No args provided other than program name");
    }
    return 0;
}

