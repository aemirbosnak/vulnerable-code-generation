//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void print_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void add_matrices(int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols);
void subtract_matrices(int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols);
void multiply_matrices(int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows1, int cols1, int rows2, int cols2);
void transpose_matrix(int matrix[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols);

int main() {
    int mat1[MAX_ROWS][MAX_COLS], mat2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int rows, cols;
    
    printf("Enter the number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Exceeded maximum dimensions!\n");
        return 1;
    }

    srand(time(0));

    // Initialize matrices with random values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat1[i][j] = rand() % 10;
            mat2[i][j] = rand() % 10;
        }
    }

    printf("\nMatrix 1:\n");
    print_matrix(mat1, rows, cols);
    
    printf("\nMatrix 2:\n");
    print_matrix(mat2, rows, cols);

    // Matrix Addition
    add_matrices(mat1, mat2, result, rows, cols);
    printf("\nMatrix Addition Result:\n");
    print_matrix(result, rows, cols);

    // Matrix Subtraction
    subtract_matrices(mat1, mat2, result, rows, cols);
    printf("\nMatrix Subtraction Result:\n");
    print_matrix(result, rows, cols);

    // Matrix Multiplication (columns of mat1 should equal rows of mat2)
    printf("\nMultiplying matrices of size %dx%d and %dx%d\n", rows, cols, cols, rows);
    if (cols == rows) {
        multiply_matrices(mat1, mat2, result, rows, cols, cols, rows);
        printf("\nMatrix Multiplication Result:\n");
        print_matrix(result, rows, rows);
    } else {
        printf("Error: Number of columns of first matrix must equal number of rows of second matrix for multiplication!\n");
    }

    // Matrix Transposition
    transpose_matrix(mat1, result, rows, cols);
    printf("\nTransposed Matrix 1:\n");
    print_matrix(result, cols, rows);

    return 0;
}

void print_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtract_matrices(int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiply_matrices(int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transpose_matrix(int matrix[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}