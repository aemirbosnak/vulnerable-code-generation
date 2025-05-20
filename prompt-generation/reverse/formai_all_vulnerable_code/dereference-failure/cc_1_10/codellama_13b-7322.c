//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MATRIX_SIZE 3
#define MATRIX_ELEMENTS (MATRIX_SIZE * MATRIX_SIZE)

typedef struct {
    int elements[MATRIX_ELEMENTS];
} Matrix;

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix->elements[i * MATRIX_SIZE + j]);
        }
        printf("\n");
    }
}

Matrix* create_matrix(int size) {
    Matrix *matrix = malloc(sizeof(Matrix));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix->elements[i * size + j] = rand() % 100;
        }
    }
    return matrix;
}

Matrix* add_matrices(Matrix *matrix1, Matrix *matrix2) {
    Matrix *result = malloc(sizeof(Matrix));
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result->elements[i * MATRIX_SIZE + j] = matrix1->elements[i * MATRIX_SIZE + j] + matrix2->elements[i * MATRIX_SIZE + j];
        }
    }
    return result;
}

Matrix* multiply_matrices(Matrix *matrix1, Matrix *matrix2) {
    Matrix *result = malloc(sizeof(Matrix));
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result->elements[i * MATRIX_SIZE + j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                result->elements[i * MATRIX_SIZE + j] += matrix1->elements[i * MATRIX_SIZE + k] * matrix2->elements[k * MATRIX_SIZE + j];
            }
        }
    }
    return result;
}

int main() {
    srand(time(NULL));

    Matrix *matrix1 = create_matrix(MATRIX_SIZE);
    Matrix *matrix2 = create_matrix(MATRIX_SIZE);

    printf("Matrix 1:\n");
    print_matrix(matrix1);

    printf("\nMatrix 2:\n");
    print_matrix(matrix2);

    Matrix *sum = add_matrices(matrix1, matrix2);
    Matrix *product = multiply_matrices(matrix1, matrix2);

    printf("\nSum:\n");
    print_matrix(sum);

    printf("\nProduct:\n");
    print_matrix(product);

    free(matrix1);
    free(matrix2);
    free(sum);
    free(product);

    return 0;
}