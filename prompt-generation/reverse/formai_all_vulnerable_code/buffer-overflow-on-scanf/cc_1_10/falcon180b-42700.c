//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the matrix
#define MAX_SIZE 1000

// Function to generate a random matrix
void generate_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int i, j;
    srand(time(NULL));
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Function to print the matrix
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int i, j;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose the matrix
void transpose_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int i, j;
    int new_matrix[MAX_SIZE][MAX_SIZE];
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            new_matrix[j][i] = matrix[i][j];
        }
    }
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            matrix[i][j] = new_matrix[i][j];
        }
    }
}

// Function to multiply the matrix by a scalar
void scalar_multiply_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size, int scalar) {
    int i, j;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            matrix[i][j] *= scalar;
        }
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;

    // Get the size of the matrix from the user
    printf("Enter the size of the matrix: ");
    scanf("%d", &size);

    // Generate a random matrix
    generate_matrix(matrix, size);

    // Print the original matrix
    printf("Original matrix:\n");
    print_matrix(matrix, size);

    // Transpose the matrix
    transpose_matrix(matrix, size);

    // Print the transposed matrix
    printf("Transposed matrix:\n");
    print_matrix(matrix, size);

    // Multiply the matrix by a scalar
    int scalar;
    printf("Enter the scalar: ");
    scanf("%d", &scalar);
    scalar_multiply_matrix(matrix, size, scalar);

    // Print the multiplied matrix
    printf("Multiplied matrix:\n");
    print_matrix(matrix, size);

    return 0;
}