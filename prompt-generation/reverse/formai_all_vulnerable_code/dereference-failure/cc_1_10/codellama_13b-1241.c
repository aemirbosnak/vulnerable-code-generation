//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: multi-threaded
// Game of Life program in a multi-threaded style
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure for thread arguments
typedef struct {
    int rows;
    int cols;
    int** grid;
} thread_arg;

// Function to print the grid
void print_grid(int rows, int cols, int** grid) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the next generation
void calculate_next_generation(int rows, int cols, int** grid, int** new_grid) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int live_neighbors = 0;
            if (i > 0) {
                if (j > 0) {
                    live_neighbors += grid[i - 1][j - 1];
                }
                live_neighbors += grid[i - 1][j];
                if (j < cols - 1) {
                    live_neighbors += grid[i - 1][j + 1];
                }
            }
            if (j > 0) {
                live_neighbors += grid[i][j - 1];
            }
            if (j < cols - 1) {
                live_neighbors += grid[i][j + 1];
            }
            if (i < rows - 1) {
                if (j > 0) {
                    live_neighbors += grid[i + 1][j - 1];
                }
                live_neighbors += grid[i + 1][j];
                if (j < cols - 1) {
                    live_neighbors += grid[i + 1][j + 1];
                }
            }
            if (grid[i][j] == 1) {
                if (live_neighbors < 2) {
                    new_grid[i][j] = 0;
                } else if (live_neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else {
                if (live_neighbors == 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = 0;
                }
            }
        }
    }
}

// Function to run the game of life
void run_game_of_life(int rows, int cols, int** grid, int** new_grid) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    while (1) {
        calculate_next_generation(rows, cols, grid, new_grid);
        print_grid(rows, cols, new_grid);
        sleep(1);
    }
}

// Main function
int main() {
    int rows = 10;
    int cols = 10;
    int** grid = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc(cols * sizeof(int));
    }
    int** new_grid = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        new_grid[i] = malloc(cols * sizeof(int));
    }
    run_game_of_life(rows, cols, grid, new_grid);
    return 0;
}