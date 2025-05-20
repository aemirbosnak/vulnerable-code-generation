//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, j, k, rows, columns, matrix[10][10], transpose[10][10], sum = 0;

    printf("Welcome to the Matrix Madness program!\n");

    printf("Enter the number of rows and columns for your matrix: ");
    scanf("%d %d", &rows, &columns);

    if (rows < 1 || columns < 1) {
        printf("Oops! You cannot create a matrix with less than 1 row or 1 column.\n");
        exit(0);
    }

    printf("Enter your matrix elements one by one: \n");

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < columns; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\n\nHere is your matrix:\n");

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < columns; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n\nCalculating the transpose...\n");

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < columns; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\n\nHere is the transpose of your matrix:\n");

    for (i = 0; i < columns; ++i) {
        for (j = 0; j < rows; ++j) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    printf("\n\nCalculating the sum of diagonal elements...\n");

    for (i = 0; i < rows && i < columns; ++i) {
        sum += matrix[i][i];
    }

    printf("\n\nThe sum of diagonal elements is: %d\n", sum);

    printf("\n\nCalculating the product of matrices...\n");

    int m, n, p, q, multiply[10][10];

    printf("\nEnter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &m, &n);

    if (columns != m) {
        printf("Oops! The number of columns in the first matrix should be equal to the number of rows in the second matrix.\n");
        exit(0);
    }

    int second_matrix[10][10];

    printf("Enter the elements of the second matrix one by one:\n");

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &second_matrix[i][j]);
        }
    }

    printf("\n\nHere is your second matrix:\n");

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%d ", second_matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < n; ++j) {
            multiply[i][j] = 0;
        }
    }

    printf("\n\nMultiplying the matrices...\n");

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < n; ++j) {
            for (k = 0; k < columns; ++k) {
                multiply[i][j] += matrix[i][k] * second_matrix[k][j];
            }
        }
    }

    printf("\n\nThe product of matrices is:\n");

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%d ", multiply[i][j]);
        }
        printf("\n");
    }

    printf("\n\nThanks for using the Matrix Madness program! Have a good one!\n");

    return 0;
}