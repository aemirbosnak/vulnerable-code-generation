//FormAI DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, i, j;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // allocate memory for the matrix
    int **matrix = malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    // fill matrix with random values
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    // print original matrix
    printf("Original Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // perform matrix operations
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] += i + j; // add row and column index to each element
        }
    }

    // print modified matrix
    printf("\nModified Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // calculate sum of diagonal elements
    int sum = 0;
    for (i = 0; i < rows && i < cols; i++) {
        sum += matrix[i][i];
    }
    printf("\nSum of diagonal elements: %d\n", sum);

    // free memory
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}