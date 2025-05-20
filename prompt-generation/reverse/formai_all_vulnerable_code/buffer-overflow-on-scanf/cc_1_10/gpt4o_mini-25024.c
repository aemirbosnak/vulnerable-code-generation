//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void printMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int r2, int c2);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void getMatrix(int matrix[MAX][MAX], int rows, int cols);

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;
    
    printf("Welcome to the Matrix Magic Show!\n");
    
    // Input Matrix A
    printf("\nEnter the dimensions of Matrix A (rows columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter the elements of Matrix A:\n");
    getMatrix(A, rowsA, colsA);
    
    // Input Matrix B
    printf("\nEnter the dimensions of Matrix B (rows columns): ");
    scanf("%d %d", &rowsB, &colsB);
    printf("Enter the elements of Matrix B:\n");
    getMatrix(B, rowsB, colsB);
    
    // Show A and B
    printf("\nMatrix A:\n");
    printMatrix(A, rowsA, colsA);
    
    printf("\nMatrix B:\n");
    printMatrix(B, rowsB, colsB);
    
    // Add Matrices if possible
    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(A, B, result, rowsA, colsA);
        printf("\nMatrix A + Matrix B:\n");
        printMatrix(result, rowsA, colsA);
    } else {
        printf("\nAddition not possible: Matrix dimensions must match!\n");
    }
    
    // Multiply Matrices if possible
    if (colsA == rowsB) {
        multiplyMatrices(A, B, result, rowsA, colsA, rowsB, colsB);
        printf("\nMatrix A * Matrix B:\n");
        printMatrix(result, rowsA, colsB);
    } else {
        printf("\nMultiplication not possible: Number of columns in A must equal number of rows in B!\n");
    }
    
    // Transpose Matrix A
    transposeMatrix(A, result, rowsA, colsA);
    printf("\nTranspose of Matrix A:\n");
    printMatrix(result, colsA, rowsA);
    
    // Transpose Matrix B
    transposeMatrix(B, result, rowsB, colsB);
    printf("\nTranspose of Matrix B:\n");
    printMatrix(result, colsB, rowsB);
    
    printf("\nThanks for watching the Matrix Magic Show!\n");
    return 0;
}

void getMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}