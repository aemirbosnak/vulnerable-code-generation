//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main() {
    int width = 30;
    int height = 30;
    int cells = width * height;
    int *grid;
    grid = (int *)malloc(cells * sizeof(int));
    
    for (int i = 0; i < cells; i++) {
        grid[i] = 0;
    }
    
    int generation = 0;
    while (1) {
        printf("Generation %d\n", generation);
        printf("-----------------\n");
        
        for (int i = 0; i < cells; i++) {
            if (grid[i] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
        
        int newCells = 0;
        for (int i = 0; i < cells; i++) {
            int neighbors = 0;
            int x = i % width;
            int y = i / width;
            for (int j = -1; j <= 1; j++) {
                for (int k = -1; k <= 1; k++) {
                    if (x + j >= 0 && x + j < width && y + k >= 0 && y + k < height) {
                        if (grid[i + j + k * width] == 1) {
                            neighbors++;
                        }
                    }
                }
            }
            if (grid[i] == 1 && neighbors < 2 || neighbors > 3) {
                grid[i] = 0;
            } else if (grid[i] == 0 && neighbors == 3) {
                grid[i] = 1;
                newCells++;
            }
        }
        generation++;
        if (newCells == 0) {
            break;
        }
    }
    free(grid);
    return 0;
}