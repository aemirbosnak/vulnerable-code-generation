//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define GRID_WIDTH 50
#define GRID_HEIGHT 50
#define CELL_SIZE 10

// Define the cell structure
typedef struct {
    int x;
    int y;
    int state;
} cell_t;

// Define the grid structure
typedef struct {
    cell_t** cells;
    int width;
    int height;
} grid_t;

// Initialize the grid
void init_grid(grid_t* grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid->cells[i][j].x = i * CELL_SIZE;
            grid->cells[i][j].y = j * CELL_SIZE;
            grid->cells[i][j].state = 0;
        }
    }
}

// Print the grid
void print_grid(grid_t* grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid->cells[i][j].state == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Update the grid
void update_grid(grid_t* grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            int neighbors = 0;
            if (i > 0 && grid->cells[i - 1][j].state == 1) {
                neighbors++;
            }
            if (i < GRID_SIZE - 1 && grid->cells[i + 1][j].state == 1) {
                neighbors++;
            }
            if (j > 0 && grid->cells[i][j - 1].state == 1) {
                neighbors++;
            }
            if (j < GRID_SIZE - 1 && grid->cells[i][j + 1].state == 1) {
                neighbors++;
            }
            if (grid->cells[i][j].state == 1) {
                if (neighbors < 2) {
                    grid->cells[i][j].state = 0;
                } else if (neighbors > 3) {
                    grid->cells[i][j].state = 0;
                }
            } else {
                if (neighbors == 3) {
                    grid->cells[i][j].state = 1;
                }
            }
        }
    }
}

// Main function
int main() {
    grid_t grid;
    grid.width = GRID_WIDTH;
    grid.height = GRID_HEIGHT;
    grid.cells = (cell_t**)malloc(GRID_SIZE * sizeof(cell_t*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid.cells[i] = (cell_t*)malloc(GRID_SIZE * sizeof(cell_t));
    }

    srand(time(NULL));
    init_grid(&grid);

    while (1) {
        print_grid(&grid);
        update_grid(&grid);
        sleep(1);
    }

    return 0;
}