//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2);

int main() {
    int rows1, cols1, rows2, cols2;
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    // Input dimensions for the first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    
    // Input dimensions for the second matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Check compatibility for addition, subtraction and multiplication
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices are not compatible for addition or subtraction!\n");
        return 1;
    }

    if (cols1 != rows2) {
        printf("Matrices are not compatible for multiplication!\n");
        return 1;
    }

    // Input matrices
    printf("Enter elements of the first matrix:\n");
    inputMatrix(mat1, rows1, cols1);
    printf("Enter elements of the second matrix:\n");
    inputMatrix(mat2, rows2, cols2);

    // Print matrices
    printf("Matrix 1:\n");
    printMatrix(mat1, rows1, cols1);
    printf("Matrix 2:\n");
    printMatrix(mat2, rows2, cols2);

    // Addition
    addMatrices(mat1, mat2, result, rows1, cols1);
    printf("Result of Addition:\n");
    printMatrix(result, rows1, cols1);

    // Subtraction
    subtractMatrices(mat1, mat2, result, rows1, cols1);
    printf("Result of Subtraction:\n");
    printMatrix(result, rows1, cols1);

    // Multiplication
    multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
    printf("Result of Multiplication:\n");
    printMatrix(result, rows1, cols2);

    return 0;
}

// Function to input matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
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

// Function to subtract two matrices
void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize result matrix element
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}