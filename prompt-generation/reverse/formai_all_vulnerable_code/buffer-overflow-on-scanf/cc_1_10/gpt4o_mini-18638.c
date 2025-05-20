//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function to create (initialize) a matrix
void createMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter the elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

// Main function
int main() {
    // Prepare the matrix variables
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE], transposed[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    // Prompt user for the first matrix
    printf("Matrix 1:\n");
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows1, &cols1);
    createMatrix(matrix1, rows1, cols1);
    displayMatrix(matrix1, rows1, cols1);

    // Prompt user for the second matrix
    printf("Matrix 2:\n");
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows2, &cols2);
    
    // Ensure compatibility for addition and multiplication
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Warning: Add or subtract matrices of different dimensions!\n");
    }

    createMatrix(matrix2, rows2, cols2);
    displayMatrix(matrix2, rows2, cols2);

    // Addition of matrices
    if (rows1 == rows2 && cols1 == cols2) {
        addMatrices(matrix1, matrix2, result, rows1, cols1);
        printf("Result of Addition:\n");
        displayMatrix(result, rows1, cols1);
    }

    // Multiplication of matrices
    if (cols1 == rows2) {
        multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
        printf("Result of Multiplication:\n");
        displayMatrix(result, rows1, cols2);
    } else {
        printf("Warning: Cannot multiply these matrices! Incompatible dimensions.\n");
    }

    // Transposing the first matrix
    transposeMatrix(matrix1, transposed, rows1, cols1);
    printf("Transposed Matrix 1:\n");
    displayMatrix(transposed, cols1, rows1);

    // Transposing the second matrix
    transposeMatrix(matrix2, transposed, rows2, cols2);
    printf("Transposed Matrix 2:\n");
    displayMatrix(transposed, cols2, rows2);

    return 0;
}