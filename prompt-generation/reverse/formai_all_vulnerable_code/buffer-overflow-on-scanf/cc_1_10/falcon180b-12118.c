//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void init_matrix(int matrix[MAX][MAX], int size) {
    int i, j;
    srand(time(0));
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int matrix[MAX][MAX], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int matrix[MAX][MAX], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[j][i] = matrix[i][j];
        }
    }
}

void multiply_matrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int size) {
    int i, j, k;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            result[i][j] = 0;
            for (k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];
    int size;

    printf("Enter the size of the matrices (max %d): ", MAX);
    scanf("%d", &size);

    init_matrix(matrix1, size);
    init_matrix(matrix2, size);

    printf("Matrix 1:\n");
    print_matrix(matrix1, size);

    printf("Matrix 2:\n");
    print_matrix(matrix2, size);

    transpose_matrix(matrix2, size);

    printf("Transposed Matrix 2:\n");
    print_matrix(matrix2, size);

    multiply_matrices(matrix1, matrix2, result, size);

    printf("Result of matrix multiplication:\n");
    print_matrix(result, size);

    return 0;
}