//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%4d ", matrix[r][c]);
        }
        printf("\n");
    }
}

int** createMatrix(int rows, int cols) {
    int **mat = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat[i] = (int*)malloc(cols * sizeof(int));
    }
    return mat;
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void matrixAddition(int **a, int **b, int **result, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void matrixSubtraction(int **a, int **b, int **result, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void matrixMultiplication(int **a, int **b, int **result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int **transposeMatrix(int **matrix, int rows, int cols) {
    int **transposed = createMatrix(cols, rows);
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            transposed[c][r] = matrix[r][c];
        }
    }
    return transposed;
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    printf("Enter rows and columns for first matrix (A): ");
    scanf("%d %d", &rowsA, &colsA);

    int **matrixA = createMatrix(rowsA, colsA);
    printf("Enter elements of first matrix (A):\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("\nEnter rows and columns for second matrix (B): ");
    scanf("%d %d", &rowsB, &colsB);

    int **matrixB = createMatrix(rowsB, colsB);
    printf("Enter elements of second matrix (B):\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    //**** Addition ****//
    if (rowsA == rowsB && colsA == colsB) {
        int **resultAdd = createMatrix(rowsA, colsA);
        matrixAddition(matrixA, matrixB, resultAdd, rowsA, colsA);
        printf("\nAddition of A and B:\n");
        printMatrix(resultAdd, rowsA, colsA);
        freeMatrix(resultAdd, rowsA);
    } else {
        printf("\nMatrix addition not possible!\n");
    }

    //**** Subtraction ****//
    if (rowsA == rowsB && colsA == colsB) {
        int **resultSub = createMatrix(rowsA, colsA);
        matrixSubtraction(matrixA, matrixB, resultSub, rowsA, colsA);
        printf("\nSubtraction of A and B:\n");
        printMatrix(resultSub, rowsA, colsA);
        freeMatrix(resultSub, rowsA);
    } else {
        printf("\nMatrix subtraction not possible!\n");
    }

    //**** Multiplication ****//
    if (colsA == rowsB) {
        int **resultMul = createMatrix(rowsA, colsB);
        matrixMultiplication(matrixA, matrixB, resultMul, rowsA, colsA, colsB);
        printf("\nMultiplication of A and B:\n");
        printMatrix(resultMul, rowsA, colsB);
        freeMatrix(resultMul, rowsA);
    } else {
        printf("\nMatrix multiplication not possible!\n");
    }

    //**** Transpose ****//
    int **transposedA = transposeMatrix(matrixA, rowsA, colsA);
    printf("\nTranspose of matrix A:\n");
    printMatrix(transposedA, colsA, rowsA);
    freeMatrix(transposedA, colsA);

    int **transposedB = transposeMatrix(matrixB, rowsB, colsB);
    printf("\nTranspose of matrix B:\n");
    printMatrix(transposedB, colsB, rowsB);
    freeMatrix(transposedB, colsB);

    freeMatrix(matrixA, rowsA);
    freeMatrix(matrixB, rowsB);
    return 0;
}