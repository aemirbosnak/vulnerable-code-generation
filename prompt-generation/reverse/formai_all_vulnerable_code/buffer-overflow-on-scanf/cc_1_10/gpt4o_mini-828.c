//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE];
    int sum[MAX_SIZE][MAX_SIZE], product[MAX_SIZE][MAX_SIZE], transposed[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Enter the dimensions of the first matrix (rows and columns): ");
    scanf("%d %d", &rows1, &cols1);
    inputMatrix(mat1, rows1, cols1);

    printf("Enter the dimensions of the second matrix (rows and columns): ");
    scanf("%d %d", &rows2, &cols2);
    inputMatrix(mat2, rows2, cols2);

    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrix addition requires matrices of the same dimensions.\n");
        exit(1);
    }
    
    addMatrices(mat1, mat2, sum, rows1, cols1);
    printf("\nSum of matrices:\n");
    printMatrix(sum, rows1, cols1);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible due to incompatible dimensions.\n");
    } else {
        multiplyMatrices(mat1, mat2, product, rows1, cols1, cols2);
        printf("\nProduct of matrices:\n");
        printMatrix(product, rows1, cols2);
    }

    transposeMatrix(mat1, transposed, rows1, cols1);
    printf("\nTranspose of first matrix:\n");
    printMatrix(transposed, cols1, rows1);

    return 0;
}