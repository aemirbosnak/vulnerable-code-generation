//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int width, height;
    width = 50;
    height = 50;

    srand(time(NULL));

    int** grid = (int**)malloc(sizeof(int*) * width);
    for (int i = 0; i < width; i++) {
        grid[i] = (int*)malloc(sizeof(int) * height);
        for (int j = 0; j < height; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 20; i++) {
        int liveNeighbors = 0;
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < height; k++) {
                if (grid[i][j] == grid[i][k] && grid[i][j] == 1) {
                    liveNeighbors++;
                }
            }
        }

        if (grid[i][i] == 1 && liveNeighbors < 2) {
            grid[i][i] = 0;
        } else if (grid[i][i] == 0 && liveNeighbors == 3) {
            grid[i][i] = 1;
        }

        for (int j = 0; j < width; j++) {
            for (int k = 0; k < height; k++) {
                if (grid[j][k] == grid[i][j] && grid[j][k] == 1) {
                    grid[j][k] = 0;
                }
            }
        }
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    free(grid[0]);
    free(grid);

    return 0;
}