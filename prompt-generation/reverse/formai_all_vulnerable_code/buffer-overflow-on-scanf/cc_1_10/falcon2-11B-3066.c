//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create a random matrix
void create_random_matrix(int rows, int cols, int **matrix) {
    int i, j;
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * cols);
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Function to print a matrix
void print_matrix(int rows, int cols, int **matrix) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose a matrix
int **transpose_matrix(int rows, int cols, int **matrix) {
    int i, j;
    int **transposed = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        transposed[i] = (int *)malloc(cols * sizeof(int));
        for (j = 0; j < cols; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}

// Function to multiply two matrices
int **matrix_multiply(int rows1, int cols1, int **matrix1, int cols2, int **matrix2) {
    int i, j, k;
    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
        for (j = 0; j < cols2; j++) {
            int sum = 0;
            for (k = 0; k < cols1; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

int main() {
    int rows, cols, i, j;
    int **matrix1, **matrix2;

    srand(time(NULL));

    printf("Enter number of rows and columns for matrix 1:\n");
    scanf("%d%d", &rows, &cols);

    matrix1 = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        for (j = 0; j < cols; j++) {
            matrix1[i][j] = rand() % 100;
        }
    }

    printf("Enter number of rows and columns for matrix 2:\n");
    scanf("%d%d", &rows, &cols);

    matrix2 = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix2[i] = (int *)malloc(cols * sizeof(int));
        for (j = 0; j < cols; j++) {
            matrix2[i][j] = rand() % 100;
        }
    }

    printf("Matrix 1:\n");
    print_matrix(rows, cols, matrix1);

    printf("Matrix 2:\n");
    print_matrix(rows, cols, matrix2);

    printf("Transpose of matrix 1:\n");
    int **transposed1 = transpose_matrix(rows, cols, matrix1);
    print_matrix(rows, cols, transposed1);

    printf("Multiply matrix 1 and matrix 2:\n");
    int **result = matrix_multiply(rows, cols, matrix1, cols, matrix2);
    print_matrix(rows, cols, result);

    free(matrix1);
    free(matrix2);
    free(transposed1);
    free(result);
    return 0;
}