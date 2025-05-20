//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrixMultiplication(int m, int n, int p, int A[m][n], int B[n][p], int C[m][p]) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int m, n, p;
    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &m, &n);
    int A[m][n];
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &n, &p);
    int B[n][p];
    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    int C[m][p];
    clock_t start = clock();
    matrixMultiplication(m, n, p, A, B, C);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The product of matrices A and B is:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("Time taken for matrix multiplication: %lf seconds\n", time_taken);
    return 0;
}