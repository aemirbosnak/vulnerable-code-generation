//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int rows1, cols1, rows2, cols2, i, j, k;
    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];

    // Get dimensions of first matrix
    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    // Get dimensions of second matrix
    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Check if matrices can be added/subtracted
    if (rows1!= rows2 || cols1!= cols2) {
        printf("Matrices cannot be added/subtracted.\n");
        return 0;
    }

    // Get elements of first matrix
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Get elements of second matrix
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform matrix addition
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print result of matrix addition
    printf("Result of matrix addition:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Perform matrix subtraction
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    // Print result of matrix subtraction
    printf("\nResult of matrix subtraction:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}