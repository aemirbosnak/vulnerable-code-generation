//FormAI DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function to print the given matrix
void print_matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices of the same size
void add_matrices(int **matrix1, int **matrix2, int **result, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int **matrix1, int **matrix2, int **result, int rows1, int cols1_rows2, int cols2)
{
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1_rows2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main()
{
    int rows1, cols1, rows2, cols2;

    // Input matrix 1
    printf("Enter the number of rows and columns of matrix 1:\n");
    scanf("%d %d", &rows1, &cols1);
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
        printf("Enter row %d of matrix 1:\n", i + 1);
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input matrix 2
    printf("Enter the number of rows and columns of matrix 2:\n");
    scanf("%d %d", &rows2, &cols2);
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
        printf("Enter row %d of matrix 2:\n", i + 1);
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Check if the matrices can be added/multiplied
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Error: The matrices cannot be added!\n");
        return 1;
    } else if (cols1 != rows2) {
        printf("Error: The matrices cannot be multiplied!\n");
        return 1;
    }

    // Add the matrices
    int **result_sum = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result_sum[i] = (int *)malloc(cols1 * sizeof(int));
    }
    add_matrices(matrix1, matrix2, result_sum, rows1, cols1);

    // Multiply the matrices
    int **result_product = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result_product[i] = (int *)malloc(cols2 * sizeof(int));
    }
    multiply_matrices(matrix1, matrix2, result_product, rows1, cols1, cols2);

    // Output the matrices and their sum and product
    printf("Matrix 1:\n");
    print_matrix(matrix1, rows1, cols1);
    printf("Matrix 2:\n");
    print_matrix(matrix2, rows2, cols2);
    printf("Sum of matrices 1 and 2:\n");
    print_matrix(result_sum, rows1, cols1);
    printf("Product of matrices 1 and 2:\n");
    print_matrix(result_product, rows1, cols2);

    return 0;
}