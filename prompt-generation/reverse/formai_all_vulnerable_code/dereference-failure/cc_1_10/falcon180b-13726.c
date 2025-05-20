//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main(void) {
    int i, j, k;
    int *array1, *array2;
    clock_t start, end;

    srand(time(NULL));

    // Allocate memory for arrays
    array1 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (array1 == NULL) {
        printf("Memory error!\n");
        exit(1);
    }

    array2 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (array2 == NULL) {
        printf("Memory error!\n");
        exit(1);
    }

    // Initialize arrays with random values
    for (i = 0; i < ARRAY_SIZE; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    // Start benchmarking
    start = clock();

    // Sum elements in arrays
    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = 0; j < ARRAY_SIZE; j++) {
            for (k = 0; k < ARRAY_SIZE; k++) {
                array1[i] += array2[j] * array2[k];
            }
        }
    }

    // End benchmarking
    end = clock();

    // Calculate time taken
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU time used: %f seconds\n", cpu_time_used);

    // Free memory
    free(array1);
    free(array2);

    return 0;
}