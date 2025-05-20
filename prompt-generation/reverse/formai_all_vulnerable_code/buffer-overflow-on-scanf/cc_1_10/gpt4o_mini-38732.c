//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    if (rowsA > MAX_SIZE || colsA > MAX_SIZE) {
        printf("Matrix size exceeds maximum limit of %d x %d\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }
    inputMatrix(matrixA, rowsA, colsA);
    displayMatrix(matrixA, rowsA, colsA);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    if (rowsB > MAX_SIZE || colsB > MAX_SIZE) {
        printf("Matrix size exceeds maximum limit of %d x %d\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }
    inputMatrix(matrixB, rowsB, colsB);
    displayMatrix(matrixB, rowsB, colsB);

    // Addition
    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(matrixA, matrixB, result, rowsA, colsA);
        printf("Result of Matrix A + Matrix B:\n");
        displayMatrix(result, rowsA, colsA);
    } else {
        printf("Matrices cannot be added due to dimension mismatch.\n");
    }

    // Subtraction
    if (rowsA == rowsB && colsA == colsB) {
        subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
        printf("Result of Matrix A - Matrix B:\n");
        displayMatrix(result, rowsA, colsA);
    } else {
        printf("Matrices cannot be subtracted due to dimension mismatch.\n");
    }

    // Multiplication
    if (colsA == rowsB) {
        multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
        printf("Result of Matrix A * Matrix B:\n");
        displayMatrix(result, rowsA, colsB);
    } else {
        printf("Matrices cannot be multiplied due to dimension mismatch.\n");
    }

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}