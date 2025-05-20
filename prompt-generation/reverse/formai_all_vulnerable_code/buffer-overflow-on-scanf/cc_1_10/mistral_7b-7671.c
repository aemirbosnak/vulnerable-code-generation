//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef struct Matrix {
    int data[SIZE][SIZE];
    int rows;
    int cols;
} Matrix;

void print_matrix(Matrix m) {
    int i, j;

    printf("\nMatrix A:\n");
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++)
            printf("%3d ", m.data[i][j]);
        printf("\n");
    }
}

Matrix multiply(Matrix a, Matrix b) {
    Matrix result;
    int i, j, k;

    if (a.cols != b.rows) {
        printf("Error! Matrices can't be multiplied.\n");
        exit(EXIT_FAILURE);
    }

    result.rows = a.rows;
    result.cols = b.cols;

    for (i = 0; i < result.rows; i++) {
        for (j = 0; j < result.cols; j++) {
            result.data[i][j] = 0;
            for (k = 0; k < a.cols; k++)
                result.data[i][j] += a.data[i][k] * b.data[k][j];
        }
    }

    return result;
}

int main() {
    Matrix A, B, C;
    int i, j;

    A.rows = A.cols = SIZE;
    B.rows = B.cols = SIZE;

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            scanf("%d", &A.data[i][j]);

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            scanf("%d", &B.data[i][j]);

    C = multiply(A, B);

    printf("\nMatrix A:\n");
    print_matrix(A);

    printf("\nMatrix B:\n");
    print_matrix(B);

    printf("\nProduct of Matrix A and Matrix B:\n");
    print_matrix(C);

    return 0;
}