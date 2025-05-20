//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_SIZE 100

void display_grid(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("\033[H\033[J"); // Clear the console
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                printf("■ ");
            } else {
                printf("□ ");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols, int x, int y) {
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

void next_generation(int grid[MAX_SIZE][MAX_SIZE], int next[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int alive_neighbors = count_neighbors(grid, rows, cols, i, j);
            if (grid[i][j] == 1) {
                // Live cell
                if (alive_neighbors < 2 || alive_neighbors > 3) {
                    next[i][j] = 0; // Dies
                } else {
                    next[i][j] = 1; // Lives
                }
            } else {
                // Dead cell
                if (alive_neighbors == 3) {
                    next[i][j] = 1; // Becomes alive
                } else {
                    next[i][j] = 0; // Remains dead
                }
            }
        }
    }
}

void randomize_grid(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2; // Randomly set cells to alive/dead
        }
    }
}

int main() {
    int rows, cols, generations;
    int grid[MAX_SIZE][MAX_SIZE] = {0};
    int next[MAX_SIZE][MAX_SIZE] = {0};

    printf("Enter the number of rows (max %d): ", MAX_SIZE);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_SIZE);
    scanf("%d", &cols);
    printf("Enter the number of generations to simulate: ");
    scanf("%d", &generations);

    // Initialize random number generator
    srand(time(0));

    // Randomly initialize the grid
    randomize_grid(grid, rows, cols);

    for (int gen = 0; gen < generations; gen++) {
        display_grid(grid, rows, cols);
        next_generation(grid, next, rows, cols);

        // Copy the next generation to the current grid
        memcpy(grid, next, sizeof(grid));
        usleep(500000); // Delay for half a second
    }

    return 0;
}