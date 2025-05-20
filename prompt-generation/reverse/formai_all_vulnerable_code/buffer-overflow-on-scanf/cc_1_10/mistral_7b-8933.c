//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef struct Matrix {
    int data[SIZE][SIZE];
} Matrix;

Matrix addMatrices(Matrix a, Matrix b) {
    Matrix result;
    int i, j;

    result.data[0][0] = a.data[0][0] + b.data[0][0];
    result.data[0][1] = a.data[0][1] + b.data[0][1];
    result.data[0][2] = a.data[0][2] + b.data[0][2];
    result.data[1][0] = a.data[1][0] + b.data[1][0];
    result.data[1][1] = a.data[1][1] + b.data[1][1];
    result.data[1][2] = a.data[1][2] + b.data[1][2];
    result.data[2][0] = a.data[2][0] + b.data[2][0];
    result.data[2][1] = a.data[2][1] + b.data[2][1];
    result.data[2][2] = a.data[2][2] + b.data[2][2];

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", result.data[i][j]);
        }
        printf("\n");
    }

    return result;
}

int main() {
    Matrix matrixA, matrixB, result;

    printf("Enter elements of Matrix A:\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &matrixA.data[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &matrixB.data[i][j]);
        }
    }

    result = addMatrices(matrixA, matrixB);

    printf("Sum of Matrix A and Matrix B:\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", result.data[i][j]);
        }
        printf("\n");
    }

    return 0;
}