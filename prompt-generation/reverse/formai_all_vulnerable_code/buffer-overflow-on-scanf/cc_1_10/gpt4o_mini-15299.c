//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Matrix (%dx%d):\n", rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int r1, int c1, int r2, int c2, int mat1[r1][c1], int mat2[r2][c2], int result[r1][c1]) {
    if (r1 != r2 || c1 != c2) {
        printf("Error: Matrices must be of the same dimensions for addition!\n");
        return;
    }
    
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c1; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int r1, int c1, int r2, int c2, int mat1[r1][c1], int mat2[r2][c2], int result[r1][c1]) {
    if (r1 != r2 || c1 != c2) {
        printf("Error: Matrices must be of the same dimensions for subtraction!\n");
        return;
    }
    
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c1; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int r1, int c1, int r2, int c2, int mat1[r1][c1], int mat2[r2][c2], int result[r1][c2]) {
    if (c1 != r2) {
        printf("Error: Invalid dimensions for multiplication!\n");
        return;
    }
    
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0; // Initialize to 0 for summation
            for(int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int r1, c1, r2, c2;

    // Input for first matrix
    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d%d", &r1, &c1);
    int mat1[r1][c1];
    inputMatrix(r1, c1, mat1);
    printMatrix(r1, c1, mat1);

    // Input for second matrix
    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d%d", &r2, &c2);
    int mat2[r2][c2];
    inputMatrix(r2, c2, mat2);
    printMatrix(r2, c2, mat2);

    // Addition
    int addResult[r1][c1];
    addMatrices(r1, c1, r2, c2, mat1, mat2, addResult);
    printMatrix(r1, c1, addResult);

    // Subtraction
    int subResult[r1][c1];
    subtractMatrices(r1, c1, r2, c2, mat1, mat2, subResult);
    printMatrix(r1, c1, subResult);

    // Multiplication
    int mulResult[r1][c2];
    multiplyMatrices(r1, c1, r2, c2, mat1, mat2, mulResult);
    printMatrix(r1, c2, mulResult);

    return 0;
}