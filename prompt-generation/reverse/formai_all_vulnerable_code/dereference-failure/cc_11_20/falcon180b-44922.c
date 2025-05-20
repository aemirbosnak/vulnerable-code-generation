//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROWS 50
#define MAX_COLS 100

int main() {
    int rows, cols;
    int **matrix;
    int i, j;

    // Print header
    printf("C Pattern Printing Example\n\n");

    // Get user input for number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Initialize matrix with random values
    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    // Print matrix
    printf("\nMatrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Print C pattern
    printf("\nC Pattern:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if ((i == 0 || i == rows - 1) && (j == 0 || j == cols - 1)) {
                printf("* ");
            } else if ((i == 0 || i == rows - 1) && (j > 0 && j < cols - 1)) {
                printf("* ");
            } else if ((i > 0 && i < rows - 1) && (j == 0 || j == cols - 1)) {
                printf("* ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}