//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MIN_VALUE -10
#define MAX_VALUE 10

// Function to generate a random matrix
void generate_matrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        }
    }
}

// Function to print a matrix
void print_matrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose a matrix
void transpose_matrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int rows1, int cols1, int rows2, int cols2, int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]) {
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
    srand(time(NULL));
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1!= rows2) {
        printf("Matrices cannot be multiplied.\n");
        return 0;
    }

    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    generate_matrix(rows1, cols1, matrix1);
    generate_matrix(rows2, cols2, matrix2);

    printf("Matrix 1:\n");
    print_matrix(rows1, cols1, matrix1);

    printf("Matrix 2:\n");
    print_matrix(rows2, cols2, matrix2);

    transpose_matrix(rows1, cols1, matrix1);
    transpose_matrix(rows2, cols2, matrix2);

    multiply_matrices(rows1, cols2, rows2, cols1, matrix1, matrix2, result);

    printf("Result:\n");
    print_matrix(rows1, cols2, result);

    return 0;
}