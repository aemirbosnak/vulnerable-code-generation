//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if a site is connected to the rest of the network
int isConnected(int** grid, int width, int height, int row, int col) {
    // Check if the site is in the grid
    if (row < 0 || row >= height || col < 0 || col >= width) {
        return 0;
    }
    
    // Check if the site is occupied
    if (grid[row][col] == 0) {
        return 0;
    }
    
    // Mark the site as visited
    grid[row][col] = 0;
    
    // Check if the site is connected to the rest of the network
    int count = 0;
    int i, j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int r = row + i;
            int c = col + j;
            
            // Check if the site is in the grid
            if (r < 0 || r >= height || c < 0 || c >= width) {
                continue;
            }
            
            // Check if the site is occupied
            if (grid[r][c] == 0) {
                count++;
            }
        }
    }
    
    // If the site is connected to the rest of the network, return 1
    if (count >= 4) {
        return 1;
    } else {
        return 0;
    }
}

// Function to simulate the percolation process
void percolation(int** grid, int width, int height, int n) {
    int i, j;
    int* visited = (int*)calloc(height * width, sizeof(int));
    
    // Initialize the grid
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            grid[i][j] = 1;
            visited[i * width + j] = 0;
        }
    }
    
    // Simulate the percolation process for n iterations
    for (i = 0; i < n; i++) {
        int row, col;
        
        // Randomly select a site to check
        row = rand() % height;
        col = rand() % width;
        
        // Check if the site is connected to the rest of the network
        if (isConnected(grid, width, height, row, col)) {
            grid[row][col] = 0;
            for (j = -1; j <= 1; j++) {
                for (i = -1; i <= 1; i++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int r = row + i;
                    int c = col + j;
                    
                    // Check if the site is in the grid
                    if (r < 0 || r >= height || c < 0 || c >= width) {
                        continue;
                    }
                    
                    // Check if the site is occupied
                    if (grid[r][c] == 1) {
                        visited[r * width + c] = 0;
                    }
                }
            }
        }
    }
    
    // Print the final state of the grid
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (grid[i][j] == 1) {
                printf("X ");
            } else if (visited[i * width + j]) {
                printf("O ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    
    // Free the memory
    free(visited);
}

int main() {
    int width, height, n;
    printf("Enter the width of the grid: ");
    scanf("%d", &width);
    printf("Enter the height of the grid: ");
    scanf("%d", &height);
    printf("Enter the number of iterations: ");
    scanf("%d", &n);
    
    int** grid = (int**)calloc(height, sizeof(int*));
    for (int i = 0; i < height; i++) {
        grid[i] = (int*)calloc(width, sizeof(int));
    }
    
    srand(time(NULL));
    percolation(grid, width, height, n);
    
    return 0;
}