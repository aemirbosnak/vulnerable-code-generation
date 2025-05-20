//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct {
    int data[SIZE][SIZE];
} Matrix;

Matrix createIdentityMatrix() {
    Matrix matrix;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (i == j)
                matrix.data[i][j] = 1;
            else
                matrix.data[i][j] = 0;
        }
    }

    return matrix;
}

void printMatrix(Matrix matrix) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%3d ", matrix.data[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(Matrix a, Matrix b, Matrix result) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < SIZE; ++k)
                result.data[i][j] += a.data[i][k] * b.data[k][j];
        }
    }
}

Matrix fibonacciMatrix(int n) {
    if (n <= 0)
        return (Matrix){};

    if (n == 1)
        return createIdentityMatrix();

    Matrix a = fibonacciMatrix(n - 1);
    Matrix b = fibonacciMatrix(n - 2);
    Matrix result;

    multiplyMatrices(a, a, result);
    multiplyMatrices(result, b, result);

    return result;
}

int main() {
    int n;

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    Matrix fibonacci = fibonacciMatrix(n);

    printf("\nFibonacci numbers:\n");
    printMatrix(fibonacci);

    return 0;
}