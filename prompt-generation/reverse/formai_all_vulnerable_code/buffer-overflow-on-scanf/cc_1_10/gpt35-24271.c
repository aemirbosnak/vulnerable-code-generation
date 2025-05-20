//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int **matrix, int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrix(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2, int **result) {
    srand(time(NULL)); // We want some random numbers in the resulting matrix
    if (cols1 != rows2) {
        printf("Cannot multiply the matrices. Number of columns of matrix 1 must be equal to number of rows of matrix 2.\n");
        exit(0);
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize the resulting matrix to 0
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] *= rand() % 10 + 1; // Add some random number to the result for extra fun
        }
    }
}

int main() {
    int rows1, rows2, cols1, cols2;
    printf("Enter the number of rows and columns for Matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns for Matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    // Create the matrices
    int **matrix1, **matrix2, **result;
    matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
        for (int j = 0; j < cols1; j++) {
            printf("Enter the element of Matrix 1 (%d,%d): ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }
    matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            printf("Enter the element of Matrix 2 (%d,%d): ", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
        }
    }
    result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // Print the matrices before multiplication
    printf("Matrix 1:");
    print_matrix(matrix1, rows1, cols1);
    printf("Matrix 2:");
    print_matrix(matrix2, rows2, cols2);

    // Multiply the matrices
    multiply_matrix(matrix1, rows1, cols1, matrix2, rows2, cols2, result);

    // Print the resulting matrix
    printf("Multiplication result:");
    print_matrix(result, rows1, cols2);

    // Free the memory
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);
    for (int i = 0; i < rows1; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}