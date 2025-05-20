//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ALIVE 'O'
#define DEAD '.'

void initialize_grid(char **grid, int rows, int cols);
void display_grid(char **grid, int rows, int cols);
void update_grid(char **grid, int rows, int cols);
int count_neighbors(char **grid, int row, int col, int rows, int cols);
void free_grid(char **grid, int rows);

int main() {
    int rows, cols, iterations;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    // Allocate memory for the grid
    char **grid = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (char *)malloc(cols * sizeof(char));
    }

    // Initialize the grid
    initialize_grid(grid, rows, cols);
    
    printf("Initial Generation:\n");
    display_grid(grid, rows, cols);

    // Iterate for a number of generations
    for (int i = 0; i < iterations; i++) {
        sleep(1);  // Pause for a second for better visualization
        update_grid(grid, rows, cols);
        printf("Generation %d:\n", i + 1);
        display_grid(grid, rows, cols);
    }

    // Clean up memory
    free_grid(grid, rows);
    return 0;
}

void initialize_grid(char **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = (rand() % 2) ? ALIVE : DEAD;  // Randomly generate initial state
        }
    }
}

void display_grid(char **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void update_grid(char **grid, int rows, int cols) {
    char **new_grid = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        new_grid[i] = (char *)malloc(cols * sizeof(char));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int alive_neighbors = count_neighbors(grid, i, j, rows, cols);
            if (grid[i][j] == ALIVE) {
                new_grid[i][j] = (alive_neighbors < 2 || alive_neighbors > 3) ? DEAD : ALIVE;
            } else {
                new_grid[i][j] = (alive_neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }

    // Copy new grid to the original grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = new_grid[i][j];
        }
        free(new_grid[i]);
    }
    free(new_grid);
}

int count_neighbors(char **grid, int row, int col, int rows, int cols) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;  // Skip the cell itself
            int neighbor_row = row + i;
            int neighbor_col = col + j;
            
            // Check bounds
            if (neighbor_row >= 0 && neighbor_row < rows && neighbor_col >= 0 && neighbor_col < cols) {
                if (grid[neighbor_row][neighbor_col] == ALIVE) {
                    count++;
                }
            }
        }
    }
    return count;
}

void free_grid(char **grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}