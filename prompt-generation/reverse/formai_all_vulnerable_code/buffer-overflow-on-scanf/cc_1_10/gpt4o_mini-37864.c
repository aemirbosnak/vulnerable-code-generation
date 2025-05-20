//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ALIVE 'O'
#define DEAD '.'

// Function to create and initialize the grid
char **create_grid(int rows, int cols) {
    char **grid = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (char *)malloc(cols * sizeof(char));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = DEAD; // Initialize all cells to DEAD
        }
    }
    return grid;
}

// Function to free the grid memory
void free_grid(char **grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

// Function to print the grid
void print_grid(char **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to count alive neighbors
int count_neighbors(char **grid, int x, int y, int rows, int cols) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int new_x = x + i;
            int new_y = y + j;
            if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
                if (grid[new_x][new_y] == ALIVE) {
                    count++;
                }
            }
        }
    }
    return count;
}

// Function to update the grid to the next generation
void update_grid(char **grid, int rows, int cols) {
    char **new_grid = create_grid(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int alive_neighbors = count_neighbors(grid, i, j, rows, cols);
            if (grid[i][j] == ALIVE) {
                if (alive_neighbors < 2 || alive_neighbors > 3) {
                    new_grid[i][j] = DEAD; // Underpopulation or overpopulation
                } else {
                    new_grid[i][j] = ALIVE; // Lives to the next generation
                }
            } else {
                if (alive_neighbors == 3) {
                    new_grid[i][j] = ALIVE; // Reproduction
                } else {
                    new_grid[i][j] = DEAD; // Stays dead
                }
            }
        }
    }
    // Copy the new grid back to the current grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
    free_grid(new_grid, rows);
}

int main() {
    int rows, cols, iterations;

    // User input for grid size and iterations
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    printf("Enter number of iterations: ");
    scanf("%d", &iterations);

    // Create the grid
    char **grid = create_grid(rows, cols);

    // Randomly populate the grid
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = (rand() % 2) ? ALIVE : DEAD;
        }
    }

    // Game loop for iterations
    for (int iter = 0; iter < iterations; iter++) {
        print_grid(grid, rows, cols);
        printf("Iteration: %d\n", iter + 1);
        update_grid(grid, rows, cols);
        usleep(200000); // Sleep for 200 milliseconds for better visual
        printf("\033[H\033[J"); // Clear screen
    }

    // Free the grid memory
    free_grid(grid, rows);
    
    return 0;
}