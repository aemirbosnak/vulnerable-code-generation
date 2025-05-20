//FormAI DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// This is a rainbow-colored matrix operations example program!
int main()
{
    int rows, cols, i, j;
    printf("\nWelcome to the Rainbow Matrix Operations Program!\n");
    printf("Let's create a matrix!\n");

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("\nNow let's fill in the matrix with some colorful numbers!\n");

    // Create a rainbow-colored matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i % 6 == 0) {
                matrix[i][j] = 31;  // red
            } else if (i % 6 == 1) {
                matrix[i][j] = 33;  // yellow
            } else if (i % 6 == 2) {
                matrix[i][j] = 32;  // green
            } else if (i % 6 == 3) {
                matrix[i][j] = 36;  // cyan
            } else if (i % 6 == 4) {
                matrix[i][j] = 34;  // blue
            } else {
                matrix[i][j] = 35;  // magenta
            }
        }
    }

    printf("\nWow! Look at this beautiful rainbow matrix:\n\n");

    // Display the rainbow matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nLet's perform some matrix operations on this rainbow matrix!\n");

    // Multiply matrix by 2
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] *= 2;
        }
    }

    printf("\nThe rainbow matrix is now twice as colorful as before!\n");

    printf("\nHere is the updated matrix:\n\n");

    // Display the updated matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    printf("\nThanks for using the Rainbow Matrix Operations Program!\n");
    printf("Have a colorful day!\n");

    return 0;
}