//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int n, i, j, k, m, count = 0;
    double a[100][100], b[100][100], c[100][100], sum = 0;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d%d", &n, &m);

    // Input first matrix
    printf("\nEnter elements of first matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    // Input second matrix
    printf("\nEnter elements of second matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%lf", &b[i][j]);
        }
    }

    // Multiply matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Calculate sum of elements in result matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            sum += c[i][j];
        }
    }

    // Calculate time taken for matrix multiplication
    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nResultant matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%lf\t", c[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of elements in result matrix: %lf\n", sum);
    printf("Time taken for matrix multiplication: %lf seconds\n", cpu_time_used);

    return 0;
}