//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize result element
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;
    
    printf("Matrix Operation Program (Addition and Multiplication)\n");

    // Input for first matrix
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    int mat1[MAX][MAX];
    inputMatrix(mat1, rows1, cols1);
    displayMatrix(mat1, rows1, cols1);

    // Input for second matrix
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    int mat2[MAX][MAX];
    inputMatrix(mat2, rows2, cols2);
    displayMatrix(mat2, rows2, cols2);

    // Addition of matrices
    if (rows1 == rows2 && cols1 == cols2) {
        int sum[MAX][MAX];
        addMatrices(mat1, mat2, sum, rows1, cols1);
        printf("\nResult of Addition:\n");
        displayMatrix(sum, rows1, cols1);
    } else {
        printf("Matrices cannot be added. Dimensions do not match.\n");
    }

    // Multiplication of matrices
    if (cols1 == rows2) {
        int product[MAX][MAX];
        multiplyMatrices(mat1, mat2, product, rows1, cols1, cols2);
        printf("\nResult of Multiplication:\n");
        displayMatrix(product, rows1, cols2);
    } else {
        printf("Matrices cannot be multiplied. The number of columns of the first matrix must equal the number of rows of the second matrix.\n");
    }

    return 0;
}