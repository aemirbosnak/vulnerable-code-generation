//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef struct {
    float data[SIZE][SIZE];
} Matrix;

void print_matrix(Matrix matrix) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%.2f ", matrix.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Matrix create_matrix(char* matrix_name) {
    Matrix new_matrix;
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%s_element_%d_%d: ", matrix_name, i, j);
            scanf("%f", &new_matrix.data[i][j]);
        }
    }
    return new_matrix;
}

Matrix add_matrices(Matrix matrix1, Matrix matrix2) {
    Matrix result;
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }
    return result;
}

Matrix multiply_matrices(Matrix matrix1, Matrix matrix2) {
    Matrix result;
    int i, j, k;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result.data[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                result.data[i][j] += matrix1.data[i][k] * matrix2.data[k][j];
            }
        }
    }
    return result;
}

Matrix transpose_matrix(Matrix matrix) {
    Matrix transposed;
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            transposed.data[j][i] = matrix.data[i][j];
        }
    }
    return transposed;
}

int main() {
    Matrix matrix1, matrix2, result, transposed_matrix;

    printf("Enter elements of first matrix:\n");
    matrix1 = create_matrix("matrix1");

    printf("Enter elements of second matrix:\n");
    matrix2 = create_matrix("matrix2");

    print_matrix(matrix1);
    print_matrix(matrix2);

    result = add_matrices(matrix1, matrix2);
    printf("Sum of matrices:\n");
    print_matrix(result);

    result = multiply_matrices(matrix1, matrix2);
    printf("Product of matrices:\n");
    print_matrix(result);

    transposed_matrix = transpose_matrix(matrix1);
    printf("Transpose of matrix1:\n");
    print_matrix(transposed_matrix);

    return 0;
}