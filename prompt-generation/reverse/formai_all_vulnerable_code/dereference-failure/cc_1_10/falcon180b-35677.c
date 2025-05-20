//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 1000000
#define ITERATIONS 10000

int main() {
    int i, j, k;
    double **a, **b, **c;
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL));

    a = (double **)malloc(SIZE * sizeof(double *));
    for (i = 0; i < SIZE; i++) {
        a[i] = (double *)malloc(SIZE * sizeof(double));
        for (j = 0; j < SIZE; j++) {
            a[i][j] = rand() % 100;
        }
    }

    b = (double **)malloc(SIZE * sizeof(double *));
    for (i = 0; i < SIZE; i++) {
        b[i] = (double *)malloc(SIZE * sizeof(double));
        for (j = 0; j < SIZE; j++) {
            b[i][j] = rand() % 100;
        }
    }

    start = clock();
    for (k = 0; k < ITERATIONS; k++) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                c[i][j] += a[i][j] * b[i][j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU time used: %lf seconds\n", cpu_time_used);

    for (i = 0; i < SIZE; i++) {
        free(a[i]);
    }
    free(a);

    for (i = 0; i < SIZE; i++) {
        free(b[i]);
    }
    free(b);

    return 0;
}