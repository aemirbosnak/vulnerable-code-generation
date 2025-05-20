//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define maximum matrix size
#define MAX_SIZE 10

// Declare functions
void printMatrix(double mat[MAX_SIZE][MAX_SIZE], int n);
void generateMatrix(double mat[MAX_SIZE][MAX_SIZE], int n);

int main() {
    // Initialize variables
    int n, i, j;
    double mat[MAX_SIZE][MAX_SIZE];

    // Prompt user for matrix size
    printf("Enter matrix size (max 10): ");
    scanf("%d", &n);

    // Generate random input matrix
    generateMatrix(mat, n);

    // Print input matrix
    printf("Input Matrix:\n");
    printMatrix(mat, n);

    // Solve circuit using Gaussian elimination
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            double ratio = mat[j][i] / mat[i][i];

            for (int k = i + 1; k < n + 1; k++) {
                mat[j][k] = mat[j][k] - ratio * mat[i][k];
            }
        }
    }

    // Calculate final values using back substitution
    double solutions[MAX_SIZE] = {0};
    for (i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (j = i + 1; j < n; j++) {
            sum += mat[i][j] * solutions[j];
        }

        solutions[i] = (mat[i][n] - sum) / mat[i][i];
    }

    // Print solution vector
    printf("Solution Vector:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f\n", solutions[i]);
    }

    return 0;
}

// Function to print matrix
void printMatrix(double mat[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to generate random matrix
void generateMatrix(double mat[MAX_SIZE][MAX_SIZE], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            mat[i][j] = (double) rand() / RAND_MAX * 10.0 - 5.0;
        }
    }
}