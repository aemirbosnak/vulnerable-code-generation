//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function to create a matrix of size rows x cols
void createMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix of size rows x cols
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize the result matrix
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Main function
int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    createMatrix(matrixA, rowsA, colsA);
    displayMatrix(matrixA, rowsA, colsA);

    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    createMatrix(matrixB, rowsB, colsB);
    displayMatrix(matrixB, rowsB, colsB);

    if (rowsA == rowsB && colsA == colsB) {
        int additionResult[MAX][MAX];
        addMatrices(matrixA, matrixB, additionResult, rowsA, colsA);
        printf("Matrix A + Matrix B:\n");
        displayMatrix(additionResult, rowsA, colsA);
    } else {
        printf("Matrices cannot be added due to different dimensions.\n");
    }

    if (colsA == rowsB) {
        int multiplicationResult[MAX][MAX];
        multiplyMatrices(matrixA, matrixB, multiplicationResult, rowsA, colsA, colsB);
        printf("Matrix A * Matrix B:\n");
        displayMatrix(multiplicationResult, rowsA, colsB);
    } else {
        printf("Matrices cannot be multiplied due to incompatible dimensions.\n");
    }

    int transposedResult[MAX][MAX];
    transposeMatrix(matrixA, transposedResult, rowsA, colsA);
    printf("Transpose of Matrix A:\n");
    displayMatrix(transposedResult, colsA, rowsA);

    return 0;
}