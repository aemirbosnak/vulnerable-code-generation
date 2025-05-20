//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    int n, m, i, j, k, l, sum = 0;
    double a[100][100], b[100][100], c[100][100];
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &n, &m);

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%lf", &b[i][j]);
        }
    }

    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < n; k++) {
                for (l = 0; l < m; l++) {
                    c[i][j] += a[i][k] * b[k][l] * c[l][j];
                }
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The result of matrix multiplication is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%lf ", c[i][j]);
        }
        printf("\n");
    }

    printf("Time taken for matrix multiplication: %lf seconds\n", cpu_time_used);

    return 0;
}