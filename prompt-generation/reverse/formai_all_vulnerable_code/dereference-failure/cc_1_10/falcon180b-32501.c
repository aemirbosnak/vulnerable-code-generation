//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int i, j, k;
    int *arr1, *arr2, *arr3;
    double start, end;

    // Allocate memory for arrays
    arr1 = (int *)malloc(sizeof(int) * SIZE);
    arr2 = (int *)malloc(sizeof(int) * SIZE);
    arr3 = (int *)malloc(sizeof(int) * SIZE);

    // Initialize arrays
    for (i = 0; i < SIZE; i++) {
        arr1[i] = i;
        arr2[i] = i * 2;
    }

    // Sort arr2 in ascending order
    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (arr2[i] > arr2[j]) {
                k = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = k;
            }
        }
    }

    // Measure time for sorting
    start = clock();
    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (arr2[i] > arr2[j]) {
                k = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = k;
            }
        }
    }
    end = clock();

    // Calculate time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate percentage of time taken
    double percentage = (time_taken / (double)SIZE) * 100;

    // Print results
    printf("Time taken for sorting: %lf\n", time_taken);
    printf("Percentage of time taken: %.2lf%%\n", percentage);

    // Free memory
    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}