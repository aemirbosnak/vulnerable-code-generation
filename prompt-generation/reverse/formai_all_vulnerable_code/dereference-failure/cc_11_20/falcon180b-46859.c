//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MAX_ITER 100000
#define EPSILON 0.000001

int main() {
    int i, j, k;
    double x, y, z;
    clock_t start, end;
    double cpu_time_used;

    double **A = (double **)malloc(MAX_SIZE * sizeof(double *));
    for (i = 0; i < MAX_SIZE; i++) {
        A[i] = (double *)malloc(MAX_SIZE * sizeof(double));
        for (j = 0; j < MAX_SIZE; j++) {
            A[i][j] = 0.0;
        }
    }

    double **B = (double **)malloc(MAX_SIZE * sizeof(double *));
    for (i = 0; i < MAX_SIZE; i++) {
        B[i] = (double *)malloc(MAX_SIZE * sizeof(double));
        for (j = 0; j < MAX_SIZE; j++) {
            B[i][j] = 0.0;
        }
    }

    double **C = (double **)malloc(MAX_SIZE * sizeof(double *));
    for (i = 0; i < MAX_SIZE; i++) {
        C[i] = (double *)malloc(MAX_SIZE * sizeof(double));
        for (j = 0; j < MAX_SIZE; j++) {
            C[i][j] = 0.0;
        }
    }

    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            A[i][j] = (double)rand() / RAND_MAX;
        }
    }

    start = clock();
    for (k = 0; k < MAX_ITER; k++) {
        for (i = 0; i < MAX_SIZE; i++) {
            for (j = 0; j < MAX_SIZE; j++) {
                x = 0.0;
                for (int l = 0; l < MAX_SIZE; l++) {
                    x += A[i][l] * B[l][j];
                }
                C[i][j] = x;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Multiplication of two %d x %d matrices completed in %lf seconds.\n", MAX_SIZE, MAX_SIZE, cpu_time_used);

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (fabs(C[i][j] - ((double)MAX_ITER * A[i][j] * B[i][j])) > EPSILON) {
                printf("Error: incorrect result at position (%d, %d)\n", i, j);
                exit(1);
            }
        }
    }

    for (i = 0; i < MAX_SIZE; i++) {
        free(A[i]);
    }
    free(A);

    for (i = 0; i < MAX_SIZE; i++) {
        free(B[i]);
    }
    free(B);

    for (i = 0; i < MAX_SIZE; i++) {
        free(C[i]);
    }
    free(C);

    return 0;
}