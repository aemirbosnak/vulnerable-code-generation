//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

// Structure to represent a cell in the grid
typedef struct cell {
    int alive;  // Whether the cell is alive or not
    int neighbors;  // Number of living neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to iterate over the grid and update the values
void update_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            // Update the cell's alive status based on its neighbors
            if (grid[i][j].alive && (i + 1 < GRID_SIZE && grid[i + 1][j].alive) &&
                    (i - 1 >= 0 && grid[i - 1][j].alive) && (j + 1 < GRID_SIZE && grid[i][j + 1].alive) && (j - 1 >= 0 && grid[i][j - 1].alive)) {
                // If the cell is alive and has 2 or 3 living neighbors, leave it alive
                grid[i][j].alive = 1;
            } else if (grid[i][j].alive && (i + 1 < GRID_SIZE && !grid[i + 1][j].alive) && (i - 1 >= 0 && !grid[i - 1][j].alive) && (j + 1 < GRID_SIZE && !grid[i][j + 1].alive) && (j - 1 >= 0 && !grid[i][j - 1].alive)) {
                // If the cell is alive and has no living neighbors, die
                grid[i][j].alive = 0;
            } else {
                // If the cell is dead and has 3 living neighbors, come to life
                if (grid[i][j].alive == 0 && (i + 1 < GRID_SIZE && grid[i + 1][j].alive) && (i - 1 >= 0 && grid[i - 1][j].alive) && (j + 1 < GRID_SIZE && grid[i][j + 1].alive) && (j - 1 >= 0 && grid[i][j - 1].alive)) {
                    grid[i][j].alive = 1;
                }
            }
            grid[i][j].neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) continue;
                    if (grid[i + k][j + l].alive) {
                        grid[i][j].neighbors++;
                    }
                }
            }
        }
    }
}

// Function to print the grid
void print_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    cell_t** grid = malloc(GRID_SIZE * sizeof(cell_t *));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = malloc(GRID_SIZE * sizeof(cell_t));
    }
    init_grid(grid);
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        print_grid(grid);
    }
    return 0;
}