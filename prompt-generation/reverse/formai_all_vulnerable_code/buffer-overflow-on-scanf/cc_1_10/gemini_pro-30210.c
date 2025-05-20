//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>

// Defining the maximum size of the matrix
#define MAX_SIZE 10

// Function to get the gratitude-filled matrix
int** get_gratitude_matrix(int rows, int cols) {
    // Allocating memory for the matrix
    int** matrix = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) malloc(cols * sizeof(int));
    }

    // Filling the matrix with gratitude
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * j + 1;
        }
    }

    // Returning the gratitude-filled matrix
    return matrix;
}

// Function to print the gratitude-filled matrix
void print_gratitude_matrix(int** matrix, int rows, int cols) {
    // Printing the gratitude-filled matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the gratitude-filled matrix
void free_gratitude_matrix(int** matrix, int rows) {
    // Freeing the memory allocated for the matrix
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Main function
int main() {
    // Getting the number of rows and columns from the user
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Getting the gratitude-filled matrix
    int** matrix = get_gratitude_matrix(rows, cols);

    // Printing the gratitude-filled matrix
    printf("The gratitude-filled matrix is:\n");
    print_gratitude_matrix(matrix, rows, cols);

    // Freeing the gratitude-filled matrix
    free_gratitude_matrix(matrix, rows);

    // Returning 0 to indicate successful execution
    return 0;
}