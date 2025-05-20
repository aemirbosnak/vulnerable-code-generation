//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

// Function to initialize the grid with obstacles
void initialize(char grid[N][N], int n) {
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            grid[i][j] = 1;
}

// Function to check if a cell is open
int isOpen(int x, int y, char grid[N][N], int n) {
    if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1)
        return 1;
    else
        return 0;
}

// Function to check if a cell is full
int isFull(int x, int y, char grid[N][N], int n) {
    if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0)
        return 1;
    else
        return 0;
}

// Function to check if a cell is open and update the grid accordingly
void percolate(int x, int y, char grid[N][N], int n) {
    if(isOpen(x, y, grid, n)) {
        grid[x][y] = 0;
        if(isFull(x, y-1, grid, n))
            percolate(x, y-1, grid, n);
        if(isFull(x-1, y, grid, n))
            percolate(x-1, y, grid, n);
        if(isFull(x+1, y, grid, n))
            percolate(x+1, y, grid, n);
        if(isFull(x, y+1, grid, n))
            percolate(x, y+1, grid, n);
    }
}

// Function to simulate the percolation process
void simulate(char grid[N][N], int n) {
    int i, j, count = 0;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(isFull(i, j, grid, n)) {
                percolate(i, j, grid, n);
                count++;
            }
        }
    }
    printf("Number of clusters: %d\n", count);
}

int main() {
    int n, i, j;
    printf("Enter the size of the grid: ");
    scanf("%d", &n);

    char grid[N][N];
    initialize(grid, n);

    simulate(grid, n);

    return 0;
}