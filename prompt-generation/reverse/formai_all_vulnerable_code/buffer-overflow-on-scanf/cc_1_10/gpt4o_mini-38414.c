//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

void displayMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void deallocateMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int** addMatrices(int **matrixA, int **matrixB, int rows, int cols) {
    int **result = allocateMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return result;
}

int** multiplyMatrices(int **matrixA, int **matrixB, int rowsA, int colsA, int colsB) {
    int **result = allocateMatrix(rowsA, colsB);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowsA, &colsA);
    int **matrixA = allocateMatrix(rowsA, colsA);

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowsB, &colsB);
    int **matrixB = allocateMatrix(rowsB, colsB);

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    if (rowsA == rowsB && colsA == colsB) {
        int **addedMatrix = addMatrices(matrixA, matrixB, rowsA, colsA);
        printf("Result of matrix addition:\n");
        displayMatrix(addedMatrix, rowsA, colsA);
        deallocateMatrix(addedMatrix, rowsA);
    } else {
        printf("Addition not possible due to dimension mismatch.\n");
    }

    if (colsA == rowsB) {
        int **multipliedMatrix = multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB);
        printf("Result of matrix multiplication:\n");
        displayMatrix(multipliedMatrix, rowsA, colsB);
        deallocateMatrix(multipliedMatrix, rowsA);
    } else {
        printf("Multiplication not possible due to dimension mismatch.\n");
    }

    deallocateMatrix(matrixA, rowsA);
    deallocateMatrix(matrixB, rowsB);

    return 0;
}