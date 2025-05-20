//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void generate_matrix(int matrix[][MAX_SIZE], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtract_matrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiply_matrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transpose_matrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the matrix (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    generate_matrix(matrix1, size);
    generate_matrix(matrix2, size);

    printf("Matrix 1:\n");
    print_matrix(matrix1, size);

    printf("Matrix 2:\n");
    print_matrix(matrix2, size);

    add_matrices(matrix1, matrix2, result, size);
    printf("Sum of matrices:\n");
    print_matrix(result, size);

    subtract_matrices(matrix1, matrix2, result, size);
    printf("Difference of matrices:\n");
    print_matrix(result, size);

    multiply_matrices(matrix1, matrix2, result, size);
    printf("Product of matrices:\n");
    print_matrix(result, size);

    transpose_matrix(matrix1, size);
    printf("Transpose of matrix 1:\n");
    print_matrix(matrix1, size);

    return 0;
}