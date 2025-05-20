//FormAI DATASET v1.0 Category: Matrix operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Function to initialize a matrix with random values
void initialize_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int **add_matrices(int **matrix1, int **matrix2, int rows, int cols) {
    int **result_matrix = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result_matrix[i] = (int *) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result_matrix;
}

// Function to multiply two matrices
int **multiply_matrices(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Error: columns of first matrix must match rows of second matrix.\n");
        exit(1);
    }
    int **result_matrix = (int **) malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result_matrix[i] = (int *) malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            result_matrix[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result_matrix;
}

int main() {
    printf("Welcome to my matrix operations program!\n\n");

    int rows1, cols1;
    printf("Enter number of rows for first matrix: ");
    scanf("%d", &rows1);
    printf("Enter number of columns for first matrix: ");
    scanf("%d", &cols1);
    printf("\n");

    int **matrix1 = (int **) malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *) malloc(cols1 * sizeof(int));
    }

    initialize_matrix(matrix1, rows1, cols1);
    printf("First matrix:\n");
    print_matrix(matrix1, rows1, cols1);
    printf("\n");

    int rows2, cols2;
    printf("Enter number of rows for second matrix: ");
    scanf("%d", &rows2);
    printf("Enter number of columns for second matrix: ");
    scanf("%d", &cols2);
    printf("\n");

    int **matrix2 = (int **) malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *) malloc(cols2 * sizeof(int));
    }

    initialize_matrix(matrix2, rows2, cols2);
    printf("Second matrix:\n");
    print_matrix(matrix2, rows2, cols2);
    printf("\n");

    int **sum_matrix = add_matrices(matrix1, matrix2, rows1, cols1);
    printf("Matrix sum:\n");
    print_matrix(sum_matrix, rows1, cols1);
    printf("\n");

    int **product_matrix = multiply_matrices(matrix1, matrix2, rows1, cols1, rows2, cols2);
    printf("Matrix product:\n");
    print_matrix(product_matrix, rows1, cols2);
    printf("\n");

    return 0;
}