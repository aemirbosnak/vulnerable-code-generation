//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int **grid;
    int size;
} PercolationSystem;

// Function to create a percolation system
PercolationSystem* createPercolationSystem(int size) {
    PercolationSystem *system = (PercolationSystem*)malloc(sizeof(PercolationSystem));
    system->size = size;
    system->grid = (int**)malloc(size * sizeof(int*));
    
    for (int i = 0; i < size; i++) {
        system->grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            system->grid[i][j] = BLOCKED; // Initialize all sites to blocked
        }
    }
    return system;
}

// Function to free the memory allocated for the percolation system
void freePercolationSystem(PercolationSystem *system) {
    for (int i = 0; i < system->size; i++) {
        free(system->grid[i]);
    }
    free(system->grid);
    free(system);
}

// Function to open a site
void openSite(PercolationSystem *system, int row, int col) {
    if (row >= 0 && row < system->size && col >= 0 && col < system->size) {
        system->grid[row][col] = OPEN;
    }
}

// Function to check if a site is open
int isOpen(PercolationSystem *system, int row, int col) {
    return (row >= 0 && row < system->size && col >= 0 && col < system->size && 
            system->grid[row][col] == OPEN);
}

// Depth-first search to check connectivity
int dfs(PercolationSystem *system, int row, int col, int *visited) {
    if (row == system->size - 1) {
        return 1; // We've reached the bottom
    }

    visited[row * system->size + col] = 1;

    // Possible movement directions
    int directions[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];
        if (isOpen(system, newRow, newCol) && !visited[newRow * system->size + newCol]) {
            if (dfs(system, newRow, newCol, visited)) {
                return 1; // Found a path to the bottom
            }
        }
    }
    return 0; // No path found
}

// Function to check for percolation
int percolates(PercolationSystem *system) {
    int *visited = (int*)calloc(system->size * system->size, sizeof(int));

    for (int col = 0; col < system->size; col++) {
        if (isOpen(system, 0, col)) {
            if (dfs(system, 0, col, visited)) {
                free(visited);
                return 1;
            }
        }
    }
    free(visited);
    return 0;
}

// Function to print the grid
void printGrid(PercolationSystem *system) {
    for (int i = 0; i < system->size; i++) {
        for (int j = 0; j < system->size; j++) {
            printf("%s ", system->grid[i][j] == OPEN ? "O" : "X");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size;

    printf("Enter grid size for percolation (e.g., 5 for 5x5): ");
    scanf("%d", &size);

    PercolationSystem *system = createPercolationSystem(size);
    int openSitesCount = 0;

    printf("Opening random sites...\n");
    while (openSitesCount < (size * size) / 2) {
        int row = rand() % size;
        int col = rand() % size;
        
        if (system->grid[row][col] == BLOCKED) {
            openSite(system, row, col);
            openSitesCount++;
        }
    }

    printGrid(system);

    if (percolates(system)) {
        printf("The system does percolate!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freePercolationSystem(system);
    return 0;
}