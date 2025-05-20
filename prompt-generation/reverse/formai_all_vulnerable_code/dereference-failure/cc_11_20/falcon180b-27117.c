//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 1000
#define PI 3.14159265358979323846

int main() {
    int n, i, j, k;
    double x, y, z, sum = 0.0;
    double **a, **b, **c;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    a = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        a[i] = (double *)malloc(n * sizeof(double));
    }

    b = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        b[i] = (double *)malloc(n * sizeof(double));
    }

    c = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        c[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Enter the coefficients of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the coefficients of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &b[i][j]);
        }
    }

    start = clock();
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The product of matrices A and B is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", c[i][j]);
        }
        printf("\n");
    }

    printf("The CPU time used is %lf seconds.\n", cpu_time_used);

    return 0;
}