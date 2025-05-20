//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_ITERATIONS 100

int main()
{
    int size, iterations;
    int *arr;
    double elapsed_time;
    int i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < size; i++)
    {
        arr[i] = i;
    }

    printf("Original array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start_time, end_time;
    double start_sec, end_sec, cpu_time_used;

    start_time = clock();
    for (i = 0; i < iterations; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[j] = arr[j] * 2;
        }
    }
    end_time = clock();

    start_sec = (double)start_time / CLOCKS_PER_SEC;
    end_sec = (double)end_time / CLOCKS_PER_SEC;
    cpu_time_used = (end_sec - start_sec);

    elapsed_time = cpu_time_used;

    printf("Elapsed time: %.6f seconds\n", elapsed_time);

    free(arr);

    return 0;
}