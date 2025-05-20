//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 30
#define SITE (ROW * COL)
#define DROP 0
#define FULL 1
#define EMPTY 2
#define TOP 0
#define BOTTOM 1
#define LEFT 2
#define RIGHT 3

int **create_grid(int state) {
    int **grid = (int **)malloc(ROW * sizeof(int *));
    for (int i = 0; i < ROW; i++) {
        grid[i] = (int *)malloc(COL * sizeof(int));
        for (int j = 0; j < COL; j++) {
            grid[i][j] = state;
        }
    }
    return grid;
}

void print_grid(int **grid) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int check_neighbors(int **grid, int x, int y) {
    int count = 0;
    if (y > TOP && grid[y - 1][x] == FULL)
        count++;
    if (y < BOTTOM - 1 && grid[y + 1][x] == FULL)
        count++;
    if (x > LEFT && grid[y][x - 1] == FULL)
        count++;
    if (x < RIGHT - 1 && grid[y][x + 1] == FULL)
        count++;
    return count;
}

void percolate(int **grid) {
    int x, y;
    srand(time(NULL));
    for (y = 0; y < ROW; y++) {
        for (x = 0; x < COL; x++) {
            if (grid[y][x] == FULL) {
                int neighbors = check_neighbors(grid, x, y);
                if (neighbors == 1) {
                    grid[y][x] = DROP;
                }
            }
        }
    }
}

int main() {
    int **grid = create_grid(EMPTY);
    print_grid(grid);
    percolate(grid);
    print_grid(grid);
    return 0;
}