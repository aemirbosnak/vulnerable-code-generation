//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITERATIONS 1000000

void matrix_multiply(int n, int **A, int **B, int **C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int n = 1000;
    int **A, **B, **C;
    int i, j, k;

    A = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
        }
    }

    B = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        B[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            B[i][j] = rand() % 10;
        }
    }

    C = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        C[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    clock_t start_time = clock();
    for (i = 0; i < NUM_ITERATIONS; i++) {
        matrix_multiply(n, A, B, C);
    }
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);

    for (i = 0; i < n; i++) {
        free(B[i]);
    }
    free(B);

    for (i = 0; i < n; i++) {
        free(C[i]);
    }
    free(C);

    return 0;
}