//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep function

#define MAX_ROWS 50
#define MAX_COLS 50

void initializeGrid(int rows, int cols, int grid[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2; // Randomly populate the grid with alive (1) or dead (0)
        }
    }
}

void displayGrid(int rows, int cols, int grid[rows][cols]) {
    system("clear"); // Clear the console for a better view
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s", grid[i][j] ? "■" : "□"); // Display alive as filled square and dead as empty square
        }
        printf("\n");
    }
}

int countNeighbors(int rows, int cols, int grid[rows][cols], int x, int y) {
    int count = 0;
    // Check all 8 neighbors
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; // Skip itself
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                count += grid[nx][ny];
            }
        }
    }
    return count;
}

void updateGrid(int rows, int cols, int grid[rows][cols]) {
    int newGrid[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = countNeighbors(rows, cols, grid, i, j);
            // Apply the Game of Life rules
            if (grid[i][j] == 1) { // Cell is alive
                newGrid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0; // Survive
            } else { // Cell is dead
                newGrid[i][j] = (neighbors == 3) ? 1 : 0; // Revive
            }
        }
    }
    // Copy new grid to original grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int rows, cols;
    srand(time(NULL)); // Seed for random number generation

    printf("Enter number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    // Ensure grid size is within limits
    if (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS) {
        printf("Grid size out of bounds. Exiting...\n");
        return 1;
    }

    int grid[rows][cols];
    initializeGrid(rows, cols, grid);
    
    while (1) {
        displayGrid(rows, cols, grid);
        updateGrid(rows, cols, grid);
        usleep(200000); // Pause for a while to visualize changes (200 milliseconds)
    }

    return 0; // Just a formality; likely never reached in this infinite loop
}