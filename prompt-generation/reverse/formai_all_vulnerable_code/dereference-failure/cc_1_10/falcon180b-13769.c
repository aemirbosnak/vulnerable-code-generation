//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5000000

int main() {
    int *arr;
    int i;
    clock_t start, end;
    double cpu_time_used;

    // Allocate memory for the array
    arr = (int *)malloc(SIZE * sizeof(int));

    // Initialize the array
    for (i = 0; i < SIZE; i++) {
        arr[i] = i;
    }

    // Start the timer
    start = clock();

    // Sort the array
    for (i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Stop the timer
    end = clock();

    // Calculate the CPU time used
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the CPU time used
    printf("CPU time used: %lf seconds\n", cpu_time_used);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}