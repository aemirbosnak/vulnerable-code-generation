//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function to input a matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
int multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    if (cols1 != rows1) {
        return 0; // Incompatible dimensions
    }
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize the result matrix
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return 1;
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE], transposed[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    // Input for first matrix
    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    inputMatrix(matrix1, rows1, cols1);
    printMatrix(matrix1, rows1, cols1);

    // Input for second matrix
    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    inputMatrix(matrix2, rows2, cols2);
    printMatrix(matrix2, rows2, cols2);

    // Addition of matrices
    if (rows1 == rows2 && cols1 == cols2) {
        int addResult[MAX_SIZE][MAX_SIZE];
        addMatrices(matrix1, matrix2, addResult, rows1, cols1);
        printMatrix(addResult, rows1, cols1);
    } else {
        printf("Matrix addition cannot be performed due to incompatible dimensions.\n");
    }

    // Multiplication of matrices
    if (cols1 == rows2) {
        int mulResult[MAX_SIZE][MAX_SIZE];
        if (multiplyMatrices(matrix1, matrix2, mulResult, rows1, cols1, cols2)) {
            printMatrix(mulResult, rows1, cols2);
        } else {
            printf("Matrix multiplication cannot be performed due to incompatible dimensions.\n");
        }
    } else {
        printf("Matrix multiplication cannot be performed due to incompatible dimensions.\n");
    }

    // Transpose of the first matrix
    transposeMatrix(matrix1, transposed, rows1, cols1);
    printMatrix(transposed, cols1, rows1); // Transposed dimensions are swapped

    return 0;
}