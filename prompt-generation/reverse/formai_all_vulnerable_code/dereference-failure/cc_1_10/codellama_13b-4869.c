//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: curious
// A curious C Matrix operations example program
#include <stdio.h>
#include <stdlib.h>

// Define a matrix structure
typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

// Function to create a matrix
Matrix* create_matrix(int rows, int cols) {
    Matrix* mat = malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = malloc(cols * sizeof(int));
    }
    return mat;
}

// Function to print a matrix
void print_matrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix* add_matrices(Matrix* mat1, Matrix* mat2) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        return NULL;
    }
    Matrix* sum = create_matrix(mat1->rows, mat1->cols);
    for (int i = 0; i < sum->rows; i++) {
        for (int j = 0; j < sum->cols; j++) {
            sum->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return sum;
}

// Function to multiply two matrices
Matrix* multiply_matrices(Matrix* mat1, Matrix* mat2) {
    if (mat1->cols != mat2->rows) {
        return NULL;
    }
    Matrix* product = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < product->rows; i++) {
        for (int j = 0; j < product->cols; j++) {
            product->data[i][j] = 0;
            for (int k = 0; k < mat1->cols; k++) {
                product->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
            }
        }
    }
    return product;
}

// Function to transpose a matrix
Matrix* transpose_matrix(Matrix* mat) {
    Matrix* transpose = create_matrix(mat->cols, mat->rows);
    for (int i = 0; i < transpose->rows; i++) {
        for (int j = 0; j < transpose->cols; j++) {
            transpose->data[i][j] = mat->data[j][i];
        }
    }
    return transpose;
}

// Function to invert a matrix
Matrix* invert_matrix(Matrix* mat) {
    if (mat->rows != mat->cols) {
        return NULL;
    }
    Matrix* inverse = create_matrix(mat->rows, mat->cols);
    for (int i = 0; i < inverse->rows; i++) {
        for (int j = 0; j < inverse->cols; j++) {
            inverse->data[i][j] = 1 / mat->data[i][j];
        }
    }
    return inverse;
}

int main() {
    // Create two matrices
    Matrix* mat1 = create_matrix(2, 3);
    mat1->data[0][0] = 1;
    mat1->data[0][1] = 2;
    mat1->data[0][2] = 3;
    mat1->data[1][0] = 4;
    mat1->data[1][1] = 5;
    mat1->data[1][2] = 6;
    Matrix* mat2 = create_matrix(2, 3);
    mat2->data[0][0] = 7;
    mat2->data[0][1] = 8;
    mat2->data[0][2] = 9;
    mat2->data[1][0] = 10;
    mat2->data[1][1] = 11;
    mat2->data[1][2] = 12;

    // Add matrices
    Matrix* sum = add_matrices(mat1, mat2);
    printf("Sum of matrices: \n");
    print_matrix(sum);

    // Multiply matrices
    Matrix* product = multiply_matrices(mat1, mat2);
    printf("Product of matrices: \n");
    print_matrix(product);

    // Transpose matrices
    Matrix* transpose1 = transpose_matrix(mat1);
    printf("Transpose of matrix 1: \n");
    print_matrix(transpose1);
    Matrix* transpose2 = transpose_matrix(mat2);
    printf("Transpose of matrix 2: \n");
    print_matrix(transpose2);

    // Invert matrices
    Matrix* inverse1 = invert_matrix(mat1);
    printf("Inverse of matrix 1: \n");
    print_matrix(inverse1);
    Matrix* inverse2 = invert_matrix(mat2);
    printf("Inverse of matrix 2: \n");
    print_matrix(inverse2);

    // Free memory
    free(mat1->data);
    free(mat1);
    free(mat2->data);
    free(mat2);
    free(sum->data);
    free(sum);
    free(product->data);
    free(product);
    free(transpose1->data);
    free(transpose1);
    free(transpose2->data);
    free(transpose2);
    free(inverse1->data);
    free(inverse1);
    free(inverse2->data);
    free(inverse2);

    return 0;
}