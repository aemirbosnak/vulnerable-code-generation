//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int **grid;
    int size;
} PercolationGrid;

PercolationGrid* createGrid(int n) {
    PercolationGrid *pg = malloc(sizeof(PercolationGrid));
    pg->size = n;
    pg->grid = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        pg->grid[i] = malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pg->grid[i][j] = BLOCKED;  // Initialize to blocked
    return pg;
}

void freeGrid(PercolationGrid *pg) {
    for (int i = 0; i < pg->size; i++) {
        free(pg->grid[i]);
    }
    free(pg->grid);
    free(pg);
}

void openSite(PercolationGrid *pg, int row, int col) {
    if (row >= 0 && row < pg->size && col >= 0 && col < pg->size) {
        pg->grid[row][col] = OPEN;
    }
}

int isOpen(PercolationGrid *pg, int row, int col) {
    return (row >= 0 && row < pg->size && col >= 0 && col < pg->size && 
            pg->grid[row][col] == OPEN);
}

void printGrid(PercolationGrid *pg) {
    for (int i = 0; i < pg->size; i++) {
        for (int j = 0; j < pg->size; j++) {
            printf("%d ", pg->grid[i][j]);
        }
        printf("\n");
    }
}

int isConnected(int **visited, int row, int col, int n) {
    if (row < 0 || col < 0 || row >= n || col >= n || visited[row][col] || 
        visited[row][col] == BLOCKED) {
        return 0;
    }
    visited[row][col] = 1; // Mark as visited

    if (row == n-1) { // Reached the bottom
        return 1;
    }

    int up = isConnected(visited, row - 1, col, n);
    int down = isConnected(visited, row + 1, col, n);
    int left = isConnected(visited, row, col - 1, n);
    int right = isConnected(visited, row, col + 1, n);

    return up || down || left || right;
}

int percolates(PercolationGrid *pg) {
    int **visited = malloc(pg->size * sizeof(int*));
    for (int i = 0; i < pg->size; i++) {
        visited[i] = calloc(pg->size, sizeof(int));
    }

    for (int col = 0; col < pg->size; col++) {
        if (isOpen(pg, 0, col)) {
            if (isConnected(visited, 0, col, pg->size)) {
                for (int i = 0; i < pg->size; i++) {
                    free(visited[i]);
                }
                free(visited);
                return 1; // System percolates
            }
        }
    }

    for (int i = 0; i < pg->size; i++) {
        free(visited[i]);
    }
    free(visited);
    return 0; // System does not percolate
}

void randomOpenSites(PercolationGrid *pg, float probability) {
    for (int i = 0; i < pg->size; i++) {
        for (int j = 0; j < pg->size; j++) {
            if ((float)rand() / RAND_MAX < probability) {
                openSite(pg, i, j);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int size;
    float probability;

    printf("Enter grid size (N x N): ");
    scanf("%d", &size);
    printf("Enter open site probability (0 to 1): ");
    scanf("%f", &probability);

    PercolationGrid *pg = createGrid(size);

    randomOpenSites(pg, probability);
    printGrid(pg);

    if (percolates(pg)) {
        printf("The system percolates.\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freeGrid(pg);
    return 0;
}