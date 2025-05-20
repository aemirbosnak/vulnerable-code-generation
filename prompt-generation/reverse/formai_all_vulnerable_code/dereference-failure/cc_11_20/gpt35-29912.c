//FormAI DATASET v1.0 Category: Matrix operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Create a dynamically allocated matrix of size rows x cols
    int **matrix = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int));
    }

    // Initialize the matrix with random values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; // generate integers from 0 to 99
        }
    }

    // Print the initial matrix
    printf("Initial Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Transpose the matrix
    int **transpose = (int **) malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++) {
        transpose[i] = (int *) malloc(rows * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print the transposed matrix
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Multiply the matrix by a scalar
    int scalar;
    printf("\nEnter a scalar value to multiply the matrix by: ");
    scanf("%d", &scalar);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] *= scalar;
        }
    }

    // Print the resulting matrix after scalar multiplication
    printf("\nMatrix after scalar multiplication:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < cols; i++) {
        free(transpose[i]);
    }
    free(transpose);

    return 0;
}