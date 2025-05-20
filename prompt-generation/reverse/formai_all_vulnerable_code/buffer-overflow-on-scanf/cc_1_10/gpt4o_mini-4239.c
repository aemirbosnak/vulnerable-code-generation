//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 50 // Maximum size of the matrix

// Function prototypes
void displayMatrix(int matrix[MAX][MAX], int row, int col);
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int row, int col);
void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int row, int col);
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowA, int colA, int rowB, int colB);
void transposeMatrix(int a[MAX][MAX], int result[MAX][MAX], int row, int col);
void readMatrix(int matrix[MAX][MAX], int row, int col);

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int rowA, colA, rowB, colB;

    // First matrix dimensions
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowA, &colA);
    
    printf("\nEnter elements of the first matrix:\n");
    readMatrix(matrixA, rowA, colA);

    // Second matrix dimensions
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowB, &colB);
    
    if (rowA != rowB || colA != colB) {
        printf("Matrices must be of the same dimensions for addition and subtraction!\n");
        return 1;
    }

    printf("\nEnter elements of the second matrix:\n");
    readMatrix(matrixB, rowB, colB);

    // Resultant matrix for addition and subtraction
    printf("\nAddition of matrices:\n");
    addMatrices(matrixA, matrixB, result, rowA, colA);
    displayMatrix(result, rowA, colA);

    printf("\nSubtraction of matrices:\n");
    subtractMatrices(matrixA, matrixB, result, rowA, colA);
    displayMatrix(result, rowA, colA);
    
    // Multiplication of matrices if dimensions allow
    if (colA != rowB) {
        printf("Matrices cannot be multiplied due to dimension mismatch!\n");
    } else {
        printf("\nMultiplication of matrices:\n");
        multiplyMatrices(matrixA, matrixB, result, rowA, colA, rowB, colB);
        displayMatrix(result, rowA, colB);
    }

    // Transpose of the first matrix
    printf("\nTranspose of the first matrix:\n");
    transposeMatrix(matrixA, result, rowA, colA);
    displayMatrix(result, colA, rowA); // Swap rows and columns for display

    return 0;
}

// Function to read a matrix
void readMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowA, int colA, int rowB, int colB) {
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int a[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[j][i] = a[i][j];
        }
    }
}