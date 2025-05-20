//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef struct Matrix {
    int data[SIZE][SIZE];
} Matrix;

Matrix createMatrix(int rows, int cols) {
    Matrix matrix;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix.data[i][j] = 0;
        }
    }
    return matrix;
}

void printMatrix(Matrix matrix) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", matrix.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Matrix transpose(Matrix matrix) {
    Matrix transposed;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            transposed.data[j][i] = matrix.data[i][j];
        }
    }
    return transposed;
}

Matrix multiplyMatrices(Matrix matrix1, Matrix matrix2) {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result.data[i][j] += matrix1.data[i][k] * matrix2.data[k][j];
            }
        }
    }
    return result;
}

int main() {
    Matrix A = createMatrix(SIZE, SIZE);
    Matrix B = createMatrix(SIZE, SIZE);
    Matrix C = createMatrix(SIZE, SIZE);

    printf("Enter elements of first matrix A:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &A.data[i][j]);
        }
    }

    printf("Enter elements of second matrix B:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &B.data[i][j]);
        }
    }

    printMatrix(A);
    printf("Matrix A:\n");
    printMatrix(B);
    printf("Matrix B:\n");

    C = multiplyMatrices(A, B);
    printf("Result of matrix multiplication (C = A * B):\n");
    printMatrix(C);

    printf("Transpose of Matrix A:\n");
    Matrix AT = transpose(A);
    printMatrix(AT);

    return 0;
}