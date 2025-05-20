//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** create_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free allocated memory for a matrix
void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to input matrix elements
void input_matrix(int** matrix, int rows, int cols) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void print_matrix(int** matrix, int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int** add_matrices(int** a, int** b, int rows, int cols) {
    int** result = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices
int** subtract_matrices(int** a, int** b, int rows, int cols) {
    int** result = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
int** multiply_matrices(int** a, int** b, int rows_a, int cols_a, int cols_b) {
    int** result = create_matrix(rows_a, cols_b);
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols_a; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
int** transpose_matrix(int** matrix, int rows, int cols) {
    int** transposed = create_matrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main() {
    int rows_a, cols_a, rows_b, cols_b;

    printf("Welcome to the Matrix Operations Program!\n");
    printf("Enter rows and columns for the first matrix (A): ");
    scanf("%d%d", &rows_a, &cols_a);
    
    int** matrix_a = create_matrix(rows_a, cols_a);
    input_matrix(matrix_a, rows_a, cols_a);
    print_matrix(matrix_a, rows_a, cols_a);

    printf("Enter rows and columns for the second matrix (B): ");
    scanf("%d%d", &rows_b, &cols_b);
    
    if (rows_a != rows_b || cols_a != cols_b) {
        printf("Addition and Subtraction require matrices of the same dimensions!\n");
        free_matrix(matrix_a, rows_a);
        return -1;
    }
    
    int** matrix_b = create_matrix(rows_b, cols_b);
    input_matrix(matrix_b, rows_b, cols_b);
    print_matrix(matrix_b, rows_b, cols_b);

    // Perform matrix operations
    int** sum_matrix = add_matrices(matrix_a, matrix_b, rows_a, cols_a);
    print_matrix(sum_matrix, rows_a, cols_a);

    int** diff_matrix = subtract_matrices(matrix_a, matrix_b, rows_a, cols_a);
    print_matrix(diff_matrix, rows_a, cols_a);

    if (cols_a != rows_b) {
        printf("Matrices cannot be multiplied!\n");
    } else {
        int** product_matrix = multiply_matrices(matrix_a, matrix_b, rows_a, cols_a, cols_b);
        print_matrix(product_matrix, rows_a, cols_b);
        free_matrix(product_matrix, rows_a);
    }

    int** transposed_a = transpose_matrix(matrix_a, rows_a, cols_a);
    print_matrix(transposed_a, cols_a, rows_a);

    int** transposed_b = transpose_matrix(matrix_b, rows_b, cols_b);
    print_matrix(transposed_b, cols_b, rows_b);
    
    // Free allocated memory
    free_matrix(matrix_a, rows_a);
    free_matrix(matrix_b, rows_b);
    free_matrix(sum_matrix, rows_a);
    free_matrix(diff_matrix, rows_a);
    free_matrix(transposed_a, cols_a);
    free_matrix(transposed_b, cols_b);

    printf("Thank you for using the Matrix Operations Program!\n");
    
    return 0;
}