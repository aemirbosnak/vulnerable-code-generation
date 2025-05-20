//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    printf("Matrix A - Enter number of rows and columns: ");
    scanf("%d %d", &rowsA, &colsA);
    inputMatrix(matrixA, rowsA, colsA);

    printf("Matrix B - Enter number of rows and columns: ");
    scanf("%d %d", &rowsB, &colsB);
    inputMatrix(matrixB, rowsB, colsB);

    if (rowsA == rowsB && colsA == colsB) {
        printf("Matrix A + Matrix B:\n");
        addMatrices(matrixA, matrixB, result, rowsA, colsA);
        printMatrix(result, rowsA, colsA);

        printf("Matrix A - Matrix B:\n");
        subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
        printMatrix(result, rowsA, colsA);
    } else {
        printf("Addition and subtraction operations require matrices of the same dimensions.\n");
    }

    if (colsA == rowsB) {
        printf("Matrix A x Matrix B:\n");
        multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
        printMatrix(result, rowsA, colsB);
    } else {
        printf("Multiplication operation requires that the number of columns of Matrix A "
               "equals the number of rows of Matrix B.\n");
    }

    return 0;
}