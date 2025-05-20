//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: distributed
// Game of Life in a distributed style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define WIDTH 100
#define HEIGHT 100

// Define the cell structure
typedef struct {
    int x;
    int y;
    int alive;
} Cell;

// Define the grid structure
typedef struct {
    Cell **cells;
    int width;
    int height;
} Grid;

// Function to create a new grid
Grid *create_grid(int width, int height) {
    Grid *grid = malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->cells = malloc(sizeof(Cell *) * width * height);
    for (int i = 0; i < width * height; i++) {
        grid->cells[i] = malloc(sizeof(Cell));
        grid->cells[i]->x = i % width;
        grid->cells[i]->y = i / width;
        grid->cells[i]->alive = 0;
    }
    return grid;
}

// Function to free a grid
void free_grid(Grid *grid) {
    for (int i = 0; i < grid->width * grid->height; i++) {
        free(grid->cells[i]);
    }
    free(grid->cells);
    free(grid);
}

// Function to display the grid
void display_grid(Grid *grid) {
    for (int y = 0; y < grid->height; y++) {
        for (int x = 0; x < grid->width; x++) {
            Cell *cell = grid->cells[y * grid->width + x];
            printf("%c ", cell->alive ? 'O' : ' ');
        }
        printf("\n");
    }
}

// Function to update the grid
void update_grid(Grid *grid) {
    // Count the number of alive neighbors for each cell
    int **neighbors = malloc(sizeof(int *) * grid->width * grid->height);
    for (int y = 0; y < grid->height; y++) {
        for (int x = 0; x < grid->width; x++) {
            neighbors[y * grid->width + x] = malloc(sizeof(int) * 8);
            int count = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    int neighbor_x = (x + dx + grid->width) % grid->width;
                    int neighbor_y = (y + dy + grid->height) % grid->height;
                    Cell *neighbor = grid->cells[neighbor_y * grid->width + neighbor_x];
                    neighbors[y * grid->width + x][count] = neighbor->alive;
                    count++;
                }
            }
        }
    }

    // Update the grid based on the number of alive neighbors
    for (int y = 0; y < grid->height; y++) {
        for (int x = 0; x < grid->width; x++) {
            Cell *cell = grid->cells[y * grid->width + x];
            int count = 0;
            for (int i = 0; i < 8; i++) {
                count += neighbors[y * grid->width + x][i];
            }
            if (cell->alive) {
                if (count < 2 || count > 3) {
                    cell->alive = 0;
                }
            } else {
                if (count == 3) {
                    cell->alive = 1;
                }
            }
        }
    }

    // Free the neighbors array
    for (int y = 0; y < grid->height; y++) {
        for (int x = 0; x < grid->width; x++) {
            free(neighbors[y * grid->width + x]);
        }
    }
    free(neighbors);
}

// Function to run the game of life
void run_game_of_life(Grid *grid) {
    while (1) {
        update_grid(grid);
        display_grid(grid);
        sleep(1);
    }
}

int main() {
    Grid *grid = create_grid(WIDTH, HEIGHT);
    run_game_of_life(grid);
    free_grid(grid);
    return 0;
}