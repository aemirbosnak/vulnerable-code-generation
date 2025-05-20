//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

void allocate_matrix(int rows, int cols, int ***matrix) {
    *matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = (int *)malloc(cols * sizeof(int));
    }
}

void free_matrix(int rows, int ***matrix) {
    for (int i = 0; i < rows; i++) {
        free((*matrix)[i]);
    }
    free(*matrix);
}

void input_matrix(int rows, int cols, int **matrix) {
    printf("Enter the elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            while (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter an integer: ");
                while (getchar() != '\n'); // clear invalid input
            }
        }
    }
}

void print_matrix(int rows, int cols, int **matrix) {
    printf("Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int rows, int cols, int **A, int **B, int **result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract_matrices(int rows, int cols, int **A, int **B, int **result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiply_matrices(int rowsA, int colsA, int colsB, int **A, int **B, int **result) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transpose_matrix(int rows, int cols, int **matrix, int **result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter rows and columns of the matrix: ");
    while (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("Invalid input. Please enter positive integers for rows and columns: ");
        while (getchar() != '\n'); // clear invalid input
    }

    int **A, **B, **result;
    
    // Allocate and input first matrix
    allocate_matrix(rows, cols, &A);
    input_matrix(rows, cols, A);
    print_matrix(rows, cols, A);
    
    // Allocate and input second matrix
    allocate_matrix(rows, cols, &B);
    input_matrix(rows, cols, B);
    print_matrix(rows, cols, B);
    
    // Allocate result matrices
    allocate_matrix(rows, cols, &result);
    
    // Addition
    add_matrices(rows, cols, A, B, result);
    printf("Result of addition:\n");
    print_matrix(rows, cols, result);
    
    // Subtraction
    subtract_matrices(rows, cols, A, B, result);
    printf("Result of subtraction:\n");
    print_matrix(rows, cols, result);
    
    // Multiplication - allowed only when cols of A == rows of B
    if (cols == rows) {
        int **C;
        allocate_matrix(cols, cols, &C);
        multiply_matrices(rows, cols, cols, A, B, C);
        printf("Result of multiplication:\n");
        print_matrix(rows, cols, C);
        free_matrix(cols, &C);
    } else {
        printf("Multiplication not possible: columns of A and rows of B do not match.\n");
    }
    
    // Transpose
    int **transpose;
    allocate_matrix(cols, rows, &transpose);
    transpose_matrix(rows, cols, A, transpose);
    printf("Transpose of first matrix:\n");
    print_matrix(cols, rows, transpose);
    
    // Clean up
    free_matrix(rows, &A);
    free_matrix(rows, &B);
    free_matrix(rows, &result);
    free_matrix(cols, &transpose);

    return 0;
}