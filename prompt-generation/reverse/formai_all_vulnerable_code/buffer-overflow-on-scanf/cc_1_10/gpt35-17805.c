//FormAI DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void printMatrix(int mat[][COLS], int rows, int cols);
void addMatrix(int mat1[][COLS], int mat2[][COLS], int result[][COLS], int rows, int cols);
void multiplyMatrix(int mat1[][COLS], int mat2[][COLS], int result[][COLS], int rows, int cols);

int main() {
    int mat1[ROWS][COLS], mat2[ROWS][COLS], sum[ROWS][COLS], product[ROWS][COLS];

    printf("Enter values for matrix 1:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("Enter value for mat1[%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("\nEnter values for matrix 2:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("Enter value for mat2[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("\nMatrix 1:\n");
    printMatrix(mat1, ROWS, COLS);

    printf("\nMatrix 2:\n");
    printMatrix(mat2, ROWS, COLS);

    // Add the matrices
    addMatrix(mat1, mat2, sum, ROWS, COLS);

    printf("\nSum of matrices:\n");
    printMatrix(sum, ROWS, COLS);

    // Multiply the matrices
    multiplyMatrix(mat1, mat2, product, ROWS, COLS);

    printf("\nProduct of matrices:\n");
    printMatrix(product, ROWS, COLS);

    return 0;
}

void printMatrix(int mat[][COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int mat1[][COLS], int mat2[][COLS], int result[][COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiplyMatrix(int mat1[][COLS], int mat2[][COLS], int result[][COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i][j] = 0;

            for(int k=0; k<cols; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}