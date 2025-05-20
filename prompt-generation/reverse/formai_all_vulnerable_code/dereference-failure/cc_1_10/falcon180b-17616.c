//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define SIZE 1000000

int main() {
    int i, j;
    double *A, *B, *C;
    double alpha = 1.0;
    struct timespec start, end;

    // Allocate memory for matrices
    A = (double *) malloc(sizeof(double) * SIZE * SIZE);
    B = (double *) malloc(sizeof(double) * SIZE * SIZE);
    C = (double *) malloc(sizeof(double) * SIZE * SIZE);

    // Initialize matrices
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            A[i * SIZE + j] = i + j;
            B[i * SIZE + j] = i - j;
        }
    }

    // Start timer
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Perform matrix multiplication
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            C[i * SIZE + j] = 0.0;
            for (int k = 0; k < SIZE; k++) {
                C[i * SIZE + j] += alpha * A[i * SIZE + k] * B[k * SIZE + j];
            }
        }
    }

    // Stop timer
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate elapsed time
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    // Print results
    printf("Elapsed time: %f seconds\n", elapsed_time);

    // Free memory
    free(A);
    free(B);
    free(C);

    return 0;
}