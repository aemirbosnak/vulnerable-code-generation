//Falcon-180B DATASET v1.0 Category: Error handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generate_random_matrix(int rows, int cols, int matrix[rows][cols]);
void print_matrix(int rows, int cols, int matrix[rows][cols]);

int main() {
    int rows, cols;

    // Get user input for number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Check if number of rows and columns are valid
    if (rows <= 0 || cols <= 0) {
        printf("Error: Invalid number of rows or columns.\n");
        return 1;
    }

    // Generate random matrix
    int matrix[rows][cols];
    generate_random_matrix(rows, cols, matrix);

    // Print matrix
    printf("Random matrix:\n");
    print_matrix(rows, cols, matrix);

    return 0;
}

// Function to generate a random matrix
void generate_random_matrix(int rows, int cols, int matrix[rows][cols]) {
    srand(time(NULL)); // Seed random number generator with current time

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; // Generate random integer between 0 and 99
        }
    }
}

// Function to print a matrix
void print_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}