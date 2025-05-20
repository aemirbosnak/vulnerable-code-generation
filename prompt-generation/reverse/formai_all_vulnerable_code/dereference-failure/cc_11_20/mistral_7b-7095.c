//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#define ROWS 21
#define COLS 21

int main() {
    int i = 0, j = 0, count = 0, n = ROWS * COLS, num = 1;
    int top = 0, bottom = ROWS - 1, left = 0, right = COLS - 1;

    int **matrix = malloc(sizeof(int *) * ROWS);
    for (i = 0; i < ROWS; i++) {
        matrix[i] = calloc(COLS, sizeof(int));
    }

    while (count < n) {
        // Print current row
        for (j = left; j <= right; j++) {
            matrix[top][j] = num++;
            count++;
        }
        top++;

        // Print current column
        for (j = top; j <= bottom; j++) {
            matrix[j][right] = num++;
            count++;
        }
        right--;

        // Print remaining rows reverse
        if (top <= bottom) {
            for (j = right; j >= left; j--) {
                matrix[bottom][j] = num++;
                count++;
            }
            bottom--;
        }

        // Print remaining columns reverse
        if (left < right) {
            for (j = bottom; j >= top; j--) {
                matrix[j][left] = num++;
                count++;
            }
            left++;
        }
    }

    // Print the matrix
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}