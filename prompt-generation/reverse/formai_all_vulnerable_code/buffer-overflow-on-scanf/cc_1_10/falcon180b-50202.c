//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void create_matrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[j][i] = matrix[i][j];
        }
    }
}

void multiply_matrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int rows2, int cols2) {
    int i, j, k;
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    create_matrix(matrix1, rows1, cols1);
    printf("Matrix 1:\n");
    print_matrix(matrix1, rows1, cols1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    if (cols1!= rows2) {
        printf("Error: Incompatible dimensions for matrix multiplication.\n");
        return 1;
    }
    create_matrix(matrix2, rows2, cols2);
    printf("Matrix 2:\n");
    print_matrix(matrix2, rows2, cols2);

    multiply_matrices(matrix1, matrix2, result, rows1, cols1, rows2, cols2);
    printf("Result of matrix multiplication:\n");
    print_matrix(result, rows1, cols2);

    transpose_matrix(matrix1, rows1, cols1);
    printf("\nTranspose of Matrix 1:\n");
    print_matrix(matrix1, cols1, rows1);

    return 0;
}