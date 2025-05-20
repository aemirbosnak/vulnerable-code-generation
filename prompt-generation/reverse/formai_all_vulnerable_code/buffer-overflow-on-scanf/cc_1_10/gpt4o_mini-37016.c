//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function to initialize a matrix
void initializeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // Assign random values between 0 and 9
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
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
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize result cell
            for (int k = 0; k < cols1; k++) {
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
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    // Initialize random seed
    srand(time(NULL));

    // Input dimensions for the first matrix
    printf("Enter number of rows and columns for Matrix 1 (max %d): ", MAX_SIZE);
    scanf("%d %d", &rows1, &cols1);

    // Input dimensions for the second matrix
    printf("Enter number of rows and columns for Matrix 2 (max %d): ", MAX_SIZE);
    scanf("%d %d", &rows2, &cols2);

    // Check for matrix addition compatibility
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices cannot be added since dimensions do not match.\n");
        return 1;
    }

    // Check for matrix multiplication compatibility
    if (cols1 != rows2) {
        printf("Matrices cannot be multiplied since dimensions are not compatible.\n");
        return 1;
    }

    // Initialize matrices
    initializeMatrix(mat1, rows1, cols1);
    initializeMatrix(mat2, rows2, cols2);

    // Display original matrices
    displayMatrix(mat1, rows1, cols1);
    displayMatrix(mat2, rows2, cols2);

    // Add matrices
    addMatrices(mat1, mat2, result, rows1, cols1);
    printf("\nMatrix Addition Result:\n");
    displayMatrix(result, rows1, cols1);

    // Multiply matrices
    multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
    printf("\nMatrix Multiplication Result:\n");
    displayMatrix(result, rows1, cols2);

    // Transpose the first matrix
    transposeMatrix(mat1, transposed, rows1, cols1);
    printf("\nTransposed Matrix 1:\n");
    displayMatrix(transposed, cols1, rows1);

    return 0;
}