//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function to display the matrix
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                 int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                      int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function to multiply two matrices
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

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], 
                     int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

// Main function to demonstrate matrix operations
int main() {
    int matA[MAX_SIZE][MAX_SIZE], matB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE], transposed[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matA[i][j]);
        }
    }

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matB[i][j]);
        }
    }

    printf("\nMatrix A:\n");
    displayMatrix(matA, rowsA, colsA);

    printf("\nMatrix B:\n");
    displayMatrix(matB, rowsB, colsB);

    printf("\nAddition of Matrix A and B:\n");
    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(matA, matB, result, rowsA, colsA);
        displayMatrix(result, rowsA, colsA);
    } else {
        printf("Matrix addition requires same dimensions.\n");
    }

    printf("\nSubtraction of Matrix A and B:\n");
    if (rowsA == rowsB && colsA == colsB) {
        subtractMatrices(matA, matB, result, rowsA, colsA);
        displayMatrix(result, rowsA, colsA);
    } else {
        printf("Matrix subtraction requires same dimensions.\n");
    }

    printf("\nMultiplication of Matrix A and B:\n");
    if (colsA == rowsB) {
        multiplyMatrices(matA, matB, result, rowsA, colsA, colsB);
        displayMatrix(result, rowsA, colsB);
    } else {
        printf("Matrix multiplication requires specific dimensions.\n");
    }

    printf("\nTranspose of Matrix A:\n");
    transposeMatrix(matA, transposed, rowsA, colsA);
    displayMatrix(transposed, colsA, rowsA);
    
    return 0;
}