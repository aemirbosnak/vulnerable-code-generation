//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void initializeMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter elements for the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("\nHere is your matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    printf("Welcome to the Dazzling Matrix Operations Program!\n");
    printf("Let's start with Matrix A. How exciting!\n");
    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    initializeMatrix(matrixA, rowsA, colsA);
    printMatrix(matrixA, rowsA, colsA);

    printf("Yay! Now it's time for Matrix B!\n");
    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    
    // For addition and subtraction, matrices must have the same dimensions
    if(rowsA == rowsB && colsA == colsB) {
        initializeMatrix(matrixB, rowsB, colsB);
        printMatrix(matrixB, rowsB, colsB);

        printf("\nLet's add the joyful matrices!\n");
        addMatrices(matrixA, matrixB, result, rowsA, colsA);
        printMatrix(result, rowsA, colsA);
        
        printf("\nNow, subtracting them for more fun!\n");
        subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
        printMatrix(result, rowsA, colsA);
    } else {
        printf("Oh no! The dimensions don't match for addition/subtraction. Let's skip to multiplication!\n");
    }

    printf("\nMultiplication time! Let's take Matrix A (%d x %d) and Matrix B (%d x %d)\n", rowsA, colsA, rowsB, colsB);
    if (colsA == rowsB) {
        multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
        printf("The result of multiplying Matrix A with Matrix B is:\n");
        printMatrix(result, rowsA, colsB);
    } else {
        printf("Oops! The number of columns in Matrix A must match the number of rows in Matrix B for multiplication.\n");
    }

    printf("Thank you for playing with matrices today! Have a fantastic day ahead!\n");

    return 0;
}