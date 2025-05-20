//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: detailed
/*
 * Matrix operations example program
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    float **data;
} Matrix;

// Function to create a new matrix
Matrix *create_matrix(int rows, int cols) {
    Matrix *mat = malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(rows * cols * sizeof(float));
    return mat;
}

// Function to print a matrix
void print_matrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%.2f ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
Matrix *matrix_multiply(Matrix *mat1, Matrix *mat2) {
    Matrix *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            float sum = 0;
            for (int k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i][k] * mat2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

// Function to add two matrices
Matrix *matrix_add(Matrix *mat1, Matrix *mat2) {
    Matrix *result = create_matrix(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices
Matrix *matrix_subtract(Matrix *mat1, Matrix *mat2) {
    Matrix *result = create_matrix(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] - mat2->data[i][j];
        }
    }
    return result;
}

int main() {
    // Create two matrices
    Matrix *mat1 = create_matrix(3, 3);
    Matrix *mat2 = create_matrix(3, 3);

    // Initialize the matrices with random values
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            mat1->data[i][j] = (float)rand() / RAND_MAX;
            mat2->data[i][j] = (float)rand() / RAND_MAX;
        }
    }

    // Print the matrices
    printf("Mat1:\n");
    print_matrix(mat1);
    printf("Mat2:\n");
    print_matrix(mat2);

    // Multiply the matrices
    Matrix *result = matrix_multiply(mat1, mat2);
    printf("Result of matrix multiplication:\n");
    print_matrix(result);

    // Add the matrices
    result = matrix_add(mat1, mat2);
    printf("Result of matrix addition:\n");
    print_matrix(result);

    // Subtract the matrices
    result = matrix_subtract(mat1, mat2);
    printf("Result of matrix subtraction:\n");
    print_matrix(result);

    // Free the memory
    free(mat1->data);
    free(mat2->data);
    free(result->data);
    free(mat1);
    free(mat2);
    free(result);

    return 0;
}