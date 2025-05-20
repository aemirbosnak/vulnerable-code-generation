//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to generate a random matrix
void generate_matrix(int matrix[][MAX_SIZE], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Function to print a matrix
void print_matrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int size, int result[][MAX_SIZE]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract_matrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int size, int result[][MAX_SIZE]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int size, int result[][MAX_SIZE]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size;

    // Get matrix size from user
    printf("Enter matrix size: ");
    scanf("%d", &size);

    // Generate random matrices
    generate_matrix(matrix1, size);
    generate_matrix(matrix2, size);

    // Print original matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1, size);
    printf("\nMatrix 2:\n");
    print_matrix(matrix2, size);

    // Perform matrix addition
    add_matrices(matrix1, matrix2, size, result);
    printf("\nResult of matrix addition:\n");
    print_matrix(result, size);

    // Perform matrix subtraction
    subtract_matrices(matrix1, matrix2, size, result);
    printf("\nResult of matrix subtraction:\n");
    print_matrix(result, size);

    // Perform matrix multiplication
    multiply_matrices(matrix1, matrix2, size, result);
    printf("\nResult of matrix multiplication:\n");
    print_matrix(result, size);

    return 0;
}