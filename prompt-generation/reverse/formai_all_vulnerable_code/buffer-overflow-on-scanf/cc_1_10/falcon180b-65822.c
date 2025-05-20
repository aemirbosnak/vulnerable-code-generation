//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n, i;
    double start_time, end_time, elapsed_time;
    int *arr;
    srand(time(NULL));

    // Prompt user for array size
    printf("Enter array size: ");
    scanf("%d", &n);

    // Allocate memory for array
    arr = (int*)malloc(n * sizeof(int));

    // Populate array with random integers
    for(i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Sort array using bubble sort
    for(i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Measure time taken for sorting
    start_time = clock();
    for(i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end_time = clock();
    elapsed_time = (end_time - start_time) / (double)CLOCKS_PER_SEC;

    // Print sorted array and time taken for sorting
    printf("Sorted array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken for sorting: %.6f seconds\n", elapsed_time);

    // Free memory allocated for array
    free(arr);

    return 0;
}