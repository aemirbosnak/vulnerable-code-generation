//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void inputMatrix(int mat[MAX][MAX], int row, int col);
void printMatrix(int mat[MAX][MAX], int row, int col);
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int row, int col);
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int row1, int col1, int col2);
void transposeMatrix(int mat[MAX][MAX], int res[MAX][MAX], int row, int col);

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], res[MAX][MAX];
    int row1, col1, row2, col2;
    
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &row1, &col1);
    inputMatrix(mat1, row1, col1);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &row2, &col2);
    inputMatrix(mat2, row2, col2);

    // Addition
    if (row1 == row2 && col1 == col2) {
        printf("\nSum of the two matrices:\n");
        addMatrices(mat1, mat2, res, row1, col1);
        printMatrix(res, row1, col1);
    } else {
        printf("\nMatrices cannot be added due to dimension mismatch!\n");
    }

    // Multiplication
    if (col1 == row2) {
        printf("\nProduct of the two matrices:\n");
        multiplyMatrices(mat1, mat2, res, row1, col1, col2);
        printMatrix(res, row1, col2);
    } else {
        printf("\nMatrices cannot be multiplied due to dimension mismatch!\n");
    }

    // Transpose of First Matrix
    printf("\nTranspose of the first matrix:\n");
    transposeMatrix(mat1, res, row1, col1);
    printMatrix(res, col1, row1);
    
    return 0;
}

void inputMatrix(int mat[MAX][MAX], int row, int col) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int mat[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[MAX][MAX], int res[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[j][i] = mat[i][j];
        }
    }
}