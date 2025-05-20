//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    int matrix[ROWS][COLS];

    // Initialize matrix with some values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = 0;
        }
    }

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;

    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;

    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;

    // Print the matrix
    printf("Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Transpose the matrix
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            matrix[j][i] = matrix[i][j];
        }
    }

    // Print the transposed matrix
    printf("Transposed Matrix:\n");
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    // Calculate the sum of each row
    for (int i = 0; i < ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
        printf("Sum of row %d: %d\n", i, sum);
    }

    // Calculate the sum of each column
    for (int j = 0; j < COLS; j++) {
        int sum = 0;
        for (int i = 0; i < ROWS; i++) {
            sum += matrix[i][j];
        }
        printf("Sum of column %d: %d\n", j, sum);
    }

    // Calculate the product of each row
    for (int i = 0; i < ROWS; i++) {
        int product = 1;
        for (int j = 0; j < COLS; j++) {
            product *= matrix[i][j];
        }
        printf("Product of row %d: %d\n", i, product);
    }

    // Calculate the product of each column
    for (int j = 0; j < COLS; j++) {
        int product = 1;
        for (int i = 0; i < ROWS; i++) {
            product *= matrix[i][j];
        }
        printf("Product of column %d: %d\n", j, product);
    }

    return 0;
}