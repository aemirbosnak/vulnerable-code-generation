//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    int rows, cols;
    int **matrix;
    int i, j, k;
    char c;

    srand(time(NULL));
    rows = rand() % MAX_ROWS + 1;
    cols = rand() % MAX_COLS + 1;

    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the values for the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Enter the number of steps to be taken:\n");
    scanf("%d", &k);

    for (i = 0; i < k; i++) {
        printf("Step %d:\n", i + 1);
        for (j = 0; j < rows; j++) {
            for (c = 0; c < cols; c++) {
                if (matrix[j][c] == 0) {
                    printf(" ");
                } else {
                    printf("%d ", matrix[j][c]);
                }
            }
            printf("\n");
        }
    }

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}