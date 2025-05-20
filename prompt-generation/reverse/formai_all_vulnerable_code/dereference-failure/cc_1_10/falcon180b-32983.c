//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000000

int main() {
    int i, j;
    double **a, **b, **c;
    clock_t start, end;

    srand(time(NULL));

    // Allocate memory for matrices
    a = (double **)malloc(sizeof(double *) * 2);
    b = (double **)malloc(sizeof(double *) * 2);
    c = (double **)malloc(sizeof(double *) * 2);

    for (i = 0; i < 2; i++) {
        a[i] = (double *)malloc(sizeof(double) * SIZE);
        b[i] = (double *)malloc(sizeof(double) * SIZE);
        c[i] = (double *)malloc(sizeof(double) * SIZE);
    }

    // Fill matrices with random values
    for (i = 0; i < 2; i++) {
        for (j = 0; j < SIZE; j++) {
            a[i][j] = rand() % 100;
            b[i][j] = rand() % 100;
        }
    }

    // Start timer
    start = clock();

    // Perform matrix multiplication
    for (i = 0; i < 2; i++) {
        for (j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Stop timer
    end = clock();

    // Print result and execution time
    for (i = 0; i < 2; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Free memory
    for (i = 0; i < 2; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }

    return 0;
}