//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int rows;
    int cols;
    int **grid;
} Grid;

Grid* createGrid(int rows, int cols) {
    Grid* g = (Grid*)malloc(sizeof(Grid));
    g->rows = rows;
    g->cols = cols;
    g->grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        g->grid[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            g->grid[i][j] = BLOCKED; // Initialize grid to BLOCKED state
        }
    }
    return g;
}

void freeGrid(Grid* g) {
    for (int i = 0; i < g->rows; i++) {
        free(g->grid[i]);
    }
    free(g->grid);
    free(g);
}

void displayGrid(Grid* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            printf("%d ", g->grid[i][j]);
        }
        printf("\n");
    }
}

int isInBounds(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

void generatePercolation(Grid* g, float probability) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            // Randomly decide whether to open the site.
            if ((float)rand() / RAND_MAX < probability) {
                g->grid[i][j] = OPEN;
            }
        }
    }
}

int dfs(int x, int y, Grid* g, int** visited) {
    if (x == g->rows - 1) return 1; // Reached the bottom row
    if (!isInBounds(x, y, g->rows, g->cols) || g->grid[x][y] == BLOCKED || visited[x][y]) {
        return 0;
    }
    visited[x][y] = 1; // Mark this cell as visited
    // Explore all 4 directions
    if (dfs(x + 1, y, g, visited) ||
        dfs(x - 1, y, g, visited) ||
        dfs(x, y + 1, g, visited) ||
        dfs(x, y - 1, g, visited)) {
        return 1; // Found a path to the bottom
    }
    return 0; // No path found
}

int doesPercolate(Grid* g) {
    int** visited = (int**)malloc(g->rows * sizeof(int*));
    for (int i = 0; i < g->rows; i++) {
        visited[i] = (int*)malloc(g->cols * sizeof(int));
        for (int j = 0; j < g->cols; j++) {
            visited[i][j] = 0; // Initialize visited array
        }
    }

    for (int j = 0; j < g->cols; j++) {
        if (g->grid[0][j] == OPEN) {
            if (dfs(0, j, g, visited)) {
                free(visited);
                return 1; // Percolates if any path is found.
            }
        }
    }
    free(visited);
    return 0; // No path found, does not percolate
}

int main() {
    srand(time(NULL)); // Seed for randomness
    int rows, cols;
    float probability;
    
    printf("Enter grid dimensions (rows and columns): ");
    scanf("%d %d", &rows, &cols);
    
    printf("Enter the probability (0 to 1) of site being open: ");
    scanf("%f", &probability);
    
    Grid* g = createGrid(rows, cols);
    generatePercolation(g, probability);
    
    printf("Generated Percolation Grid:\n");
    displayGrid(g);
    
    if (doesPercolate(g)) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }
    
    freeGrid(g); // Clean up memory
    return 0;
}