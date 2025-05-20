//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ALIVE 1
#define DEAD 0

void initialize_grid(int **grid, int rows, int cols);
void print_grid(int **grid, int rows, int cols);
void update_grid(int **grid, int **new_grid, int rows, int cols);
int count_neighbors(int **grid, int x, int y, int rows, int cols);

int main() {
    int rows, cols, iterations;

    printf("Welcome to the Game of Life!\n");
    printf("Enter the number of rows in the grid (e.g., 10): ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the grid (e.g., 10): ");
    scanf("%d", &cols);
    printf("Enter the number of iterations to run the simulation (e.g., 10): ");
    scanf("%d", &iterations);

    // Allocate memory for grid
    int **grid = (int **)malloc(rows * sizeof(int *));
    int **new_grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
        new_grid[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the grid with random alive/dead cells
    initialize_grid(grid, rows, cols);

    // Main simulation loop
    for (int i = 0; i < iterations; i++) {
        printf("\nIteration %d:\n", i + 1);
        print_grid(grid, rows, cols);
        update_grid(grid, new_grid, rows, cols);

        // Swap the grids
        int **temp = grid;
        grid = new_grid;
        new_grid = temp;

        // Sleep for a bit to visualize the changes
        usleep(500000);  // 500 ms
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
        free(new_grid[i]);
    }
    free(grid);
    free(new_grid);

    printf("Simulation finished. Thanks for playing!\n");
    return 0;
}

void initialize_grid(int **grid, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2;  // Randomly set cells to ALIVE or DEAD
        }
    }
}

void print_grid(int **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == ALIVE) {
                printf("■ ");
            } else {
                printf("□ ");
            }
        }
        printf("\n");
    }
}

void update_grid(int **grid, int **new_grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = count_neighbors(grid, i, j, rows, cols);
            
            // Apply the rules of Conway's Game of Life
            if (grid[i][j] == ALIVE) {
                new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? ALIVE : DEAD;
            } else {
                new_grid[i][j] = (neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }
}

int count_neighbors(int **grid, int x, int y, int rows, int cols) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int new_x = x + i;
            int new_y = y + j;
            if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
                count += grid[new_x][new_y];
            }
        }
    }
    return count;
}