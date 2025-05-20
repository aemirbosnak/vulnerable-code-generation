//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare global variables
int SIZE;
double PROBABILITY;
int **grid, *visited;
int top, bottom;

// Function to initialize the grid
void initializeGrid() {
    int i, j;
    grid = (int **) malloc(SIZE * sizeof(int *));
    visited = (int *) calloc(SIZE * SIZE, sizeof(int));
    for (i = 0; i < SIZE; i++) {
        grid[i] = (int *) malloc(SIZE * sizeof(int));
        for (j = 0; j < SIZE; j++)
            if (((double)rand()) / RAND_MAX < PROBABILITY) grid[i][j] = 1;
            else grid[i][j] = 0;
    }
}

// Helper function to get index in 1D array given 2D index
int getIndex(int i, int j) {
    return i * SIZE + j;
}

// Helper function to check if cell is valid
int isValid(int i, int j) {
    return (i >= 0 && j >= 0 && i < SIZE && j < SIZE);
}

// DFS to check if grid is percolating
void dfs(int i, int j) {
    visited[getIndex(i, j)] = 1;
    if (i == SIZE-1) bottom = 1;
    if (i == 0) top = 1;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int k;
    for (k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (isValid(ni, nj) && grid[ni][nj] && !visited[getIndex(ni, nj)])
            dfs(ni, nj);
    }
}

int main() {
    // Get user input for grid size and probability
    printf("Enter grid size: ");
    scanf("%d", &SIZE);
    printf("Enter probability (between 0 and 1): ");
    scanf("%lf", &PROBABILITY);
    // Initialize grid and run DFS
    initializeGrid();
    int i;
    for (i = 0; i < SIZE; i++) {
        if (grid[0][i] && !visited[getIndex(0, i)]) dfs(0, i);
    }
    // Check if there is a path from top to bottom
    if (top && bottom) printf("The grid percolates!\n");
    else printf("The grid does not percolate.\n");
    // Free memory
    for (i = 0; i < SIZE; i++) {
        free(grid[i]);
    }
    free(grid);
    free(visited);
    return 0;
}