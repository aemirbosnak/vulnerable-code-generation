//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function Prototypes
void initializeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                 int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                      int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                      int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], 
                     int rows, int cols);

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Enter number of rows and columns for Matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    
    printf("Enter number of rows and columns for Matrix 2 (should be the same as Matrix 1): ");
    scanf("%d %d", &rows2, &cols2);

    // Check if dimensions of both matrices are equal
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Error: Matrices must be of the same dimensions for addition and subtraction.\n");
        return 1;
    }

    printf("Initializing Matrix 1:\n");
    initializeMatrix(matrix1, rows1, cols1);
    printMatrix(matrix1, rows1, cols1);

    printf("Initializing Matrix 2:\n");
    initializeMatrix(matrix2, rows2, cols2);
    printMatrix(matrix2, rows2, cols2);

    printf("Adding Matrices:\n");
    addMatrices(matrix1, matrix2, result, rows1, cols1);
    printMatrix(result, rows1, cols1);

    printf("Subtracting Matrices:\n");
    subtractMatrices(matrix1, matrix2, result, rows1, cols1);
    printMatrix(result, rows1, cols1);

    printf("Multiplying Matrices (Matrix 1 × Matrix 2):\n");
    if (cols1 != rows2) {
        printf("Error: Cannot multiply the matrices, incompatible dimensions.\n");
    } else {
        multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
        printMatrix(result, rows1, cols2);
    }

    printf("Transposing Matrix 1:\n");
    transposeMatrix(matrix1, result, rows1, cols1);
    printMatrix(result, cols1, rows1);

    return 0;
}

void initializeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
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

void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                 int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                      int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                      int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], 
                     int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}