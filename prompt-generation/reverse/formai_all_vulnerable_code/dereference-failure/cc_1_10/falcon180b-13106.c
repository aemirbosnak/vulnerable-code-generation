//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int i, j, sum;
    int *arr;
    double start_time, end_time, elapsed_time;

    // Allocate memory for the array
    arr = (int *)malloc(SIZE * sizeof(int));

    // Initialize the array with random numbers
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Start the timer
    start_time = clock();

    // Sort the array using bubble sort
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Stop the timer
    end_time = clock();

    // Calculate the elapsed time
    elapsed_time = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;

    // Calculate the sum of the sorted array
    sum = 0;
    for (i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    // Print the results
    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSum: %d\n", sum);
    printf("Elapsed time: %.6f seconds\n", elapsed_time);

    // Free the memory
    free(arr);

    return 0;
}