//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Variables to store the Matrix dimensions and elements
    int rows, cols, i, j, k, l;

    // Create a pointer to a 2D array
    int **matrix = NULL;

    // Memory allocation for the Matrix
    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Get the Matrix dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Fill the Matrix with elements
    printf("Enter the elements of the Matrix: ");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Transpose the Matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            for (k = 0; k < rows; k++) {
                for (l = 0; l < cols; l++) {
                    if (k == i && l == j) {
                        matrix[k][l] = matrix[i][j];
                    }
                }
            }
        }
    }

    // Print the transposed Matrix
    printf("The transposed Matrix is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the Matrix
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}