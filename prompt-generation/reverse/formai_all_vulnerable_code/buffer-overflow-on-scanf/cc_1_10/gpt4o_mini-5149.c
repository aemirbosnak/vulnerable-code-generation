//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2);

int main() {
    int rows1, cols1, rows2, cols2;
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    // Input first matrix dimensions and elements
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter elements of the first matrix:\n");
    inputMatrix(mat1, rows1, cols1);

    // Input second matrix dimensions and elements
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    printf("Enter elements of the second matrix:\n");
    inputMatrix(mat2, rows2, cols2);

    // Matrix addition
    if (rows1 == rows2 && cols1 == cols2) {
        addMatrices(mat1, mat2, result, rows1, cols1);
        printf("Result of Addition:\n");
        displayMatrix(result, rows1, cols1);
    } else {
        printf("Matrices cannot be added due to dimension mismatch.\n");
    }

    // Matrix subtraction
    if (rows1 == rows2 && cols1 == cols2) {
        subtractMatrices(mat1, mat2, result, rows1, cols1);
        printf("Result of Subtraction:\n");
        displayMatrix(result, rows1, cols1);
    } else {
        printf("Matrices cannot be subtracted due to dimension mismatch.\n");
    }

    // Matrix multiplication
    if (cols1 == rows2) {
        multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
        printf("Result of Multiplication:\n");
        displayMatrix(result, rows1, cols2);
    } else {
        printf("Matrices cannot be multiplied due to dimension mismatch.\n");
    }

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
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

void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}