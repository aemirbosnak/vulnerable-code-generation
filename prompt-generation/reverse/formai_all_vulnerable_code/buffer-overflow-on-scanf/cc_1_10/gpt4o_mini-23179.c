//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

void initialize_grid(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols);
void print_grid(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols);
void update_grid(int grid[MAX_SIZE][MAX_SIZE], int new_grid[MAX_SIZE][MAX_SIZE], int rows, int cols);
int count_neighbors(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols, int x, int y);

int main() {
    int rows, cols;
    char choice;

    printf("Welcome to Conway's Game of Life!\n");
    printf("Enter the number of rows (max %d): ", MAX_SIZE);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_SIZE);
    scanf("%d", &cols);

    int grid[MAX_SIZE][MAX_SIZE];
    int new_grid[MAX_SIZE][MAX_SIZE];

    initialize_grid(grid, rows, cols);
    
    printf("Would you like to populate the grid with a pattern? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y') {
        int pattern_type;
        printf("Choose a pattern type (1: Glider, 2: Block, 3: Beacon): ");
        scanf("%d", &pattern_type);

        switch (pattern_type) {
            case 1: // Glider
                grid[1][2] = 1;
                grid[2][3] = 1;
                grid[3][1] = 1;
                grid[3][2] = 1;
                grid[3][3] = 1;
                break;
            case 2: // Block
                grid[1][1] = 1;
                grid[1][2] = 1;
                grid[2][1] = 1;
                grid[2][2] = 1;
                break;
            case 3: // Beacon
                grid[1][1] = 1;
                grid[1][2] = 1;
                grid[2][1] = 1;
                grid[2][2] = 1;
                grid[3][3] = 1;
                grid[3][4] = 1;
                grid[4][3] = 1;
                grid[4][4] = 1;
                break;
            default:
                printf("Invalid pattern type selected.\n");
        }
    }

    while (true) {
        print_grid(grid, rows, cols);
        update_grid(grid, new_grid, rows, cols);
        memcpy(grid, new_grid, sizeof(grid));
        usleep(500000); // Sleep for 500ms
        printf("\033[H\033[J"); // Clear screen on Unix/Linux
    }

    return 0;
}

void initialize_grid(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 0; // Initialize all cells to dead
        }
    }
}

void print_grid(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                printf("■ "); // Live cell
            } else {
                printf("□ "); // Dead cell
            }
        }
        printf("\n");
    }
    printf("\nPress Ctrl+C to exit.\n");
}

void update_grid(int grid[MAX_SIZE][MAX_SIZE], int new_grid[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = count_neighbors(grid, rows, cols, i, j);
            if (grid[i][j] == 1) {
                new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                new_grid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
}

int count_neighbors(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int ni = x + i, nj = y + j;
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                count += grid[ni][nj];
            }
        }
    }
    return count;
}