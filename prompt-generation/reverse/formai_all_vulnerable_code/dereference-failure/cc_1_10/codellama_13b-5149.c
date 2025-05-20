//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: curious
// Curious Matrix Operations Example Program

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a matrix
Matrix *create_matrix(int rows, int cols) {
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            mat->data[i][j] = 0;
        }
    }
    return mat;
}

// Function to print a matrix
void print_matrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix addition
Matrix *add_matrices(Matrix *mat1, Matrix *mat2) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        printf("Matrices have different dimensions.\n");
        return NULL;
    }
    Matrix *sum = create_matrix(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            sum->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return sum;
}

// Function to perform matrix multiplication
Matrix *multiply_matrices(Matrix *mat1, Matrix *mat2) {
    if (mat1->cols != mat2->rows) {
        printf("Matrices cannot be multiplied.\n");
        return NULL;
    }
    Matrix *product = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            product->data[i][j] = 0;
            for (int k = 0; k < mat1->cols; k++) {
                product->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
            }
        }
    }
    return product;
}

// Function to perform matrix transpose
Matrix *transpose_matrix(Matrix *mat) {
    Matrix *transpose = create_matrix(mat->cols, mat->rows);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            transpose->data[j][i] = mat->data[i][j];
        }
    }
    return transpose;
}

int main() {
    // Create two matrices
    Matrix *mat1 = create_matrix(2, 3);
    Matrix *mat2 = create_matrix(2, 3);

    // Initialize matrix elements
    mat1->data[0][0] = 1;
    mat1->data[0][1] = 2;
    mat1->data[0][2] = 3;
    mat1->data[1][0] = 4;
    mat1->data[1][1] = 5;
    mat1->data[1][2] = 6;

    mat2->data[0][0] = 7;
    mat2->data[0][1] = 8;
    mat2->data[0][2] = 9;
    mat2->data[1][0] = 10;
    mat2->data[1][1] = 11;
    mat2->data[1][2] = 12;

    // Print matrices
    printf("Matrix 1:\n");
    print_matrix(mat1);
    printf("\nMatrix 2:\n");
    print_matrix(mat2);

    // Perform matrix addition
    Matrix *sum = add_matrices(mat1, mat2);
    printf("\nSum of matrices:\n");
    print_matrix(sum);

    // Perform matrix multiplication
    Matrix *product = multiply_matrices(mat1, mat2);
    printf("\nProduct of matrices:\n");
    print_matrix(product);

    // Perform matrix transpose
    Matrix *transpose = transpose_matrix(mat1);
    printf("\nTranspose of matrix:\n");
    print_matrix(transpose);

    // Free memory
    free(mat1->data);
    free(mat1);
    free(mat2->data);
    free(mat2);
    free(sum->data);
    free(sum);
    free(product->data);
    free(product);
    free(transpose->data);
    free(transpose);

    return 0;
}