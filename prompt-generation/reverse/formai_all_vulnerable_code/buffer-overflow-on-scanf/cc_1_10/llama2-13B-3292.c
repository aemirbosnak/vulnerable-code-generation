//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a cell in the grid
typedef struct cell {
    int alive;    // Whether the cell is alive or not
    int births;   // Number of births that have occurred in the cell
    int deaths;  // Number of deaths that have occurred in the cell
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].births = 0;
            grid[i][j].deaths = 0;
        }
    }
}

// Function to apply the Game of Life rules to the grid
void apply_rules(cell_t** grid, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            // Check for births
            if (grid[i][j].births > 0) {
                // Increment alive count
                grid[i][j].alive = 1;
                // Decrement births count
                grid[i][j].births--;
            }
            // Check for deaths
            if (grid[i][j].deaths > 0) {
                // Decrement alive count
                grid[i][j].alive = 0;
                // Increment deaths count
                grid[i][j].deaths--;
            }
            // Check for survival
            if (grid[i][j].alive) {
                // Increment alive count for the next generation
                grid[i][j].alive++;
            }
        }
    }
}

// Function to print the final state of the grid
void print_grid(cell_t** grid, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    cell_t** grid;
    srand(time(NULL));

    // Get the number of rows and columns from the user
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    // Allocate memory for the grid
    grid = (cell_t**) malloc(rows * sizeof(cell_t*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (cell_t*) malloc(cols * sizeof(cell_t));
    }

    // Initialize the grid with random values
    init_grid(grid, rows, cols);

    // Run the Game of Life for 10 generations
    for (int gen = 0; gen < 10; gen++) {
        apply_rules(grid, rows, cols);
    }

    // Print the final state of the grid
    print_grid(grid, rows, cols);

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}