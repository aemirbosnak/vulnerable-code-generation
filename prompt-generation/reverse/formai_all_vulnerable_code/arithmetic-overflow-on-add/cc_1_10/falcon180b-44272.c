//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void print_matrix(int matrix[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int sum_matrix[ROWS][COLS];

    // Matrix addition
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Sum of matrices:\n");
    print_matrix(sum_matrix);

    // Matrix subtraction
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    printf("\nDifference of matrices:\n");
    print_matrix(sum_matrix);

    // Matrix multiplication
    int product_matrix[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < COLS; k++) {
                product_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("\nProduct of matrices:\n");
    print_matrix(product_matrix);

    return 0;
}