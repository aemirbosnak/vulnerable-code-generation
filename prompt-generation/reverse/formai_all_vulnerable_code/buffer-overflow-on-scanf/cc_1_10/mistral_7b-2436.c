//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>

#define ROWS 3
#define COLS 3

void multiply(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[ROWS][COLS], mat2[ROWS][COLS], result[ROWS][COLS];

    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    multiply(mat1, mat2, result);

    printf("Matrix 1:\n");
    printMatrix(mat1);

    printf("Matrix 2:\n");
    printMatrix(mat2);

    printf("Result of multiplication:\n");
    printMatrix(result);

    return 0;
}