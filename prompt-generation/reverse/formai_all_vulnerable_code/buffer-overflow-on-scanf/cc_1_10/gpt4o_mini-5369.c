//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ALIVE 'O'
#define DEAD '.'

// Function prototypes
void initialize_grid(char **grid, int rows, int cols);
void display_grid(char **grid, int rows, int cols);
int count_neighbors(char **grid, int x, int y, int rows, int cols);
void update_grid(char **grid, char **temp_grid, int rows, int cols);
void free_grid(char **grid, int rows);

int main() {
    int rows, cols, generations;

    printf("Welcome to the Game of Life!\n");
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    printf("Enter number of generations to run: ");
    scanf("%d", &generations);

    // Allocate memory for the grid
    char **grid = (char **)malloc(rows * sizeof(char *));
    char **temp_grid = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (char *)malloc(cols * sizeof(char));
        temp_grid[i] = (char *)malloc(cols * sizeof(char));
    }

    initialize_grid(grid, rows, cols);
    display_grid(grid, rows, cols);
    
    // Run the game for the specified generations
    for (int gen = 0; gen < generations; gen++) {
        sleep(1); // Pause for a second to view each generation
        update_grid(grid, temp_grid, rows, cols);
        display_grid(grid, rows, cols);

        // Swap grids
        char **swap = grid;
        grid = temp_grid;
        temp_grid = swap;
    }

    // Free memory
    free_grid(grid, rows);
    free_grid(temp_grid, rows);
    
    printf("Game Over!\n");
    return 0;
}

void initialize_grid(char **grid, int rows, int cols) {
    printf("Initialize grid with live cells (e.g., 1 for alive, 0 for dead):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char input;
            scanf(" %c", &input);
            grid[i][j] = (input == '1') ? ALIVE : DEAD;
        }
    }
}

void display_grid(char **grid, int rows, int cols) {
    printf("\033[H\033[J"); // Clear the screen
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(char **grid, int x, int y, int rows, int cols) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int ni = x + i, nj = y + j;
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                if (grid[ni][nj] == ALIVE) {
                    count++;
                }
            }
        }
    }
    return count;
}

void update_grid(char **grid, char **temp_grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = count_neighbors(grid, i, j, rows, cols);
            if (grid[i][j] == ALIVE) {
                temp_grid[i][j] = (neighbors < 2 || neighbors > 3) ? DEAD : ALIVE;
            } else {
                temp_grid[i][j] = (neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }
}

void free_grid(char **grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}