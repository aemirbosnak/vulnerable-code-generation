//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free memory of a matrix
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to input matrix elements
void inputMatrix(int** matrix, int rows, int cols) {
    printf("Enter elements of the matrix (%d rows, %d columns):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int** matrix, int rows, int cols) {
    printf("Matrix (%d rows, %d columns):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int** addMatrices(int** matrixA, int** matrixB, int rows, int cols) {
    int** sumMatrix = allocateMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return sumMatrix;
}

// Function to multiply two matrices
int** multiplyMatrices(int** matrixA, int** matrixB, int rowsA, int colsA, int colsB) {
    int** productMatrix = allocateMatrix(rowsA, colsB);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            productMatrix[i][j] = 0; // Initialize the current product element
            for (int k = 0; k < colsA; k++) {
                productMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return productMatrix;
}

// Main function to run the program
int main() {
    int rowsA, colsA, rowsB, colsB;

    printf("Enter the number of rows for Matrix A: ");
    scanf("%d", &rowsA);
    printf("Enter the number of columns for Matrix A: ");
    scanf("%d", &colsA);
    
    int** matrixA = allocateMatrix(rowsA, colsA);
    inputMatrix(matrixA, rowsA, colsA);
    displayMatrix(matrixA, rowsA, colsA);

    printf("Enter the number of rows for Matrix B: ");
    scanf("%d", &rowsB);
    printf("Enter the number of columns for Matrix B: ");
    scanf("%d", &colsB);
    
    int** matrixB = allocateMatrix(rowsB, colsB);
    inputMatrix(matrixB, rowsB, colsB);
    displayMatrix(matrixB, rowsB, colsB);
    
    // Addition and multiplication of matrices
    if (rowsA == rowsB && colsA == colsB) {
        int** sumMatrix = addMatrices(matrixA, matrixB, rowsA, colsA);
        displayMatrix(sumMatrix, rowsA, colsA);
        freeMatrix(sumMatrix, rowsA);
    } else {
        printf("Matrices cannot be added (different dimensions).\n");
    }

    if (colsA == rowsB) {
        int** productMatrix = multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB);
        displayMatrix(productMatrix, rowsA, colsB);
        freeMatrix(productMatrix, rowsA);
    } else {
        printf("Matrices cannot be multiplied (incompatible dimensions).\n");
    }
    
    // Freeing allocated memory
    freeMatrix(matrixA, rowsA);
    freeMatrix(matrixB, rowsB);
    
    return 0;
}