//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int n, i, j, k;
    double sum = 0.0, start_time, end_time;
    int *arr;

    // Get input from user
    printf("Enter the size of array: ");
    scanf("%d", &n);

    // Allocate memory for array
    arr = (int *)malloc(n * sizeof(int));

    // Fill array with random values
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    // Calculate sum of array elements
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    printf("Original array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Start timer
    start_time = clock();

    // Sort array in ascending order
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // End timer
    end_time = clock();

    // Calculate time taken
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate sum of array elements after sorting
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print time taken and sum of array elements
    printf("Time taken: %.6f seconds\n", elapsed_time);
    printf("Sum of array elements: %d\n", sum);

    // Free memory allocated for array
    free(arr);

    return 0;
}