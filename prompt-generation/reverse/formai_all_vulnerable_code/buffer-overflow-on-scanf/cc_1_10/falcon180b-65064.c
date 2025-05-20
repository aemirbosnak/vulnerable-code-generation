//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void generate_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrices(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1!= rows2) {
        printf("Error: Incompatible matrix dimensions.\n");
        return 1;
    }

    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];

    generate_matrix(matrix1, rows1, cols1);
    generate_matrix(matrix2, rows2, cols2);

    printf("Matrix 1:\n");
    print_matrix(matrix1, rows1, cols1);

    printf("Matrix 2:\n");
    print_matrix(matrix2, rows2, cols2);

    multiply_matrices(matrix1, matrix2, result, rows1, cols2);

    printf("Result:\n");
    print_matrix(result, rows1, cols2);

    return 0;
}