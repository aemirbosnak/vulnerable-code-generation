//FormAI DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>

// Function to display the elements of a matrix
void display(int mat[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add(int mat1[][100], int mat2[][100], int res[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(int mat1[][100], int mat2[][100], int res[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply(int mat1[][100], int mat2[][100], int res[][100], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[100][100], mat2[100][100], res[100][100];
    int row1, col1, row2, col2;

    // Get the dimensions of first matrix
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d %d", &row1, &col1);

    // Get the elements of first matrix
    printf("Enter the elements of first matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Get the dimensions of second matrix
    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d %d", &row2, &col2);

    // Get the elements of second matrix
    printf("Enter the elements of second matrix:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Display the matrices
    printf("\nMatrix 1:\n");
    display(mat1, row1, col1);

    printf("\nMatrix 2:\n");
    display(mat2, row2, col2);

    // Perform addition
    if (row1 == row2 && col1 == col2) {
        add(mat1, mat2, res, row1, col1);
        printf("\nAddition:\n");
        display(res, row1, col1);
    } else {
        printf("\nCannot perform addition. Dimensions do not match.\n");
    }

    // Perform subtraction
    if (row1 == row2 && col1 == col2) {
        subtract(mat1, mat2, res, row1, col1);
        printf("\nSubtraction:\n");
        display(res, row1, col1);
    } else {
        printf("\nCannot perform subtraction. Dimensions do not match.\n");
    }

    // Perform multiplication
    if (col1 == row2) {
        multiply(mat1, mat2, res, row1, col1, col2);
        printf("\nMultiplication:\n");
        display(res, row1, col2);
    } else {
        printf("\nCannot perform multiplication. Invalid dimensions.\n");
    }

    return 0;
}