//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrixMultiplication(int rows, int columns, int **A, int **B, int **C) {
    int i, j, k;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            C[i][j] = 0;
            for (k = 0; k < rows; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int rows, int columns, int **matrix) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, columns, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    int **A = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        A[i] = (int *)malloc(columns * sizeof(int));
    }

    int **B = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        B[i] = (int *)malloc(columns * sizeof(int));
    }

    int **C = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        C[i] = (int *)malloc(columns * sizeof(int));
    }

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    clock_t start = clock();
    matrixMultiplication(rows, columns, A, B, C);
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nThe product of matrices A and B is:\n");
    printMatrix(rows, columns, C);

    printf("\nCPU time used: %lf seconds\n", cpu_time_used);

    for (i = 0; i < rows; i++) {
        free(A[i]);
    }
    free(A);

    for (i = 0; i < rows; i++) {
        free(B[i]);
    }
    free(B);

    for (i = 0; i < rows; i++) {
        free(C[i]);
    }
    free(C);

    return 0;
}