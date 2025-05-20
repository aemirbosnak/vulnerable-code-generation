//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: curious
#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("\nThe matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
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

void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX][MAX], matrixB[MAX][MAX];
    
    printf("Enter the dimensions of the first matrix A:\n");
    printf("Rows: ");
    scanf("%d", &rowsA);
    printf("Columns: ");
    scanf("%d", &colsA);
    
    inputMatrix(matrixA, rowsA, colsA);
    displayMatrix(matrixA, rowsA, colsA);
    
    printf("Enter the dimensions of the second matrix B:\n");
    printf("Rows: ");
    scanf("%d", &rowsB);
    printf("Columns: ");
    scanf("%d", &colsB);
    
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrix addition and subtraction require same dimensions.\n");
        return 1;
    }
    
    inputMatrix(matrixB, rowsB, colsB);
    displayMatrix(matrixB, rowsB, colsB);
    
    int result[MAX][MAX];
    
    addMatrices(matrixA, matrixB, result, rowsA, colsA);
    printf("\nMatrix A + Matrix B:\n");
    displayMatrix(result, rowsA, colsA);
    
    subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
    printf("\nMatrix A - Matrix B:\n");
    displayMatrix(result, rowsA, colsA);
    
    if (colsA != rowsB) {
        printf("Matrix multiplication requires the number of columns of A to match the number of rows of B.\n");
    } else {
        int product[MAX][MAX];
        multiplyMatrices(matrixA, matrixB, product, rowsA, colsA, colsB);
        printf("\nMatrix A * Matrix B:\n");
        displayMatrix(product, rowsA, colsB);
    }

    int transposeA[MAX][MAX], transposeB[MAX][MAX];
    transposeMatrix(matrixA, transposeA, rowsA, colsA);
    printf("\nTranspose of Matrix A:\n");
    displayMatrix(transposeA, colsA, rowsA);
    
    transposeMatrix(matrixB, transposeB, rowsB, colsB);
    printf("\nTranspose of Matrix B:\n");
    displayMatrix(transposeB, colsB, rowsB);

    return 0;
}