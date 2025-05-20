//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int r, int c) {
    if (r >= rows) return;
    if (c >= cols) {
        inputMatrix(matrix, rows, cols, r + 1, 0);
        return;
    }
    printf("Enter element [%d][%d]: ", r, c);
    scanf("%d", &matrix[r][c]);
    inputMatrix(matrix, rows, cols, r, c + 1);
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int r, int c) {
    if (r >= rows) return;
    if (c >= cols) {
        printf("\n");
        printMatrix(matrix, rows, cols, r + 1, 0);
        return;
    }
    printf("%d ", matrix[r][c]);
    printMatrix(matrix, rows, cols, r, c + 1);
}

void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols, int r, int c) {
    if (r >= rows) return;
    if (c >= cols) {
        addMatrices(A, B, C, rows, cols, r + 1, 0);
        return;
    }
    C[r][c] = A[r][c] + B[r][c];
    addMatrices(A, B, C, rows, cols, r, c + 1);
}

void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rA, int cA, int cB, int r, int c) {
    if (r >= rA) return;
    if (c >= cB) {
        multiplyMatrices(A, B, C, rA, cA, cB, r + 1, 0);
        return;
    }
    int sum = 0;
    for (int k = 0; k < cA; k++) {
        sum += A[r][k] * B[k][c];
    }
    C[r][c] = sum;
    multiplyMatrices(A, B, C, rA, cA, cB, r, c + 1);
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols, int r, int c) {
    if (r >= rows) return;
    if (c >= cols) {
        transposeMatrix(matrix, transposed, rows, cols, r + 1, 0);
        return;
    }
    transposed[c][r] = matrix[r][c];
    transposeMatrix(matrix, transposed, rows, cols, r, c + 1);
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    printf("Enter dimensions for Matrix A (rows columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Input Matrix A:\n");
    inputMatrix(A, rowsA, colsA, 0, 0);
    
    printf("Enter dimensions for Matrix B (rows columns): ");
    scanf("%d %d", &rowsB, &colsB);
    printf("Input Matrix B:\n");
    inputMatrix(B, rowsB, colsB, 0, 0);

    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrices A and B should be of the same dimensions for addition.\n");
    } else {
        printf("Result of A + B:\n");
        addMatrices(A, B, C, rowsA, colsA, 0, 0);
        printMatrix(C, rowsA, colsA, 0, 0);
    }

    if (colsA != rowsB) {
        printf("Matrix multiplication not possible: columns of A must equal rows of B.\n");
    } else {
        printf("Result of A * B:\n");
        multiplyMatrices(A, B, C, rowsA, colsA, colsB, 0, 0);
        printMatrix(C, rowsA, colsB, 0, 0);
    }

    printf("Transpose of Matrix A:\n");
    transposeMatrix(A, transposed, rowsA, colsA, 0, 0);
    printMatrix(transposed, colsA, rowsA, 0, 0);

    return 0;
}