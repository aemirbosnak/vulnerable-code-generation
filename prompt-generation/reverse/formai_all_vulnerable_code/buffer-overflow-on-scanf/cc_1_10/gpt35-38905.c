//FormAI DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void initializeMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    // Generate random values for each element in the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void printMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    // Print out each element in the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int matrix1[][MAX_COLS], int rows1, int cols1, int matrix2[][MAX_COLS], int rows2, int cols2, int result[][MAX_COLS]) {
    // Check if the matrices can be multiplied
    if (cols1 != rows2) {
        printf("Error: the number of columns in Matrix A must match the number of rows in Matrix B\n");
        return;
    }

    // Multiply the matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrixA[MAX_ROWS][MAX_COLS], matrixB[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int rowsA, colsA, rowsB, colsB;

    // Read in the dimensions of matrices A and B
    printf("Enter the dimensions of matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter the dimensions of matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);

    // Initialize the matrices with random values
    initializeMatrix(matrixA, rowsA, colsA);
    initializeMatrix(matrixB, rowsB, colsB);

    // Print out the matrices
    printf("Matrix A:\n");
    printMatrix(matrixA, rowsA, colsA);
    printf("\nMatrix B:\n");
    printMatrix(matrixB, rowsB, colsB);

    // Multiply the matrices
    multiplyMatrix(matrixA, rowsA, colsA, matrixB, rowsB, colsB, result);

    // Print out the result matrix
    printf("\nMatrix A * B:\n");
    printMatrix(result, rowsA, colsB);

    return 0;
}