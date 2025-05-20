//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX]) {
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX]) {
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX]) {
    int i, j, k;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            result[i][j] = 0;
            for (k = 0; k < MAX; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void printMatrix(int matrix[MAX][MAX]) {
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];
    int i, j;

    // Input for matrix 1
    printf("Enter elements of matrix 1:\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input for matrix 2
    printf("Enter elements of matrix 2:\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Addition of matrices
    printf("Addition:\n");
    addMatrices(matrix1, matrix2, result);
    printMatrix(result);

    // Subtraction of matrices
    printf("\nSubtraction:\n");
    subtractMatrices(matrix1, matrix2, result);
    printMatrix(result);

    // Multiplication of matrices
    printf("\nMultiplication:\n");
    multiplyMatrices(matrix1, matrix2, result);
    printMatrix(result);

    return 0;
}