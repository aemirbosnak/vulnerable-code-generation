//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int i, j, k;
    int *array;
    clock_t start, end;

    // Allocate memory for array
    array = (int *) malloc(SIZE * sizeof(int));

    // Initialize array with random values
    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % 10;
    }

    // Sort array using bubble sort
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Measure time taken to sort array
    start = clock();
    for (k = 0; k < SIZE; k++) {
        for (i = 0; i < SIZE - 1; i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    end = clock();

    // Print sorted array
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    // Free memory
    free(array);

    printf("\nTime taken to sort array: %lf seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    return 0;
}