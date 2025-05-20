//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define matrix dimensions
#define ROWS 3
#define COLS 3

// Create matrices as 2D arrays
float serenity_matrix[ROWS][COLS], tranquility_matrix[ROWS][COLS], result_matrix[ROWS][COLS];

// Function to input matrices
void input_matrices(float matrix[ROWS][COLS], char name[20]) {
    int i, j;
    printf("Input elements for the %s matrix:\n", name);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }
}

// Function to perform matrix addition
void add_matrices(float a[ROWS][COLS], float b[ROWS][COLS], float c[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to perform matrix multiplication
void multiply_matrices(float a[ROWS][COLS], float b[ROWS][COLS], float c[ROWS][COLS]) {
    int i, j, k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result_matrix[i][j] = 0;
            for (k = 0; k < COLS; k++) {
                result_matrix[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to print matrices
void print_matrices(float matrix[ROWS][COLS], char name[20]) {
    int i, j;
    printf("\n%s Matrix:\n", name);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize matrices
    input_matrices(serenity_matrix, "Serenity");
    input_matrices(tranquility_matrix, "Tranquility");

    // Perform matrix addition
    add_matrices(serenity_matrix, tranquility_matrix, result_matrix);

    // Print result of matrix addition
    print_matrices(result_matrix, "Result");

    // Perform matrix multiplication
    multiply_matrices(serenity_matrix, tranquility_matrix, result_matrix);

    // Print result of matrix multiplication
    print_matrices(result_matrix, "Result");

    return 0;
}