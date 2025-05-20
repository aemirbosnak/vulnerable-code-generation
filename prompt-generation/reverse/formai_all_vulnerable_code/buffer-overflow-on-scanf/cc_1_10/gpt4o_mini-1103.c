//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

// Structure to represent the grid
typedef struct {
    int grid[MAX_SIZE][MAX_SIZE];
    int size;
} PercolationSite;

// Function to initialize the grid
void initializeGrid(PercolationSite *site, int n) {
    site->size = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            site->grid[i][j] = 0; // Unopened site
        }
    }
}

// Function to randomly open sites in the grid
void openRandomSites(PercolationSite *site, double probability) {
    for (int i = 0; i < site->size; i++) {
        for (int j = 0; j < site->size; j++) {
            double rand_val = ((double)rand() / RAND_MAX);
            site->grid[i][j] = (rand_val < probability) ? 1 : 0; // Open with given probability
        }
    }
}

// Function to check if a cell is valid and open
int isValid(int x, int y, PercolationSite *site) {
    return (x >= 0 && x < site->size && y >= 0 && y < site->size && site->grid[x][y] == 1);
}

// Depth-First Search (DFS) algorithm to explore percolation paths
void dfs(PercolationSite *site, int x, int y, int *visited) {
    if (!isValid(x, y, site) || visited[x * site->size + y]) {
        return;
    }
    visited[x * site->size + y] = 1; // Mark this node as visited

    // Explore neighbors (up, down, left, right)
    dfs(site, x-1, y, visited);
    dfs(site, x+1, y, visited);
    dfs(site, x, y-1, visited);
    dfs(site, x, y+1, visited);
}

// Function to check if the system percolates
int checkPercolation(PercolationSite *site) {
    int *visited = (int *)calloc(site->size * site->size, sizeof(int));
    int percolates = 0;

    // Start DFS from all open sites in the first row
    for (int j = 0; j < site->size; j++) {
        if (site->grid[0][j] == 1 && !visited[0 * site->size + j]) {
            dfs(site, 0, j, visited);
        }
    }

    // Check if any open site in the last row is connected to the top
    for (int j = 0; j < site->size; j++) {
        if (visited[(site->size - 1) * site->size + j]) {
            percolates = 1;
            break;
        }
    }

    free(visited);
    return percolates;
}

// Function to run the percolation simulation
void runSimulation(int gridSize, double probability) {
    PercolationSite site;
    initializeGrid(&site, gridSize);
    openRandomSites(&site, probability);

    printf("Grid (%d x %d) with opening probability %.2f:\n", gridSize, gridSize, probability);
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            printf("%d ", site.grid[i][j]);
        }
        printf("\n");
    }

    if (checkPercolation(&site)) {
        printf("The system percolates.\n");
    } else {
        printf("The system does not percolate.\n");
    }
}

// Main function to execute the percolation simulator
int main() {
    srand(time(NULL)); // Seed the random number generator
    int gridSize;
    double probability;

    // Prompt user for the grid size and probability
    printf("Enter the size of the grid (1 to %d): ", MAX_SIZE);
    scanf("%d", &gridSize);
    printf("Enter the probability of opening a site (0.0 to 1.0): ");
    scanf("%lf", &probability);

    // Validate inputs
    if (gridSize < 1 || gridSize > MAX_SIZE || probability < 0.0 || probability > 1.0) {
        printf("Invalid input! Please enter valid parameters.\n");
        return 1;
    }

    runSimulation(gridSize, probability);
    return 0;
}