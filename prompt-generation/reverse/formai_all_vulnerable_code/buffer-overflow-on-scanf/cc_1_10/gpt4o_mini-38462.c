//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes for matrix operations
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int firstMatrix[MAX_SIZE][MAX_SIZE], secondMatrix[MAX_SIZE][MAX_SIZE], resultMatrix[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    // Input dimensions for the first matrix
    printf("Enter the number of rows for the first matrix: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns for the first matrix: ");
    scanf("%d", &cols1);

    // Input the first matrix
    printf("Enter the elements of the first matrix:\n");
    inputMatrix(firstMatrix, rows1, cols1);
    printMatrix(firstMatrix, rows1, cols1);

    // Input dimensions for the second matrix
    printf("Enter the number of rows for the second matrix: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns for the second matrix: ");
    scanf("%d", &cols2);

    // Check if matrices can be added
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Error: Matrices dimensions do not match for addition.\n");
        return -1;
    }

    // Input the second matrix
    printf("Enter the elements of the second matrix:\n");
    inputMatrix(secondMatrix, rows2, cols2);
    printMatrix(secondMatrix, rows2, cols2);

    // Adding matrices
    addMatrices(firstMatrix, secondMatrix, resultMatrix, rows1, cols1);
    printf("Result of addition:\n");
    printMatrix(resultMatrix, rows1, cols1);

    // Check if matrices can be multiplied
    if (cols1 != rows2) {
        printf("Error: Matrices dimensions do not match for multiplication.\n");
        return -1;
    }

    // Multiplying matrices
    multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, rows1, cols1, cols2);
    printf("Result of multiplication:\n");
    printMatrix(resultMatrix, rows1, cols2);

    // Transposing the first matrix
    transposeMatrix(firstMatrix, resultMatrix, rows1, cols1);
    printf("Transpose of the first matrix:\n");
    printMatrix(resultMatrix, cols1, rows1);

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("[\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("  %d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("]\n");
}

void addMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void multiplyMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += first[i][k] * second[k][j];
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