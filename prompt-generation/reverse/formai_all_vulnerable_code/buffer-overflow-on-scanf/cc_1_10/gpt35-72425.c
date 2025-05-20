//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to initialize the grid with random values
void initialize(int grid[ROWS][COLS], float p) {
    srand((unsigned)time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if((float)rand()/(float)RAND_MAX < p) {
                grid[i][j] = 1; // site is open
            } else {
                grid[i][j] = 0; // site is blocked
            }
        }
    }
}

// Function to print the grid
void printGrid(int grid[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(grid[i][j]==0) {
                printf("# "); // blocked site
            } else {
                printf("* "); // open site
            }
        }
        printf("\n");
    }
}

// Function to check if the site is open
int isOpen(int grid[ROWS][COLS], int row, int col) {
    return grid[row][col] == 1;
}

// Function to check if the site is connected to top row
int isTopConnected(int grid[ROWS][COLS]) {
    for(int j=0; j<COLS; j++) {
        if(grid[0][j] == 1) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the site is connected to bottom row
int isBottomConnected(int grid[ROWS][COLS]) {
    for(int j=0; j<COLS; j++) {
        if(grid[ROWS-1][j] == 1) {
            return 1;
        }
    }
    return 0;
}

// Function to perform the percolation process
int percolate(int grid[ROWS][COLS]) {
    int visited[ROWS][COLS] = {{0}};
    for(int j=0; j<COLS; j++) {
        if(grid[0][j] == 1) {
            visited[0][j] = 1;
            if(dfs(grid, visited, 0, j)) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to perform depth-first search
int dfs(int grid[ROWS][COLS], int visited[ROWS][COLS], int row, int col) {
    if(row<0 || row>=ROWS || col<0 || col>=COLS || visited[row][col] || grid[row][col]==0) {
        return 0;
    }
    if(row==ROWS-1) {
        return 1;
    }
    visited[row][col] = 1;
    // perform dfs on adjacent open sites
    return (dfs(grid, visited, row+1, col) || dfs(grid, visited, row-1, col) || dfs(grid, visited, row, col+1) || dfs(grid, visited, row, col-1));
}

int main() {
    int grid[ROWS][COLS];
    float p;
    printf("Enter the probability of site being open: ");
    scanf("%f", &p);
    initialize(grid, p);
    printf("Generated grid:\n");
    printGrid(grid);
    if(percolate(grid)) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }
    return 0;
}