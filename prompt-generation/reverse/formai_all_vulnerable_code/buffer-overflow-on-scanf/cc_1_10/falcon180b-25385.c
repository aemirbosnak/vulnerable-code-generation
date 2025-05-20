//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void surreal_benchmark(int n) {
    int i, j, k;
    double start, end;

    // Initialize random seed
    srand(time(NULL));

    // Allocate memory for matrices
    int **A = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
    }
    int **B = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        B[i] = (int *)malloc(n * sizeof(int));
    }
    int **C = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        C[i] = (int *)malloc(n * sizeof(int));
    }

    // Fill matrices with random numbers
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Start timer
    start = clock();

    // Multiply matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Stop timer and print result
    end = clock();
    printf("Matrix multiplication took %f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Free memory
    for (i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}

int main() {
    int n;

    printf("Enter the size of the matrices: ");
    scanf("%d", &n);

    surreal_benchmark(n);

    return 0;
}