//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int i, j, k;
    int *array1, *array2;
    clock_t start, end;
    double cpu_time_used;

    // Allocate memory for arrays
    array1 = (int *)malloc(MAX_SIZE * sizeof(int));
    array2 = (int *)malloc(MAX_SIZE * sizeof(int));

    // Initialize arrays with random values
    for (i = 0; i < MAX_SIZE; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    // Start timer
    start = clock();

    // Sort array1 in ascending order
    for (i = 0; i < MAX_SIZE - 1; i++) {
        for (j = i + 1; j < MAX_SIZE; j++) {
            if (array1[i] > array1[j]) {
                k = array1[i];
                array1[i] = array1[j];
                array1[j] = k;
            }
        }
    }

    // Sort array2 in descending order
    for (i = 0; i < MAX_SIZE - 1; i++) {
        for (j = i + 1; j < MAX_SIZE; j++) {
            if (array2[i] < array2[j]) {
                k = array2[i];
                array2[i] = array2[j];
                array2[j] = k;
            }
        }
    }

    // Stop timer
    end = clock();

    // Calculate CPU time used
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print results
    printf("CPU time used: %lf seconds\n", cpu_time_used);

    return 0;
}