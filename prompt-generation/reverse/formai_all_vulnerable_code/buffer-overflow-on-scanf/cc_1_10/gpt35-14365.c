//FormAI DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
/* A Donald Knuth inspired C program to perform matrix operations */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10             /* Maximum number of rows in matrix */
#define MAX_COLS 10             /* Maximum number of columns in matrix */

/* Function to input matrix dimensions */
void input_dimension(int *rows, int *cols) {
    printf("Enter number of rows (max %d): ", MAX_ROWS);
    scanf("%d", rows);
    printf("Enter number of columns (max %d): ", MAX_COLS);
    scanf("%d", cols);
}

/* Function to input a matrix */
void input_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int i, j;
    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

/* Function to display a matrix */
void display_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int i, j;
    printf("Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to add two matrices */
void add_matrices(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int i, j;
    int result[MAX_ROWS][MAX_COLS];
    printf("Addition of matrices:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

/* Function to multiply two matrices */
void multiply_matrices(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int rows1, int cols1, int cols2) {
    int i, j, k;
    int result[MAX_ROWS][MAX_COLS];
    printf("Multiplication of matrices:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

/* Main function */
int main() {
    int rows1, cols1, rows2, cols2;
    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS];

    printf("Welcome to Matrix Operations!\n");

    /* Input matrix dimensions and elements */
    input_dimension(&rows1, &cols1);
    input_matrix(matrix1, rows1, cols1);
    input_dimension(&rows2, &cols2);
    input_matrix(matrix2, rows2, cols2);

    /* Display matrices */
    display_matrix(matrix1, rows1, cols1);
    display_matrix(matrix2, rows2, cols2);

    /* Check if matrices can be added or multiplied */
    if (rows1 == rows2 && cols1 == cols2) {
        add_matrices(matrix1, matrix2, rows1, cols1);
    }
    if (cols1 == rows2) {
        multiply_matrices(matrix1, matrix2, rows1, cols1, cols2);
    }

    return 0;
}