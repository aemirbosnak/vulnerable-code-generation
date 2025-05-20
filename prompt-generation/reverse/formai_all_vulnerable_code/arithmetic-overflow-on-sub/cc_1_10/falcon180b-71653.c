//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_ITERATIONS 100

int main(int argc, char *argv[]) {
    int size = MAX_SIZE;
    int iterations = MAX_ITERATIONS;
    int i, j, k;
    double sum = 0;
    clock_t start, end;

    // Argument parsing
    if (argc > 1) {
        size = atoi(argv[1]);
    }
    if (argc > 2) {
        iterations = atoi(argv[2]);
    }

    // Allocate memory
    int *array = (int *) malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }

    // Initialize array
    for (i = 0; i < size; i++) {
        array[i] = i;
    }

    // Benchmarking
    for (k = 0; k < iterations; k++) {
        start = clock();
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                sum += array[i] * array[j];
            }
        }
        end = clock();
        printf("Iteration %d: Time taken = %.6f seconds\n", k+1, (double)(end - start) / CLOCKS_PER_SEC);
        sum = 0;
    }

    // Free memory
    free(array);

    return 0;
}