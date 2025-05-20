//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: real-life
// Program to perform matrix operations in a real-life style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
struct Matrix {
    int rows;
    int cols;
    int **data;
};

// Function to create a matrix
struct Matrix *createMatrix(int rows, int cols) {
    struct Matrix *matrix = malloc(sizeof(struct Matrix));
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
void printMatrix(struct Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
struct Matrix *addMatrices(struct Matrix *matrix1, struct Matrix *matrix2) {
    struct Matrix *result = createMatrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
struct Matrix *multiplyMatrices(struct Matrix *matrix1, struct Matrix *matrix2) {
    struct Matrix *result = createMatrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            for (int k = 0; k < matrix1->cols; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
    return result;
}

int main() {
    // Create two matrices
    struct Matrix *matrix1 = createMatrix(3, 3);
    struct Matrix *matrix2 = createMatrix(3, 3);

    // Fill the matrices with some data
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
    matrix2->data[0][1] = 20;
    matrix2->data[0][2] = 30;
    matrix2->data[1][0] = 40;
    matrix2->data[1][1] = 50;
    matrix2->data[1][2] = 60;
    matrix2->data[2][0] = 70;
    matrix2->data[2][1] = 80;
    matrix2->data[2][2] = 90;

    // Print the matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("Matrix 2:\n");
    printMatrix(matrix2);

    // Add the matrices
    struct Matrix *result = addMatrices(matrix1, matrix2);
    printf("Matrix 1 + Matrix 2:\n");
    printMatrix(result);

    // Multiply the matrices
    result = multiplyMatrices(matrix1, matrix2);
    printf("Matrix 1 * Matrix 2:\n");
    printMatrix(result);

    // Free the memory allocated for the matrices
    free(matrix1->data);
    free(matrix2->data);
    free(result->data);
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}