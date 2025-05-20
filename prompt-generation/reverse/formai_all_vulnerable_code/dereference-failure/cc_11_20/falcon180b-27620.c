//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 30
#define SITE (rand() % 2)

int main() {
    int i, j;
    int **grid;
    int top = 0;
    int bottom = HEIGHT - 1;
    int left = 0;
    int right = WIDTH - 1;

    srand(time(NULL));

    grid = (int **) malloc(HEIGHT * sizeof(int *));
    for (i = 0; i < HEIGHT; i++) {
        grid[i] = (int *) malloc(WIDTH * sizeof(int));
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            grid[i][j] = 0;
        }
    }

    grid[0][0] = 1;
    grid[HEIGHT - 1][WIDTH - 1] = 1;
    grid[0][WIDTH - 1] = 1;
    grid[HEIGHT - 1][0] = 1;

    int count = 0;

    while (count < 10000) {
        int x = rand() % HEIGHT;
        int y = rand() % WIDTH;

        if (x == 0 || x == HEIGHT - 1 || y == 0 || y == WIDTH - 1) {
            continue;
        }

        if (grid[x][y] == 0 && grid[x - 1][y] == 1) {
            grid[x][y] = 1;
            count++;
        }
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < HEIGHT; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}