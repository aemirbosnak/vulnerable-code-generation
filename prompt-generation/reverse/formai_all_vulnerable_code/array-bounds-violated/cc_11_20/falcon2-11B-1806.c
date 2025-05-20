//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: romantic
#include <stdio.h>

#define ROWS 4
#define COLS 3

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nMultiplying the matrix by itself...\n");
    int product[ROWS][COLS] = {0};
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int sum = 0;
            for (int k = 0; k < COLS; k++) {
                sum += matrix[i][k] * matrix[k][j];
            }
            product[i][j] = sum;
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    printf("\nCalculating the transpose of the matrix...\n");
    int transpose[COLS][ROWS] = {0};
    for (i = 0; i < COLS; i++) {
        for (j = 0; j < ROWS; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    for (i = 0; i < COLS; i++) {
        for (j = 0; j < ROWS; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    printf("\nPerforming row reduction on the transpose matrix...\n");
    for (i = 0; i < ROWS; i++) {
        int max_index = i;
        int max_value = transpose[i][i];
        for (int j = i + 1; j < ROWS; j++) {
            if (transpose[j][i] > max_value) {
                max_index = j;
                max_value = transpose[j][i];
            }
        }

        int temp = transpose[max_index][i];
        transpose[max_index][i] = transpose[i][i];
        transpose[i][i] = temp;

        for (int k = i + 1; k < ROWS; k++) {
            int temp = transpose[i][k];
            transpose[i][k] = transpose[k][i];
            transpose[k][i] = temp;
        }
    }

    for (i = 0; i < COLS; i++) {
        for (j = 0; j < ROWS; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}