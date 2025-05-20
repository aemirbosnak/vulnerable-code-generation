//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int result[MAX_SIZE][MAX_SIZE], int m1[MAX_SIZE][MAX_SIZE], int m2[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void subtractMatrices(int result[MAX_SIZE][MAX_SIZE], int m1[MAX_SIZE][MAX_SIZE], int m2[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }
}

void multiplyMatrices(int result[MAX_SIZE][MAX_SIZE], int m1[MAX_SIZE][MAX_SIZE], int m2[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void transposeMatrix(int result[MAX_SIZE][MAX_SIZE], int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;
    
    // Input for the first matrix
    printf("Let's start with the first matrix! How many rows does it have?\n");
    scanf("%d", &rows1);
    printf("How many columns does it have?\n");
    scanf("%d", &cols1);
    inputMatrix(matrix1, rows1, cols1);
    
    // Input for the second matrix
    printf("Now, let's define the second matrix. How many rows does it have?\n");
    scanf("%d", &rows2);
    printf("How many columns does it have?\n");
    scanf("%d", &cols2);
    inputMatrix(matrix2, rows2, cols2);
    
    // Checking addition condition
    if (rows1 == rows2 && cols1 == cols2) {
        addMatrices(result, matrix1, matrix2, rows1, cols1);
        printf("Addition of the two matrices:\n");
        printMatrix(result, rows1, cols1);
    } else {
        printf("Whoa! The matrices can't be added due to their mismatch in dimensions!\n");
    }
    
    // Checking subtraction condition
    if (rows1 == rows2 && cols1 == cols2) {
        subtractMatrices(result, matrix1, matrix2, rows1, cols1);
        printf("Subtraction of the two matrices:\n");
        printMatrix(result, rows1, cols1);
    } else {
        printf("Oh no! The matrices can't be subtracted due to their mismatched dimensions!\n");
    }

    // Checking multiplication condition
    if (cols1 == rows2) {
        multiplyMatrices(result, matrix1, matrix2, rows1, cols1, rows2, cols2);
        printf("Multiplication of the two matrices:\n");
        printMatrix(result, rows1, cols2);
    } else {
        printf("Hmm! The matrices can't be multiplied because the number of columns in the first isn't equal to the number of rows in the second!\n");
    }

    // Transposition
    printf("Finally, let's transpose the first matrix!\n");
    transposeMatrix(result, matrix1, rows1, cols1);
    printf("The transposed first matrix is:\n");
    printMatrix(result, cols1, rows1);
    
    return 0;
}