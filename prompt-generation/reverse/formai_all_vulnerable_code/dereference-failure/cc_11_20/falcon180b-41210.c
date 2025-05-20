//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define PROBABILITY 0.5
#define DROPS 1000

int main() {
    int i, j, count = 0;
    int **grid;
    int top, bottom, left, right;
    int x, y;
    int neighbors;
    int threshold = (int)(SIZE * PROBABILITY);

    srand(time(NULL));

    grid = (int **)malloc(SIZE * sizeof(int *));
    for (i = 0; i < SIZE; i++) {
        grid[i] = (int *)malloc(SIZE * sizeof(int));
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    for (i = 0; i < DROPS; i++) {
        x = rand() % SIZE;
        y = rand() % SIZE;

        if (grid[x][y] == 0) {
            grid[x][y] = 1;
            count++;

            top = (x - 1) / 2;
            bottom = (x + 1) / 2;
            left = (y - 1) / 2;
            right = (y + 1) / 2;

            if (top >= 0 && grid[top][y] == 0) {
                grid[top][y] = 1;
            }
            if (bottom < SIZE && grid[bottom][y] == 0) {
                grid[bottom][y] = 1;
            }
            if (left >= 0 && grid[x][left] == 0) {
                grid[x][left] = 1;
            }
            if (right < SIZE && grid[x][right] == 0) {
                grid[x][right] = 1;
            }
        }
    }

    printf("%.2f percent of the grid is wet.\n", (float)count / (SIZE * SIZE) * 100);

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}