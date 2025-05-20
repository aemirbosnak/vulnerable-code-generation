//FormAI DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include <stdio.h>

#define N 3

void matrixMultiplication(int mat1[][N], int mat2[][N], int res[][N]) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = 0;
            for (int k = 0; k < N; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(int matrix[][N]) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    
    int matrix1[N][N];
    int matrix2[N][N];
    int result[N][N];

    printf("Enter the elements of the first matrix:\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    matrixMultiplication(matrix1, matrix2, result);

    printf("Matrix1:\n");
    printMatrix(matrix1);

    printf("Matrix2:\n");
    printMatrix(matrix2);

    printf("Resultant Matrix:\n");
    printMatrix(result);

    return 0;
}