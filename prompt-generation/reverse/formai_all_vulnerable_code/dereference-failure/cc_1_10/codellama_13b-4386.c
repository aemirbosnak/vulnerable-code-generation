//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: Cryptic
/*
 * C Game of Life in Cryptic style
 *
 * Usage: ./life <number_of_iterations>
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define GRID_SIZE 10
#define DEAD 0
#define ALIVE 1

// Grid type
typedef struct {
    int grid[GRID_SIZE][GRID_SIZE];
} grid_t;

// Print grid function
void print_grid(grid_t *grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid->grid[i][j] == ALIVE ? '*' : ' ');
        }
        printf("\n");
    }
}

// Update grid function
void update_grid(grid_t *grid) {
    grid_t next_grid = {0};
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int alive_neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    if (grid->grid[i + x][j + y] == ALIVE) alive_neighbors++;
                }
            }
            if (grid->grid[i][j] == ALIVE) {
                if (alive_neighbors == 2 || alive_neighbors == 3) {
                    next_grid.grid[i][j] = ALIVE;
                } else {
                    next_grid.grid[i][j] = DEAD;
                }
            } else {
                if (alive_neighbors == 3) {
                    next_grid.grid[i][j] = ALIVE;
                } else {
                    next_grid.grid[i][j] = DEAD;
                }
            }
        }
    }
    memcpy(grid, &next_grid, sizeof(grid_t));
}

// Main function
int main(int argc, char *argv[]) {
    // Initialize grid
    grid_t grid = {0};
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid.grid[i][j] = DEAD;
        }
    }

    // Set starting position
    grid.grid[GRID_SIZE / 2][GRID_SIZE / 2] = ALIVE;

    // Set number of iterations
    int iterations = atoi(argv[1]);

    // Print initial grid
    print_grid(&grid);

    // Update grid
    for (int i = 0; i < iterations; i++) {
        update_grid(&grid);
        print_grid(&grid);
    }

    return 0;
}