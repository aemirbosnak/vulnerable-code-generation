//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
    //initialize variables
    int grid_size = 10;
    int num_perc = 0;
    int num_cells = grid_size * grid_size;
    int **grid = malloc(grid_size * sizeof(int *));
    for (int i = 0; i < grid_size; i++) {
        grid[i] = malloc(grid_size * sizeof(int));
    }

    //initialize grid
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            grid[i][j] = 0;
        }
    }

    //initialize top row
    for (int j = 0; j < grid_size; j++) {
        grid[0][j] = 1;
    }

    //initialize percolation
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            if (grid[i][j] == 1) {
                num_perc++;
            }
        }
    }

    //print initial grid
    printf("Initial Grid:\n");
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    //print number of percolating cells
    printf("\nNumber of Percolating Cells: %d\n", num_perc);

    //free memory
    for (int i = 0; i < grid_size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}