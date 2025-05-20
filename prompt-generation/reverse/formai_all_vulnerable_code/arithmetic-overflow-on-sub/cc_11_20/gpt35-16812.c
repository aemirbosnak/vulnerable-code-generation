//FormAI DATASET v1.0 Category: Random ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n, m, temp, sum_row, sum_col, sum_diag;
    int matrix[10][10];
    srand(time(NULL));

    printf("Enter size of matrix (max 10): ");
    scanf("%d", &n);

    printf("\n");

    // initialize matrix with random values
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // find sum of diagonal elements
    sum_diag = 0;
    for (i = 0; i < n; i++) {
        sum_diag += matrix[i][i];
    }
    printf("Sum of diagonal elements = %d\n", sum_diag);

    // find row-wise totals
    for (i = 0; i < n; i++) {
        sum_row = 0;
        for (j = 0; j < n; j++) {
            sum_row += matrix[i][j];
        }
        printf("Sum of row %d = %d\n", i+1, sum_row);
    }

    // find column-wise totals
    for (j = 0; j < n; j++) {
        sum_col = 0;
        for (i = 0; i < n; i++) {
            sum_col += matrix[i][j];
        }
        printf("Sum of column %d = %d\n", j+1, sum_col);
    }

    // sort matrix diagonally
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if (matrix[j][j] > matrix[j+1][j+1]) {
                temp = matrix[j][j];
                matrix[j][j] = matrix[j+1][j+1];
                matrix[j+1][j+1] = temp;
            }
        }
    }

    printf("\nSorted matrix diagonally\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}