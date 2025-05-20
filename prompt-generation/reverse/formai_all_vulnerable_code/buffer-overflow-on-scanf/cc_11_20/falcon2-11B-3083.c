//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define LIVE 1
#define DEAD 0

// Function to print the grid
void printGrid(int grid[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate next generation based on rules
void nextGeneration(int grid[MAX_SIZE][MAX_SIZE], int size) {
    // Iterate through each cell in the grid
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Check if cell is alive or dead
            int cellState = grid[i][j];
            
            // Count neighboring cells
            int liveNeighbors = 0;
            
            // Check top neighbor
            if (i > 0 && j > 0 && i < size - 1 && j < size - 1) {
                liveNeighbors += grid[i - 1][j - 1];
            } else if (i > 0 && j > 0) {
                liveNeighbors += grid[i - 1][j - 1];
            } else if (i > 0) {
                liveNeighbors += grid[i - 1][j];
            } else if (j > 0) {
                liveNeighbors += grid[i][j - 1];
            }
            
            // Check right neighbor
            if (i > 0 && j < size - 1) {
                liveNeighbors += grid[i - 1][j + 1];
            } else if (j < size - 1) {
                liveNeighbors += grid[i][j + 1];
            }
            
            // Check bottom neighbor
            if (i < size - 1 && j > 0 && i < size - 1 && j < size - 1) {
                liveNeighbors += grid[i + 1][j - 1];
            } else if (i < size - 1 && j > 0) {
                liveNeighbors += grid[i + 1][j - 1];
            } else if (i < size - 1) {
                liveNeighbors += grid[i + 1][j];
            } else if (j > 0) {
                liveNeighbors += grid[i][j - 1];
            }
            
            // Calculate next generation state based on rules
            if (cellState == LIVE && liveNeighbors < 2 && liveNeighbors > 3) {
                cellState = DEAD;
            } else if (cellState == DEAD && liveNeighbors == 3) {
                cellState = LIVE;
            }
            
            // Update the grid
            grid[i][j] = cellState;
        }
    }
}

int main() {
    int grid[MAX_SIZE][MAX_SIZE];
    int size = MAX_SIZE;
    int generation = 0;
    
    printf("Enter initial grid state (0 = dead, 1 = alive):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    // Print initial grid
    printf("Initial grid:\n");
    printGrid(grid, size);
    
    // Start the game loop
    while (1) {
        // Print current generation
        printf("Generation %d:\n", generation);
        printGrid(grid, size);
        
        // Calculate next generation
        nextGeneration(grid, size);
        
        // Increment generation counter
        generation++;
    }
    
    return 0;
}