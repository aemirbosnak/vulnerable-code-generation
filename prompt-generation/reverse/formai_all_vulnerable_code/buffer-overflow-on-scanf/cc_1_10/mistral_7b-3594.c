//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: synchronous
#include <stdio.h>
#define ROWS 3
#define COLS 3

int main() {
    int matrix[ROWS][COLS], i, j, sum_row, sum_col, sum_diag1, sum_diag2;

    printf("Enter the elements of the matrix:\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nMatrix elements:\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of each row:\n");

    for (i = 0; i < ROWS; i++) {
        sum_row = 0;
        for (j = 0; j < COLS; j++) {
            sum_row += matrix[i][j];
        }
        printf("Row %d: %d\n", i + 1, sum_row);
    }

    printf("\nSum of each column:\n");

    for (j = 0; j < COLS; j++) {
        sum_col = 0;
        for (i = 0; i < ROWS; i++) {
            sum_col += matrix[i][j];
        }
        printf("Column %d: %d\n", j + 1, sum_col);
    }

    printf("\nSum of diagonal elements:\n");

    sum_diag1 = matrix[0][0] + matrix[1][1] + matrix[2][2];
    sum_diag2 = matrix[0][2] + matrix[1][1] + matrix[2][0];

    printf("Diagonal 1: %d\n", sum_diag1);
    printf("Diagonal 2: %d\n", sum_diag2);

    return 0;
}