//FormAI DATASET v1.0 Category: Matrix operations ; Style: peaceful
/*
This is a peaceful C Matrix operations program that performs various mathematical
operations on matrices.

The program allows the user to create matrices, add, subtract, multiply and calculate the
transpose of matrices.

The program tries to keep the user informed about what is happening by outputting messages
about the current operation in progress.

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 10

void inputMatrix(int matrix[MAX_ROWS][MAX_COLUMNS], int rows, int columns) {
    printf("Please input the matrix of size %d x %d\n", rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Matrix input completed!\n");
}

void outputMatrix(int matrix[MAX_ROWS][MAX_COLUMNS], int rows, int columns) {
    printf("The output matrix of size %d x %d is: \n", rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[MAX_ROWS][MAX_COLUMNS], int matrix2[MAX_ROWS][MAX_COLUMNS], int sum[MAX_ROWS][MAX_COLUMNS], int rows, int columns) {
    printf("Adding matrices...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("Matrices added successfully!\n");
}

void subtractMatrices(int matrix1[MAX_ROWS][MAX_COLUMNS], int matrix2[MAX_ROWS][MAX_COLUMNS], int diff[MAX_ROWS][MAX_COLUMNS], int rows, int columns) {
    printf("Subtracting matrices...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            diff[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printf("Matrices subtracted successfully!\n");
}

void multiplyMatrices(int matrix1[MAX_ROWS][MAX_COLUMNS], int matrix2[MAX_ROWS][MAX_COLUMNS], int product[MAX_ROWS][MAX_COLUMNS], int rows1, int columns1, int rows2, int columns2) {
    printf("Multiplying matrices...\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            product[i][j] = 0;
            for (int k = 0; k < columns1; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("Matrices multiplied successfully!\n");
}

void transposeMatrix(int matrix[MAX_ROWS][MAX_COLUMNS], int transpose[MAX_ROWS][MAX_COLUMNS], int rows, int columns) {
    printf("Calculating transpose of matrix...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    printf("Transpose calculated successfully!\n");
}

int main() {
    int rows1, columns1, rows2, columns2;
    int matrix1[MAX_ROWS][MAX_COLUMNS];
    int matrix2[MAX_ROWS][MAX_COLUMNS];
    int sum[MAX_ROWS][MAX_COLUMNS];
    int diff[MAX_ROWS][MAX_COLUMNS];
    int product[MAX_ROWS][MAX_COLUMNS];
    int transpose[MAX_ROWS][MAX_COLUMNS];

    printf("Welcome to peaceful C Matrix Operations program!\n");

    printf("Please enter the number of rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &columns1);
    inputMatrix(matrix1, rows1, columns1);
    outputMatrix(matrix1, rows1, columns1);

    printf("Please enter the number of rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &columns2);
    inputMatrix(matrix2, rows2, columns2);
    outputMatrix(matrix2, rows2, columns2);

    if (rows1 != rows2 || columns1 != columns2) {
        printf("Error: The matrices are of different sizes and cannot be added or subtracted.\n");
    } else {
        addMatrices(matrix1, matrix2, sum, rows1, columns1);
        outputMatrix(sum, rows1, columns1);

        subtractMatrices(matrix1, matrix2, diff, rows1, columns1);
        outputMatrix(diff, rows1, columns1);
    }

    if (columns1 != rows2) {
        printf("Error: The matrices cannot be multiplied in this order.\n");
    } else {
        multiplyMatrices(matrix1, matrix2, product, rows1, columns1, rows2, columns2);
        outputMatrix(product, rows1, columns2);
    }

    transposeMatrix(matrix1, transpose, rows1, columns1);
    outputMatrix(transpose, columns1, rows1);

    transposeMatrix(matrix2, transpose, rows2, columns2);
    outputMatrix(transpose, columns2, rows2);

    printf("Thank you for using the peaceful C Matrix Operations program. Have a pleasant day!\n");

    return 0;
}