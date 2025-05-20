//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void printMatrix(int rows, int cols, int matrix[rows][cols]);
void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]);
void subtractMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]);
void multiplyMatrices(int rows1, int cols1, int rows2, int cols2, int mat1[rows1][cols1], int mat2[rows2][cols2], int result[rows1][cols2]);

int main() {
    // Let's get the dimensions of the matrices
    int rows = 3, cols = 3;
    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

    printf("We're going to play with some matrices!\n");
    
    // Input for Matrix 1
    printf("Enter elements for Matrix 1 (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    // Input for Matrix 2
    printf("Enter elements for Matrix 2 (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Let's add the matrices!
    addMatrices(rows, cols, matrix1, matrix2, result);
    printf("\nMatrix Addition Result:\n");
    printMatrix(rows, cols, result);

    // Now, time for subtraction!
    subtractMatrices(rows, cols, matrix1, matrix2, result);
    printf("\nMatrix Subtraction Result:\n");
    printMatrix(rows, cols, result);

    // It's multiplication time!
    multiplyMatrices(rows, cols, rows, cols, matrix1, matrix2, result);
    printf("\nMatrix Multiplication Result:\n");
    printMatrix(rows, cols, result);

    printf("A fantastic time with matrices! 🎉\n");

    return 0;
}

// Function to print the matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add matrices
void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function for subtracting matrices
void subtractMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function for multiplying matrices
void multiplyMatrices(int rows1, int cols1, int rows2, int cols2, int mat1[rows1][cols1], int mat2[rows2][cols2], int result[rows1][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize result cell
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}