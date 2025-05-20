//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: relaxed
// Program to perform unique C Matrix operations

#include <stdio.h>

// Define a structure to represent a matrix
struct Matrix {
    int rows;
    int cols;
    int **data;
};

// Function to initialize a matrix
void init_matrix(struct Matrix *mat, int rows, int cols) {
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            mat->data[i][j] = 0;
        }
    }
}

// Function to print a matrix
void print_matrix(struct Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(struct Matrix *mat1, struct Matrix *mat2, struct Matrix *result) {
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(struct Matrix *mat1, struct Matrix *mat2, struct Matrix *result) {
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < mat1->cols; k++) {
                result->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transpose_matrix(struct Matrix *mat, struct Matrix *result) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[j][i] = mat->data[i][j];
        }
    }
}

int main() {
    // Initialize two matrices
    struct Matrix mat1, mat2, result;
    init_matrix(&mat1, 2, 3);
    init_matrix(&mat2, 3, 2);
    init_matrix(&result, 2, 2);

    // Add two matrices
    add_matrices(&mat1, &mat2, &result);
    printf("Addition of two matrices:\n");
    print_matrix(result);

    // Multiply two matrices
    multiply_matrices(&mat1, &mat2, &result);
    printf("Multiplication of two matrices:\n");
    print_matrix(result);

    // Transpose a matrix
    transpose_matrix(&mat1, &result);
    printf("Transpose of a matrix:\n");
    print_matrix(result);

    return 0;
}