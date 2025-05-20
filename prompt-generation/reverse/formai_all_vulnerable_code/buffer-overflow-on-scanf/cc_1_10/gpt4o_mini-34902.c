//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("\nMatrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    printf("Welcome to the Retro Matrix Operations Program!\n");
    
    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    
    printf("Enter the elements of Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrix addition/subtraction requires both matrices to have the same dimensions.\n");
        return 1;
    }

    printf("Enter the elements of Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    // Addition
    addMatrices(a, b, result, rowsA, colsA);
    displayMatrix(result, rowsA, colsA);

    // Subtraction
    subtractMatrices(a, b, result, rowsA, colsA);
    displayMatrix(result, rowsA, colsA);

    // Multiplication requires specific dimensions
    if (colsA != rowsB) {
        printf("Matrix multiplication requires the number of columns in A to equal the number of rows in B.\n");
        return 1;
    }

    printf("Matrix A multiplied by Matrix B:\n");
    multiplyMatrices(a, b, result, rowsA, colsA, colsB);
    displayMatrix(result, rowsA, colsB);

    printf("Thank you for using the Retro Matrix Operations Program! Goodbye!\n");
    return 0;
}