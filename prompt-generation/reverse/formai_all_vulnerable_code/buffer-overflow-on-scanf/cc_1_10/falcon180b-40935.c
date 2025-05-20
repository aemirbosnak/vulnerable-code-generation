//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define NEIGHBORS_COUNT 9
#define DEAD_CELL '.'
#define LIVE_CELL '*'

void init_grid(int grid[HEIGHT][WIDTH], int seed) {
    srand(seed);
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid(int grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%c", grid[i][j]? LIVE_CELL : DEAD_CELL);
        }
        printf("\n");
    }
}

void count_neighbors(int grid[HEIGHT][WIDTH], int x, int y, int neighbors[NEIGHBORS_COUNT]) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int nx = (x + i + WIDTH) % WIDTH;
            int ny = (y + j + HEIGHT) % HEIGHT;
            neighbors[count++] = grid[ny][nx];
        }
    }
}

void next_generation(int grid[HEIGHT][WIDTH]) {
    int new_grid[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            int neighbors_count = 0;
            count_neighbors(grid, i, j, new_grid[i][j]);
            if (grid[i][j]) {
                if (neighbors_count < 2 || neighbors_count > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else {
                if (neighbors_count == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int seed;
    printf("Enter the seed: ");
    scanf("%d", &seed);
    int grid[HEIGHT][WIDTH];
    init_grid(grid, seed);
    int generation = 0;
    while (1) {
        printf("Generation %d:\n", ++generation);
        print_grid(grid);
        next_generation(grid);
        usleep(100000);
    }
    return 0;
}