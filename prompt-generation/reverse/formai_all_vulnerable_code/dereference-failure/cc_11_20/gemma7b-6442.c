//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int main() {
    int **grid = NULL;
    int **perm = NULL;
    int i, j, k, r, s;

    // Allocate memory
    grid = (int **)malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++) {
        grid[i] = (int *)malloc(COLS * sizeof(int));
    }

    perm = (int **)malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++) {
        perm[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize grid and perm
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = 0;
            perm[i][j] = 0;
        }
    }

    // Simulate Percolation
    s = time(NULL);
    for (k = 0; k < 10000; k++) {
        r = rand() % ROWS;
        i = rand() % COLS;
        if (grid[r][i] == 0 && perm[r][i] == 0) {
            grid[r][i] = 1;
            perm[r][i] = 1;
        }
    }

    // Print the result
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);

    for (i = 0; i < ROWS; i++) {
        free(perm[i]);
    }
    free(perm);

    return 0;
}