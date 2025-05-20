//Falcon-180B DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j, num, count = 0;
    int **matrix;
    srand(time(NULL));

    // Prompt user for matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for matrix
    matrix = (int **) malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int));
    }

    // Fill matrix with random integers
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Prompt user for number to search for
    printf("Enter number to search for: ");
    scanf("%d", &num);

    // Search for number in matrix and count occurrences
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] == num) {
                count++;
            }
        }
    }

    // Print results
    printf("Number of occurrences: %d\n", count);

    // Free memory
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}