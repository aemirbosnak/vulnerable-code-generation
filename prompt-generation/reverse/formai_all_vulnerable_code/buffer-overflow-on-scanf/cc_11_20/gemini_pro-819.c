//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main()
{
    int rows, cols;
    int matrix[MAX_ROWS][MAX_COLS];
    int i, j;

    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Get the matrix elements from the user.
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the original matrix.
    printf("Original matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Find the sum of each row in the matrix.
    int row_sums[MAX_ROWS];
    for (i = 0; i < rows; i++) {
        row_sums[i] = 0;
        for (j = 0; j < cols; j++) {
            row_sums[i] += matrix[i][j];
        }
    }

    // Print the sum of each row in the matrix.
    printf("Sum of each row in the matrix:\n");
    for (i = 0; i < rows; i++) {
        printf("%d ", row_sums[i]);
    }
    printf("\n");

    // Find the sum of each column in the matrix.
    int col_sums[MAX_COLS];
    for (j = 0; j < cols; j++) {
        col_sums[j] = 0;
        for (i = 0; i < rows; i++) {
            col_sums[j] += matrix[i][j];
        }
    }

    // Print the sum of each column in the matrix.
    printf("Sum of each column in the matrix:\n");
    for (j = 0; j < cols; j++) {
        printf("%d ", col_sums[j]);
    }
    printf("\n");

    return 0;
}