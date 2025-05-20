//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int grid[MAX_SIZE][MAX_SIZE];
    int size;
} Percolation;

void initialize(Percolation *p, int size) {
    p->size = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = 0; // 0 represents blocked sites
        }
    }
}

void openSite(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) {
        fprintf(stderr, "Error: Invalid site coordinates (%d, %d).\n", row, col);
        return;
    }
    p->grid[row][col] = 1; // 1 represents open sites
}

int isOpen(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) {
        return 0; // Out of bounds, treated as blocked
    }
    return p->grid[row][col];
}

int percolates(Percolation *p) {
    for (int col = 0; col < p->size; col++) {
        if (isOpen(p, 0, col) && dfs(p, 0, col)) {
            return 1;
        }
    }
    return 0;
}

int dfs(Percolation *p, int row, int col) {
    if (row == p->size - 1) {
        return 1; // Reached bottom row
    }
    
    // Mark the site as visited
    if (!isOpen(p, row, col)) {
        return 0; // Blocked site, cannot proceed
    }
    
    // Temporarily mark the site as visited
    p->grid[row][col] = -1; // Using -1 as visited mark

    // Explore the four possible directions
    int result = dfs(p, row + 1, col) || 
                 dfs(p, row - 1, col) || 
                 dfs(p, row, col + 1) || 
                 dfs(p, row, col - 1);

    // Restore the site state as open
    p->grid[row][col] = 1; // Restore to open site state
    return result;
}

void simulatePercolation(int size) {
    Percolation p;
    initialize(&p, size);
    
    // Randomly open sites
    int totalSites = size * size;
    int openCount = 0;
    
    while (openCount < totalSites / 2) { // Open half of the sites
        int row = rand() % size;
        int col = rand() % size;
        
        if (!isOpen(&p, row, col)) {
            openSite(&p, row, col);
            openCount++;
        }
    }

    if (percolates(&p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int size;

    printf("Enter the size of the grid (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size <= 0 || size > MAX_SIZE) {
        fprintf(stderr, "Size must be between 1 and %d\n", MAX_SIZE);
        return EXIT_FAILURE;
    }

    simulatePercolation(size);
    return EXIT_SUCCESS;
}