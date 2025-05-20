//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 30
#define P_DENSITY 0.5
#define W_DENSITY 0.5

int main(void) {
    int i, j, k;
    int **grid;
    int top = 0;
    int bottom = HEIGHT - 1;
    int left = 0;
    int right = WIDTH - 1;
    int num_filled;

    srand(time(NULL));

    grid = malloc(HEIGHT * sizeof(int *));
    for (i = 0; i < HEIGHT; i++) {
        grid[i] = malloc(WIDTH * sizeof(int));
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == top || i == bottom) {
                grid[i][j] = 1;
            } else if (j == left || j == right) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 0) {
                k = rand() % 100;
                if (k < P_DENSITY * 100) {
                    grid[i][j] = 1;
                }
            }
        }
    }

    num_filled = 0;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 1) {
                num_filled++;
            }
        }
    }

    printf("Initial grid:\n");
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("Number of filled cells: %d\n", num_filled);

    return 0;
}