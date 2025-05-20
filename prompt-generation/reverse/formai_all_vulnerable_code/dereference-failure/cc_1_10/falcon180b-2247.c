//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 30
#define BORDER 1
#define NUM_DRIPS 500
#define DENSITY 0.5
#define PROBABILITY 0.5

typedef struct {
    int x, y;
} Point;

void init(int **grid) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            grid[i][j] = 0;
        }
    }
}

void createBorder(int **grid) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        grid[i][0] = 1;
        grid[i][WIDTH - 1] = 1;
    }
    for (j = 0; j < WIDTH; j++) {
        grid[0][j] = 1;
        grid[HEIGHT - 1][j] = 1;
    }
}

void percolate(int **grid, int numDrips) {
    int i, j, k, count = 0;
    Point p;
    srand(time(NULL));
    while (count < numDrips) {
        p.x = rand() % HEIGHT;
        p.y = rand() % WIDTH;
        if (grid[p.x][p.y] == 0) {
            grid[p.x][p.y] = 1;
            count++;
        }
    }
}

void display(int **grid) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int **grid;
    grid = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = (int *)malloc(WIDTH * sizeof(int));
    }
    init(grid);
    createBorder(grid);
    percolate(grid, NUM_DRIPS);
    display(grid);
    for (int i = 0; i < HEIGHT; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}