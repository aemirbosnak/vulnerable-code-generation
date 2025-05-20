//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: happy
/*
 * Happy Matrix Operations Example Program
 *
 * This program demonstrates the basic operations of matrices in C.
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a new matrix
Matrix *createMatrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix->data[i][j] = 0;
        }
    }
    return matrix;
}

// Function to print a matrix
void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix *addMatrices(Matrix *matrix1, Matrix *matrix2) {
    Matrix *result = createMatrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix *multiplyMatrices(Matrix *matrix1, Matrix *matrix2) {
    Matrix *result = createMatrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
    return result;
}

int main() {
    // Create two matrices
    Matrix *matrix1 = createMatrix(2, 3);
    Matrix *matrix2 = createMatrix(3, 2);

    // Initialize matrices
    matrix1->data[0][0] = 1;
    matrix1->data[0][1] = 2;
    matrix1->data[0][2] = 3;
    matrix1->data[1][0] = 4;
    matrix1->data[1][1] = 5;
    matrix1->data[1][2] = 6;

    matrix2->data[0][0] = 7;
    matrix2->data[0][1] = 8;
    matrix2->data[1][0] = 9;
    matrix2->data[1][1] = 10;
    matrix2->data[2][0] = 11;
    matrix2->data[2][1] = 12;

    // Print matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2);

    // Add matrices
    Matrix *result = addMatrices(matrix1, matrix2);
    printf("\nAddition:\n");
    printMatrix(result);

    // Multiply matrices
    result = multiplyMatrices(matrix1, matrix2);
    printf("\nMultiplication:\n");
    printMatrix(result);

    // Free memory
    free(matrix1->data);
    free(matrix2->data);
    free(result->data);
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}