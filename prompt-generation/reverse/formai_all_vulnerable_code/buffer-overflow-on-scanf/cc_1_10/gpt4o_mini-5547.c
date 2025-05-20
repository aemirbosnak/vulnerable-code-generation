//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 20
#define COLS 40

// Function to display the grid
void displayGrid(int grid[ROWS][COLS]) {
    system("clear"); // Clear the terminal for better readability
    
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (grid[i][j] == 1) {
                printf("■ "); // Live cell
            } else {
                printf("□ "); // Dead cell
            }
        }
        printf("\n");
    }
}

// Function to count the number of live neighbors
int countNeighbors(int grid[ROWS][COLS], int x, int y) {
    int count = 0;
    
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            
            int newX = x + i;
            int newY = y + j;
            
            // Check for boundaries
            if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS) {
                count += grid[newX][newY];
            }
        }
    }
    
    return count;
}

// Function to update the grid based on the rules of the game
void updateGrid(int grid[ROWS][COLS]) {
    int newGrid[ROWS][COLS] = {0}; // New grid to hold the updated state
    
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int liveNeighbors = countNeighbors(grid, i, j);
            
            if (grid[i][j] == 1) {
                // Rule 1 or Rule 3
                if (liveNeighbors == 2 || liveNeighbors == 3) {
                    newGrid[i][j] = 1; // Live cell survives
                }
            } else {
                // Rule 4
                if (liveNeighbors == 3) {
                    newGrid[i][j] = 1; // Dead cell becomes alive
                }
            }
        }
    }
    
    // Copy the new grid back into the original grid
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS] = {0}; // Initialize grid to all dead cells
    int generations;

    // User input for initial state
    printf("Welcome to Conway's Game of Life!\n");
    printf("Please enter the number of generations to simulate: ");
    scanf("%d", &generations);
    
    printf("Seed the grid with live cells (enter row and column as coordinates, -1 to end):\n");
    while (1) {
        int x, y;
        printf("Enter coordinates (row col): ");
        scanf("%d %d", &x, &y);
        
        if (x == -1 || y == -1) {
            break; // Exit loop on -1 input
        }
        
        if (x >= 0 && x < ROWS && y >= 0 && y < COLS) {
            grid[x][y] = 1; // Set the cell to alive
        } else {
            printf("Invalid coordinates, please try again.\n");
        }
    }

    // Run the simulation for the specified number of generations
    for (int i = 0; i < generations; ++i) {
        displayGrid(grid);
        updateGrid(grid);
        usleep(200000); // Sleep for 200ms for better visualization
    }

    printf("Simulation finished!\n");
    return 0;
}