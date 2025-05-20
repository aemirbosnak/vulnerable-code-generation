//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0; // Initializing the element
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j]; // The calculation
            }
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];

    printf("Surprise! Let's perform some matrix operations.\n");

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    if (colsA != rowsB) {
        printf("Oops! The number of columns in Matrix A must equal the number of rows in Matrix B for multiplication.\n");
        return 1;
    }

    printf("Fill Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("Enter element A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Fill Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("Enter element B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    printf("\nYour Matrix A is:\n");
    printMatrix(A, rowsA, colsA);

    printf("\nYour Matrix B is:\n");
    printMatrix(B, rowsB, colsB);

    // Addition (only if sizes match)
    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(A, B, C, rowsA, colsA);
        printf("\nSurprise! The sum of Matrix A and B is:\n");
        printMatrix(C, rowsA, colsA);
    } else {
        printf("\nAddition not possible; dimensions do not match!\n");
    }

    // Subtraction (only if sizes match)
    if (rowsA == rowsB && colsA == colsB) {
        subtractMatrices(A, B, C, rowsA, colsA);
        printf("\nSurprise! The difference (A - B) is:\n");
        printMatrix(C, rowsA, colsA);
    } else {
        printf("\nSubtraction not possible; dimensions do not match!\n");
    }

    // Multiplication
    multiplyMatrices(A, B, C, rowsA, colsA, colsB);
    printf("\nSurprise! The product of Matrix A and B is:\n");
    printMatrix(C, rowsA, colsB);

    return 0;
}