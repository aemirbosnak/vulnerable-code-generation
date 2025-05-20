//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function declarations
void displayMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]);
void addMatrices(int rows, int cols, int matrixA[MAX_ROWS][MAX_COLS], int matrixB[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]);
void multiplyMatrices(int rowsA, int colsA, int matrixA[MAX_ROWS][MAX_COLS], int rowsB, int colsB, int matrixB[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]);
void transposeMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]);
void fillMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]);

int main() {
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX_ROWS][MAX_COLS];
    int matrixB[MAX_ROWS][MAX_COLS];
    int result[MAX_ROWS][MAX_COLS];
    
    // Input for matrix A
    printf("Enter rows and columns for first matrix (A): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Fill matrix A:\n");
    fillMatrix(rowsA, colsA, matrixA);
    
    // Input for matrix B
    printf("Enter rows and columns for second matrix (B): ");
    scanf("%d %d", &rowsB, &colsB);
    printf("Fill matrix B:\n");
    fillMatrix(rowsB, colsB, matrixB);
    
    // Display matrices
    printf("\nMatrix A:\n");
    displayMatrix(rowsA, colsA, matrixA);
    printf("Matrix B:\n");
    displayMatrix(rowsB, colsB, matrixB);
    
    // Addition of matrices
    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(rowsA, colsA, matrixA, matrixB, result);
        printf("\nSum of A and B:\n");
        displayMatrix(rowsA, colsA, result);
    } else {
        printf("\nAddition not possible. Matrices must be of same dimensions.\n");
    }

    // Multiplication of matrices
    if (colsA == rowsB) {
        multiplyMatrices(rowsA, colsA, matrixA, rowsB, colsB, matrixB, result);
        printf("\nProduct of A and B:\n");
        displayMatrix(rowsA, colsB, result);
    } else {
        printf("\nMultiplication not possible. Columns of A must equal rows of B.\n");
    }
    
    // Transpose of matrix A
    transposeMatrix(rowsA, colsA, matrixA, result);
    printf("\nTranspose of Matrix A:\n");
    displayMatrix(colsA, rowsA, result);

    return 0;
}

void fillMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int matrixA[MAX_ROWS][MAX_COLS], int matrixB[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int rowsA, int colsA, int matrixA[MAX_ROWS][MAX_COLS], int rowsB, int colsB, int matrixB[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}