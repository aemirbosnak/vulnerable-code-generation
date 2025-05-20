//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    // Input for the first matrix
    printf("Matrix A:\n");
    printf("Enter the number of rows and columns (e.g., 3 3): ");
    scanf("%d %d", &rowsA, &colsA);
    inputMatrix(matrixA, rowsA, colsA);
    displayMatrix(matrixA, rowsA, colsA);

    // Input for the second matrix
    printf("Matrix B:\n");
    printf("Enter the number of rows and columns (e.g., 3 3): ");
    scanf("%d %d", &rowsB, &colsB);
    inputMatrix(matrixB, rowsB, colsB);
    displayMatrix(matrixB, rowsB, colsB);

    // Addition
    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(matrixA, matrixB, result, rowsA, colsA);
        printf("Result of A + B:\n");
        displayMatrix(result, rowsA, colsA);
    } else {
        printf("Matrices A and B cannot be added due to different dimensions.\n");
    }

    // Subtraction
    if (rowsA == rowsB && colsA == colsB) {
        subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
        printf("Result of A - B:\n");
        displayMatrix(result, rowsA, colsA);
    } else {
        printf("Matrices A and B cannot be subtracted due to different dimensions.\n");
    }

    // Multiplication
    if (colsA == rowsB) {
        multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
        printf("Result of A * B:\n");
        displayMatrix(result, rowsA, colsB);
    } else {
        printf("Matrices A and B cannot be multiplied due to incompatible dimensions.\n");
    }

    return 0;
}