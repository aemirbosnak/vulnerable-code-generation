//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function Declarations
void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void addMatrices(int matA[MAX_ROWS][MAX_COLS], int matB[MAX_ROWS][MAX_COLS], int res[MAX_ROWS][MAX_COLS], int rows, int cols);
void multiplyMatrices(int matA[MAX_ROWS][MAX_COLS], int matB[MAX_ROWS][MAX_COLS], int res[MAX_ROWS][MAX_COLS], int rowsA, int colsA, int rowsB, int colsB);
void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int transposed[MAX_ROWS][MAX_COLS], int rows, int cols);

int main() {
    int matA[MAX_ROWS][MAX_COLS], matB[MAX_ROWS][MAX_COLS], res[MAX_ROWS][MAX_COLS];
    int rowsA, colsA, rowsB, colsB;

    // Input for First Matrix
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Input Matrix A:\n");
    inputMatrix(matA, rowsA, colsA);

    // Input for Second Matrix
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    printf("Input Matrix B:\n");
    inputMatrix(matB, rowsB, colsB);

    // Addition
    if (rowsA == rowsB && colsA == colsB) {
        printf("\nResult of Matrix Addition:\n");
        addMatrices(matA, matB, res, rowsA, colsA);
        printMatrix(res, rowsA, colsA);
    } else {
        printf("Matrices cannot be added due to mismatch in dimensions.\n");
    }

    // Multiplication
    if (colsA == rowsB) {
        printf("\nResult of Matrix Multiplication:\n");
        multiplyMatrices(matA, matB, res, rowsA, colsA, rowsB, colsB);
        printMatrix(res, rowsA, colsB);
    } else {
        printf("Matrices cannot be multiplied due to incompatible dimensions.\n");
    }

    // Transpose of Matrix A
    int transposedA[MAX_ROWS][MAX_COLS];
    transposeMatrix(matA, transposedA, rowsA, colsA);
    printf("\nTranspose of Matrix A:\n");
    printMatrix(transposedA, colsA, rowsA);

    return 0;
}

void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matA[MAX_ROWS][MAX_COLS], int matB[MAX_ROWS][MAX_COLS], int res[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            res[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void multiplyMatrices(int matA[MAX_ROWS][MAX_COLS], int matB[MAX_ROWS][MAX_COLS], int res[MAX_ROWS][MAX_COLS], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            res[i][j] = 0; // Initialize the result matrix element
            for (int k = 0; k < colsA; ++k) {
                res[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int transposed[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
}