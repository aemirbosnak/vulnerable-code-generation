//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define OPEN 1
#define BLOCKED 0

typedef struct {
    int grid[SIZE][SIZE];
    int visited[SIZE][SIZE];
} PercolationGrid;

void initializeGrid(PercolationGrid *pg);
void printGrid(PercolationGrid *pg);
void openSite(PercolationGrid *pg, int row, int col);
int isSiteOpen(PercolationGrid *pg, int row, int col);
int isInBounds(int row, int col);
void depthFirstSearch(PercolationGrid *pg, int row, int col);
int canPercolate(PercolationGrid *pg);
void simulatePercolation(PercolationGrid *pg, double probability);
void freeMemory(PercolationGrid *pg);

int main() {
    srand(time(NULL));
    PercolationGrid pg;
    
    printf("=== Percolation Simulator ===\n");
    double probability;
    
    printf("Enter the probability of opening a site (0.0 to 1.0): ");
    scanf("%lf", &probability);
    
    if (probability < 0.0 || probability > 1.0) {
        printf("Invalid probability! It should be between 0.0 and 1.0.\n");
        return 1;
    }

    simulatePercolation(&pg, probability);
    
    return 0;
}

void initializeGrid(PercolationGrid *pg) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            pg->grid[i][j] = BLOCKED;
            pg->visited[i][j] = 0;
        }
    }
}

void printGrid(PercolationGrid *pg) {
    printf("Grid State:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", pg->grid[i][j]);
        }
        printf("\n");
    }
}

void openSite(PercolationGrid *pg, int row, int col) {
    if (isInBounds(row, col)) {
        pg->grid[row][col] = OPEN;
    }
}

int isSiteOpen(PercolationGrid *pg, int row, int col) {
    return isInBounds(row, col) && pg->grid[row][col] == OPEN;
}

int isInBounds(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

void depthFirstSearch(PercolationGrid *pg, int row, int col) {
    if (!isInBounds(row, col) || pg->visited[row][col] || !isSiteOpen(pg, row, col)) {
        return;
    }
    
    pg->visited[row][col] = 1;

    // Explore neighbors
    depthFirstSearch(pg, row + 1, col); // Down
    depthFirstSearch(pg, row - 1, col); // Up
    depthFirstSearch(pg, row, col + 1); // Right
    depthFirstSearch(pg, row, col - 1); // Left
}

int canPercolate(PercolationGrid *pg) {
    for (int col = 0; col < SIZE; col++) {
        if (isSiteOpen(pg, 0, col)) {
            depthFirstSearch(pg, 0, col);
        }
    }

    // Check if there's a path to the bottom row
    for (int col = 0; col < SIZE; col++) {
        if (pg->visited[SIZE - 1][col]) {
            return 1; // Percolates
        }
    }
    return 0; // Does not percolate
}

void simulatePercolation(PercolationGrid *pg, double probability) {
    initializeGrid(pg);
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((double)rand() / RAND_MAX < probability) {
                openSite(pg, i, j);
            }
        }
    }
    
    printGrid(pg);
    
    if (canPercolate(pg)) {
        printf("The system percolates! 🌊\n");
    } else {
        printf("The system does NOT percolate! 💧\n");
    }
}

void freeMemory(PercolationGrid *pg) {
    // In this case there's no dynamic memory, but placeholders for complex structures
    // This is here for future enhancements.
}