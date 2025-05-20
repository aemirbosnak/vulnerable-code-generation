//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter Matrix A (%d x %d):\n", rowsA, colsA);
    inputMatrix(A, rowsA, colsA);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    printf("Enter Matrix B (%d x %d):\n", rowsB, colsB);
    inputMatrix(B, rowsB, colsB);

    if (rowsA == rowsB && colsA == colsB) {
        printf("Matrix A + Matrix B:\n");
        addMatrices(A, B, result, rowsA, colsA);
        displayMatrix(result, rowsA, colsA);

        printf("Matrix A - Matrix B:\n");
        subtractMatrices(A, B, result, rowsA, colsA);
        displayMatrix(result, rowsA, colsA);
    } else {
        printf("Addition and subtraction are not possible due to incompatible dimensions.\n");
    }

    if (colsA == rowsB) {
        printf("Matrix A * Matrix B:\n");
        multiplyMatrices(A, B, result, rowsA, colsA, rowsB, colsB);
        displayMatrix(result, rowsA, colsB);
    } else {
        printf("Multiplication is not possible due to incompatible dimensions.\n");
    }

    printf("Transpose of Matrix A:\n");
    transposeMatrix(A, result, rowsA, colsA);
    displayMatrix(result, colsA, rowsA);

    printf("Transpose of Matrix B:\n");
    transposeMatrix(B, result, rowsB, colsB);
    displayMatrix(result, colsB, rowsB);

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}