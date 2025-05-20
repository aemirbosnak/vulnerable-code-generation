//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
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

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX], transposed[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    inputMatrix(matrixA, rowsA, colsA);

    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    inputMatrix(matrixB, rowsB, colsB);

    if (rowsA == rowsB && colsA == colsB) {
        printf("Matrix A:\n");
        displayMatrix(matrixA, rowsA, colsA);

        printf("Matrix B:\n");
        displayMatrix(matrixB, rowsB, colsB);

        addMatrices(matrixA, matrixB, result, rowsA, colsA);
        printf("Result of A + B:\n");
        displayMatrix(result, rowsA, colsA);

        subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
        printf("Result of A - B:\n");
        displayMatrix(result, rowsA, colsA);
    } else {
        printf("Matrix addition and subtraction not possible due to size mismatch.\n");
    }

    if (colsA == rowsB) {
        multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
        printf("Result of A * B:\n");
        displayMatrix(result, rowsA, colsB);
    } else {
        printf("Matrix multiplication not possible due to incompatible sizes.\n");
    }

    printf("Transposing Matrix A:\n");
    transposeMatrix(matrixA, transposed, rowsA, colsA);
    displayMatrix(transposed, colsA, rowsA);

    printf("Transposing Matrix B:\n");
    transposeMatrix(matrixB, transposed, rowsB, colsB);
    displayMatrix(transposed, colsB, rowsB);

    return 0;
}