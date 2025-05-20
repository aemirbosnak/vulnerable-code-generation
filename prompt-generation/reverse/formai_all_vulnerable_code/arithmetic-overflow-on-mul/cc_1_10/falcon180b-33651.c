//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void initMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2, rows3, cols3;
    int i, j, k;

    // Initialize matrices with random values
    initMatrix(matrix1, 3, 3);
    initMatrix(matrix2, 3, 3);

    // Print matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, 3, 3);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2, 3, 3);

    // Check if matrices can be multiplied
    if(matrix1[0][0] == 0) {
        printf("Matrix 1 cannot be multiplied.\n");
        return 0;
    }

    // Get dimensions of matrices
    rows1 = sizeof(matrix1) / sizeof(matrix1[0]);
    cols1 = sizeof(matrix1[0]) / sizeof(matrix1[0][0]);
    rows2 = sizeof(matrix2) / sizeof(matrix2[0]);
    cols2 = sizeof(matrix2[0]) / sizeof(matrix2[0][0]);

    // Check if matrices can be multiplied
    if(cols1!= rows2) {
        printf("Matrices cannot be multiplied.\n");
        return 0;
    }

    // Multiply matrices
    for(i = 0; i < rows1; i++) {
        for(j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(k = 0; k < rows2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print result
    printf("\nResult:\n");
    printMatrix(result, rows1, cols2);

    return 0;
}