//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 30
#define P 0.5
#define N 1000

int main() {
    int i, j;
    int **grid;
    int top = 0, bottom = HEIGHT - 1;
    int left = 0, right = WIDTH - 1;
    int count = 0;
    srand(time(NULL));

    grid = (int **)malloc(HEIGHT * sizeof(int *));
    for (i = 0; i < HEIGHT; i++) {
        grid[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    for (i = 0; i < N; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        if (grid[y][x] == 0) {
            grid[y][x] = 1;
            count++;
        }
    }

    printf("Initial grid:\n");
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    int open = 0;
    int closed = 0;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 1) {
                open += 1;
            } else {
                closed += 1;
            }
        }
    }

    printf("Open sites: %d, Closed sites: %d\n", open, closed);

    return 0;
}