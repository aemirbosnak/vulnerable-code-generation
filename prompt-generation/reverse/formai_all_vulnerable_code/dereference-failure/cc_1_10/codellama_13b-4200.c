//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: portable
/*
 * Example C Program - Matrix Operations
 *
 * This program demonstrates various matrix operations in C.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int data[MAX_SIZE][MAX_SIZE];
} Matrix;

// Function to print a matrix
void printMatrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to create a matrix
Matrix* createMatrix(int rows, int cols) {
    Matrix* mat = malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat->data[i][j] = rand() % 10;
        }
    }
    return mat;
}

// Function to add two matrices
Matrix* addMatrices(Matrix* mat1, Matrix* mat2) {
    Matrix* sum = malloc(sizeof(Matrix));
    sum->rows = mat1->rows;
    sum->cols = mat1->cols;
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            sum->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return sum;
}

// Function to multiply two matrices
Matrix* multiplyMatrices(Matrix* mat1, Matrix* mat2) {
    Matrix* product = malloc(sizeof(Matrix));
    product->rows = mat1->rows;
    product->cols = mat2->cols;
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i][k] * mat2->data[k][j];
            }
            product->data[i][j] = sum;
        }
    }
    return product;
}

int main() {
    // Create two matrices
    Matrix* mat1 = createMatrix(3, 3);
    Matrix* mat2 = createMatrix(3, 3);

    // Print the matrices
    printf("Matrix 1:\n");
    printMatrix(mat1);
    printf("Matrix 2:\n");
    printMatrix(mat2);

    // Add the matrices
    Matrix* sum = addMatrices(mat1, mat2);
    printf("Sum of matrices:\n");
    printMatrix(sum);

    // Multiply the matrices
    Matrix* product = multiplyMatrices(mat1, mat2);
    printf("Product of matrices:\n");
    printMatrix(product);

    // Free memory
    free(mat1);
    free(mat2);
    free(sum);
    free(product);

    return 0;
}