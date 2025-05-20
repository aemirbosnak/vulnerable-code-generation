//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main(int argc, char *argv[]) {
    int i, j, n;
    int *arr;
    clock_t start, end;
    double cpu_time_used;

    // Allocate memory for the array
    arr = (int *)malloc(MAX_SIZE * sizeof(int));

    // Initialize the array with random values
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array using bubble sort
    for (n = 0; n < 5; n++) {
        for (i = 0; i < MAX_SIZE - n - 1; i++) {
            for (j = 0; j < MAX_SIZE - n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Measure the time it takes to sort the array
    start = clock();
    for (n = 0; n < 5; n++) {
        for (i = 0; i < MAX_SIZE - n - 1; i++) {
            for (j = 0; j < MAX_SIZE - n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort the array: %.6f seconds\n", cpu_time_used);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}