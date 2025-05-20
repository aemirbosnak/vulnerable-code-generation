//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("\nHere is the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
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

int determinant(int matrix[MAX][MAX], int n) {
    int det = 0;
    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    } else {
        for (int x = 0; x < n; x++) {
            int temp[MAX][MAX];
            for (int i = 1; i < n; i++) {
                int j = 0;
                for (int j1 = 0; j1 < n; j1++) {
                    if (j1 == x) continue;
                    temp[i-1][j++] = matrix[i][j1];
                }
            }
            det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(temp, n - 1);
        }
    }
    return det;
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int rows, cols;

    printf("Let's perform some matrix operations!\n");
    
    printf("Enter the number of rows for square matrices (max %d): ", MAX);
    scanf("%d", &rows);
    printf("Enter the number of columns for square matrices (max %d): ", MAX);
    scanf("%d", &cols);

    if (rows > MAX || cols > MAX) {
        printf("Matrix size should not exceed %d.\n", MAX);
        return 1;
    }

    inputMatrix(A, rows, cols);
    inputMatrix(B, rows, cols);

    addMatrices(A, B, C, rows, cols);
    printf("\nAddition of matrices:\n");
    displayMatrix(C, rows, cols);

    subtractMatrices(A, B, C, rows, cols);
    printf("\nSubtraction of matrices:\n");
    displayMatrix(C, rows, cols);

    multiplyMatrices(A, B, C, rows, cols, cols);
    printf("\nMultiplication of matrices:\n");
    displayMatrix(C, rows, cols);

    int transposed[MAX][MAX];
    transposeMatrix(A, transposed, rows, cols);
    printf("\nTranspose of the first matrix:\n");
    displayMatrix(transposed, cols, rows);

    int detA = determinant(A, rows);
    printf("\nDeterminant of the first matrix: %d\n", detA);

    return 0;
}