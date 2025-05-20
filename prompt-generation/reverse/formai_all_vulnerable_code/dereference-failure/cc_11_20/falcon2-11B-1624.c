//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int width = 50;
    int height = 50;
    int num_generations = 100;
    int i, j;
    int* grid;

    srand(time(NULL));

    grid = (int*)malloc(width * height * sizeof(int));
    for (i = 0; i < width * height; i++) {
        grid[i] = rand() % 2;
    }

    for (i = 0; i < num_generations; i++) {
        for (j = 0; j < width * height; j++) {
            int neighbors = 0;
            int x = j % width;
            int y = j / width;
            if (x > 0 && y > 0) {
                neighbors += grid[j - 1];
            }
            if (x < width - 1) {
                neighbors += grid[j + 1];
            }
            if (y < height - 1) {
                neighbors += grid[j - width];
            }
            if (y > 0) {
                neighbors += grid[j + width];
            }

            if (grid[j] == 1 && (neighbors < 2 || neighbors > 3)) {
                grid[j] = 0;
            } else if (grid[j] == 0 && neighbors == 3) {
                grid[j] = 1;
            }
        }
    }

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            printf("%d ", grid[i * height + j]);
        }
        printf("\n");
    }

    free(grid);
    return 0;
}