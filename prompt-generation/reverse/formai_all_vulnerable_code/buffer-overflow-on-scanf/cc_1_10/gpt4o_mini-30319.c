//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void inputMatrix(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);
int **addMatrices(int **matrixA, int **matrixB, int rows, int cols);
int **multiplyMatrices(int **matrixA, int **matrixB, int rowsA, int colsA, int colsB);
void freeMatrix(int **matrix, int rows);

int main() {
    int rows, cols;

    printf("Enter number of rows for the matrices: ");
    scanf("%d", &rows);
    printf("Enter number of columns for the matrices: ");
    scanf("%d", &cols);

    // Dynamic memory allocation for matrices
    int **matrixA = (int **)malloc(rows * sizeof(int *));
    int **matrixB = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrixA[i] = (int *)malloc(cols * sizeof(int));
        matrixB[i] = (int *)malloc(cols * sizeof(int));
    }

    // Input matrices
    printf("Input elements for Matrix A:\n");
    inputMatrix(matrixA, rows, cols);
    printf("Input elements for Matrix B:\n");
    inputMatrix(matrixB, rows, cols);
    
    // Print matrices
    printf("\nMatrix A:\n");
    printMatrix(matrixA, rows, cols);
    printf("\nMatrix B:\n");
    printMatrix(matrixB, rows, cols);

    // Matrix Addition
    int **resultAdd = addMatrices(matrixA, matrixB, rows, cols);
    printf("\nResult of Addition (A + B):\n");
    printMatrix(resultAdd, rows, cols);

    // Matrix Multiplication
    int **matrixC = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++) {
        matrixC[i] = (int *)malloc(rows * sizeof(int));
    }
    
    printf("Input elements for Matrix C (for multiplication, must have %d rows):\n", cols);
    inputMatrix(matrixC, cols, rows); // Note: transpose in terms of dimensionality for multiplication

    int **resultMul = multiplyMatrices(matrixA, matrixC, rows, cols, rows);
    printf("\nResult of Multiplication (A * C):\n");
    printMatrix(resultMul, rows, rows);

    // Free allocated memory
    freeMatrix(matrixA, rows);
    freeMatrix(matrixB, rows);
    freeMatrix(resultAdd, rows);
    freeMatrix(matrixC, cols);
    freeMatrix(resultMul, rows);

    return 0;
}

void inputMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **addMatrices(int **matrixA, int **matrixB, int rows, int cols) {
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return result;
}

int **multiplyMatrices(int **matrixA, int **matrixB, int rowsA, int colsA, int colsB) {
    int **result = (int **)malloc(rowsA * sizeof(int *));
    for (int i = 0; i < rowsA; i++) {
        result[i] = (int *)malloc(colsB * sizeof(int));
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize result matrix
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}