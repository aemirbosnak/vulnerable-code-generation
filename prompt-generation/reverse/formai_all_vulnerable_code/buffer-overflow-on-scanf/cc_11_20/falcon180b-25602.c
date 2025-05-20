//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 100000

int main(int argc, char *argv[]) {
    int i, j, n, m;
    double **matrixA, **matrixB, **result;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of matrices: ");
    scanf("%d", &n);

    matrixA = (double **)malloc(n * sizeof(double *));
    matrixB = (double **)malloc(n * sizeof(double *));
    result = (double **)malloc(n * sizeof(double *));

    for (i = 0; i < n; i++) {
        matrixA[i] = (double *)malloc(n * sizeof(double));
        matrixB[i] = (double *)malloc(n * sizeof(double));
        result[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Enter the elements of matrix A: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &matrixA[i][j]);
        }
    }

    printf("Enter the elements of matrix B: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &matrixB[i][j]);
        }
    }

    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The sum of matrices is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

    printf("Time taken: %lf seconds\n", cpu_time_used);

    for (i = 0; i < n; i++) {
        free(matrixA[i]);
        free(matrixB[i]);
        free(result[i]);
    }
    free(matrixA);
    free(matrixB);
    free(result);

    return 0;
}