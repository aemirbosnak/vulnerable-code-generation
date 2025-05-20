//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: artistic
/*
 * Matrix Operations Example Program
 *
 * Written in C
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Matrix structure
typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

// Function to create a matrix
Matrix *createMatrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(double));
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
            printf("%lf ", matrix->data[i][j]);
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
            double sum = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                sum += matrix1->data[i][k] * matrix2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

int main() {
    // Create two matrices
    Matrix *matrix1 = createMatrix(3, 3);
    Matrix *matrix2 = createMatrix(3, 3);

    // Initialize the matrices with some values
    matrix1->data[0][0] = 1;
    matrix1->data[0][1] = 2;
    matrix1->data[0][2] = 3;
    matrix1->data[1][0] = 4;
    matrix1->data[1][1] = 5;
    matrix1->data[1][2] = 6;
    matrix1->data[2][0] = 7;
    matrix1->data[2][1] = 8;
    matrix1->data[2][2] = 9;

    matrix2->data[0][0] = 10;
    matrix2->data[0][1] = 11;
    matrix2->data[0][2] = 12;
    matrix2->data[1][0] = 13;
    matrix2->data[1][1] = 14;
    matrix2->data[1][2] = 15;
    matrix2->data[2][0] = 16;
    matrix2->data[2][1] = 17;
    matrix2->data[2][2] = 18;

    // Add the matrices
    Matrix *result = addMatrices(matrix1, matrix2);

    // Print the result
    printf("Addition of the matrices:\n");
    printMatrix(result);

    // Multiply the matrices
    result = multiplyMatrices(matrix1, matrix2);

    // Print the result
    printf("Multiplication of the matrices:\n");
    printMatrix(result);

    // Free the memory
    free(matrix1->data);
    free(matrix2->data);
    free(result->data);
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}