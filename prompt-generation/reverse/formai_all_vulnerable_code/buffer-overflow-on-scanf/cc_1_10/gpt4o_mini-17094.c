//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100  // Define maximum matrix size for simplicity

// Function to initialize a matrix with random values
void initialize_matrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // Random value between 0-9
        }
    }
}

// Function to print a matrix
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices using optimized loops
void multiply_matrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], 
                       int row1, int col1, int col2) {
    // Initialize result matrix to zero
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
        }
    }

    // Multiplication
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int row1, col1, row2, col2;
    
    srand(time(NULL)); // Seed for random number generation

    // Input for the first matrix
    printf("Enter rows and columns for the first matrix (A): ");
    scanf("%d %d", &row1, &col1);
    
    // Input for the second matrix
    printf("Enter rows and columns for the second matrix (B): ");
    scanf("%d %d", &row2, &col2);

    // Matrix multiplication is only possible if col1 == row2
    if (col1 != row2) {
        printf("Matrix multiplication not possible!\n");
        return 1;
    }

    // Initialize matrices
    initialize_matrix(mat1, row1, col1);
    initialize_matrix(mat2, row2, col2);

    // Show input matrices
    printf("\nMatrix A (%dx%d):\n", row1, col1);
    print_matrix(mat1, row1, col1);
    
    printf("\nMatrix B (%dx%d):\n", row2, col2);
    print_matrix(mat2, row2, col2);

    // Multiply the matrices
    multiply_matrices(mat1, mat2, result, row1, col1, col2);
    
    // Display the result
    printf("\nResult Matrix (A x B):\n");
    print_matrix(result, row1, col2);

    return 0;
}