//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int n, i, j;
    double **a, **b, **c;
    double *x, *y;
    clock_t start, end;
    double cpu_time_used;

    // read matrix dimensions from command line arguments
    if (argc!= 3) {
        printf("Usage:./program n m\n");
        return 1;
    }
    n = atoi(argv[1]);
    int m = atoi(argv[2]);

    // allocate memory for matrices
    a = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        a[i] = (double *)malloc(m * sizeof(double));
    }
    b = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        b[i] = (double *)malloc(m * sizeof(double));
    }
    c = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        c[i] = (double *)malloc(m * sizeof(double));
    }
    x = (double *)malloc(m * sizeof(double));
    y = (double *)malloc(m * sizeof(double));

    // initialize matrices with random values
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = rand() % 100;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            b[i][j] = rand() % 100;
        }
    }

    // start benchmarking
    start = clock();
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                c[j][k] += a[j][k] * b[k][i];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU Time: %lf seconds\n", cpu_time_used);

    return 0;
}