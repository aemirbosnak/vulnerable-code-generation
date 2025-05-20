//Falcon-180B DATASET v1.0 Category: Sorting ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr_size, i, j, temp;
    int *arr;
    time_t start_time, end_time;
    double elapsed_time;

    // Prompt user for array size
    printf("Enter array size: ");
    scanf("%d", &arr_size);

    // Allocate memory for array
    arr = (int *)malloc(arr_size * sizeof(int));

    // Prompt user for array elements
    printf("Enter array elements:\n");
    for (i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Start timer
    time(&start_time);

    // Sort array using bubble sort
    for (i = 0; i < arr_size - 1; i++)
    {
        for (j = 0; j < arr_size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // End timer
    time(&end_time);

    // Calculate elapsed time
    elapsed_time = difftime(end_time, start_time);

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }

    // Print elapsed time
    printf("\nElapsed time: %.2lf seconds\n", elapsed_time);

    // Free memory
    free(arr);
    return 0;
}