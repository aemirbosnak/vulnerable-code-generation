//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j, k, count = 0, max_count = 0, max_row = 0, max_col = 0;
    int **matrix;

    srand(time(NULL));
    rows = rand() % 21 + 5;
    cols = rand() % 21 + 5;

    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 101;
        }
    }

    printf("Random Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            count = 1;
            if (i > 0 && matrix[i - 1][j] == matrix[i][j]) {
                count++;
            }
            if (j > 0 && matrix[i][j - 1] == matrix[i][j]) {
                count++;
            }
            if (i < rows - 1 && matrix[i + 1][j] == matrix[i][j]) {
                count++;
            }
            if (j < cols - 1 && matrix[i][j + 1] == matrix[i][j]) {
                count++;
            }

            if (count > max_count) {
                max_count = count;
                max_row = i;
                max_col = j;
            }
        }
    }

    printf("\nLargest Pattern:\n");
    for (i = max_row - 1; i < max_row + 1; i++) {
        for (j = max_col - 1; j < max_col + 1; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}