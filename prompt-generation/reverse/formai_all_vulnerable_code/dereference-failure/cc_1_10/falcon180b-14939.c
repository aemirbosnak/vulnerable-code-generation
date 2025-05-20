//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define POROSITY 0.5
#define PIPE_COLOR '|'
#define WATER_COLOR '~'

int main() {
    int width = WIDTH;
    int height = HEIGHT;
    int** grid = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            grid[i][j] = 0;
        }
    }

    // Randomly add pipes to the grid
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int x = rand() % height;
        int y = rand() % width;
        grid[x][y] = 1;
    }

    // Simulate water percolation
    int num_droplets = 0;
    while (num_droplets < WIDTH * HEIGHT) {
        int x = rand() % height;
        int y = rand() % width;
        if (grid[x][y] == 0) {
            grid[x][y] = 2;
            num_droplets++;
        }
    }

    // Print the grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == 0) {
                printf(" ");
            } else if (grid[i][j] == 1) {
                printf(PIPE_COLOR);
            } else {
                printf(WATER_COLOR);
            }
        }
        printf("\n");
    }

    return 0;
}