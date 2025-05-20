//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_VAL 100

int main() {
    int rows, cols, val;
    int **matrix;
    int sum = 0;
    int i, j;
    int count = 0;

    srand(time(NULL));
    rows = rand() % (MAX_ROWS + 1);
    cols = rand() % (MAX_COLS + 1);
    val = rand() % (MAX_VAL + 1);

    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % (MAX_VAL + 1);
            sum += matrix[i][j];
        }
    }

    printf("The sum of all elements in the matrix is: %d\n", sum);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] == val) {
                count++;
            }
        }
    }

    printf("The number of occurrences of %d in the matrix is: %d\n", val, count);

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}