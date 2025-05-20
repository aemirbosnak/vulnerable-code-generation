//FormAI DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to initialize a matrix with random values
void initMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
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
void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Error: Incompatible matrices");
        return;
    }
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;
    
    printf("Enter the dimensions of matrix 1 (row col): ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the dimensions of matrix 2 (row col): ");
    scanf("%d %d", &rows2, &cols2);
    
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Error: Matrices must have the same dimensions");
        return -1;
    }
    
    initMatrix(matrix1, rows1, cols1);
    printf("Matrix 1:\n");
    printMatrix(matrix1, rows1, cols1);
    
    initMatrix(matrix2, rows2, cols2);
    printf("Matrix 2:\n");
    printMatrix(matrix2, rows2, cols2);
    
    printf("Adding the matrices...\n");
    addMatrices(matrix1, matrix2, result, rows1, cols1);
    printf("Result:\n");
    printMatrix(result, rows1, cols1);
    
    printf("Multiplying the matrices...\n");
    multiplyMatrices(matrix1, matrix2, result, rows1, cols1, rows2, cols2);
    printf("Result:\n");
    printMatrix(result, rows1, cols2);
    
    return 0;
}