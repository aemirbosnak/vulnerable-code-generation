//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Let's perform some matrix operations!\n");

    // Input dimensions for first matrix
    printf("Enter rows and columns for Matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    // Input first matrix
    printf("Enter elements of Matrix 1:\n");
    inputMatrix(mat1, rows1, cols1);
    
    // Input dimensions for second matrix
    printf("Enter rows and columns for Matrix 2: ");
    scanf("%d %d", &rows2, &cols2);
    
    // Check compatibility for operations
    if (rows1 != rows2 || cols1 != cols2) {
        printf("For addition and subtraction, matrices must have the same dimensions.\n");
    }

    // Input second matrix
    printf("Enter elements of Matrix 2:\n");
    inputMatrix(mat2, rows2, cols2);

    // Matrix addition
    if (rows1 == rows2 && cols1 == cols2) {
        addMatrices(mat1, mat2, result, rows1, cols1);
        printf("Result of Matrix Addition:\n");
        printMatrix(result, rows1, cols1);
    }

    // Matrix subtraction
    if (rows1 == rows2 && cols1 == cols2) {
        subtractMatrices(mat1, mat2, result, rows1, cols1);
        printf("Result of Matrix Subtraction:\n");
        printMatrix(result, rows1, cols1);
    }

    // Matrix multiplication
    if (cols1 == rows2) {
        multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
        printf("Result of Matrix Multiplication:\n");
        printMatrix(result, rows1, cols2);
    } else {
        printf("Matrices are not compatible for multiplication.\n");
    }

    // Matrix transpose
    transposeMatrix(mat1, result, rows1, cols1);
    printf("Transpose of Matrix 1:\n");
    printMatrix(result, cols1, rows1);

    transposeMatrix(mat2, result, rows2, cols2);
    printf("Transpose of Matrix 2:\n");
    printMatrix(result, cols2, rows2);

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}