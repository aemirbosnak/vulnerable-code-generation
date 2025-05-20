//FormAI DATASET v1.0 Category: Matrix operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Defining the maximum matrix size
#define MAX_SIZE 10

// Function declarations
void initialize_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size);
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size);
void add_matrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size, int result[MAX_SIZE][MAX_SIZE]);
void subtract_matrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size, int result[MAX_SIZE][MAX_SIZE]);
int find_determinant(int matrix[MAX_SIZE][MAX_SIZE], int size);
void multiply_matrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size, int result[MAX_SIZE][MAX_SIZE]);

int main() {
    int size;
    printf("Enter the size of the matrix (maximum size is %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    // Initialize the matrices with random values
    initialize_matrix(matrix1, size);
    initialize_matrix(matrix2, size);

    printf("Matrix 1:\n");
    print_matrix(matrix1, size);

    printf("Matrix 2:\n");
    print_matrix(matrix2, size);

    // Add the matrices and print the result
    add_matrices(matrix1, matrix2, size, result);
    printf("Matrix 1 + Matrix 2:\n");
    print_matrix(result, size);

    // Subtract the matrices and print the result
    subtract_matrices(matrix1, matrix2, size, result);
    printf("Matrix 1 - Matrix 2:\n");
    print_matrix(result, size);

    // Find the determinant of the first matrix and print the result
    int determinant = find_determinant(matrix1, size);
    printf("Determinant of Matrix 1: %d\n", determinant);

    // Multiply the matrices and print the result
    multiply_matrices(matrix1, matrix2, size, result);
    printf("Matrix 1 * Matrix 2:\n");
    print_matrix(result, size);

    return 0;
}

/*
 * Function to initialize the matrix with random values between 1 and 10
 */
void initialize_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
}

/*
 * Function to print the matrix
 */
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

/*
 * Function to add two matrices
 */
void add_matrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size, int result[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

/*
 * Function to subtract two matrices
 */
void subtract_matrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size, int result[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

/*
 * Function to find the determinant of a matrix
 */
int find_determinant(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    if (size == 1) {
        return matrix[0][0];
    } else {
        int i, j, k;
        int submatrix[MAX_SIZE][MAX_SIZE];
        int sign = 1;
        int determinant = 0;
        for (i = 0; i < size; i++) {
            int sub_i = 0;
            for (j = 1; j < size; j++) {
                int sub_j = 0;
                for (k = 0; k < size; k++) {
                    if (k == i) continue;
                    submatrix[sub_i][sub_j++] = matrix[j][k];
                }
                sub_i++;
            }
            determinant += sign * matrix[0][i] * find_determinant(submatrix, size - 1);
            sign = -sign;
        }
        return determinant;
    }
}

/*
 * Function to multiply two matrices
 */
void multiply_matrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size, int result[MAX_SIZE][MAX_SIZE]) {
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