//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY 0
#define BLOCKED 1
#define OPEN 2

typedef struct {
    int **grid;
    int size;
} PercolationGrid;

PercolationGrid* createGrid(int size);
void freeGrid(PercolationGrid *grid);
void displayGrid(PercolationGrid *grid);
void fillGrid(PercolationGrid *grid, double prob);
int percolates(PercolationGrid *grid);
void dfs(PercolationGrid *grid, int x, int y, int **visited);

int main() {
    srand(time(NULL));
    int gridSize;
    double probability;

    printf("Enter the size of the grid (N x N): ");
    scanf("%d", &gridSize);
    printf("Enter the probability of a site being open (0.0 to 1.0): ");
    scanf("%lf", &probability);

    PercolationGrid *grid = createGrid(gridSize);
    fillGrid(grid, probability);
    printf("Generated Percolation Grid:\n");
    displayGrid(grid);
    
    if (percolates(grid)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freeGrid(grid);
    return 0;
}

PercolationGrid* createGrid(int size) {
    PercolationGrid *grid = malloc(sizeof(PercolationGrid));
    grid->size = size;
    grid->grid = (int **)malloc(size * sizeof(int *));
    
    for (int i = 0; i < size; i++) {
        grid->grid[i] = (int *)malloc(size * sizeof(int));
    }
    
    return grid;
}

void freeGrid(PercolationGrid *grid) {
    for (int i = 0; i < grid->size; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    free(grid);
}

void displayGrid(PercolationGrid *grid) {
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            if (grid->grid[i][j] == EMPTY) {
                printf(". ");
            } else if (grid->grid[i][j] == BLOCKED) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

void fillGrid(PercolationGrid *grid, double prob) {
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            if ((double)rand() / RAND_MAX < prob) {
                grid->grid[i][j] = OPEN;
            } else {
                grid->grid[i][j] = BLOCKED;
            }
        }
    }
}

int percolates(PercolationGrid *grid) {
    int **visited = (int **)malloc(grid->size * sizeof(int *));
    for (int i = 0; i < grid->size; i++) {
        visited[i] = (int *)calloc(grid->size, sizeof(int));
    }

    for (int j = 0; j < grid->size; j++) {
        if (grid->grid[0][j] == OPEN && !visited[0][j]) {
            dfs(grid, 0, j, visited);
        }
    }

    for (int j = 0; j < grid->size; j++) {
        if (visited[grid->size - 1][j]) {
            for (int i = 0; i < grid->size; i++) {
                free(visited[i]);
            }
            free(visited);
            return 1;
        }
    }

    for (int i = 0; i < grid->size; i++) {
        free(visited[i]);
    }
    free(visited);
    return 0;
}

void dfs(PercolationGrid *grid, int x, int y, int **visited) {
    if (x < 0 || x >= grid->size || y < 0 || y >= grid->size || visited[x][y] || grid->grid[x][y] != OPEN) {
        return;
    }

    visited[x][y] = 1;

    dfs(grid, x + 1, y, visited); // Down
    dfs(grid, x - 1, y, visited); // Up
    dfs(grid, x, y + 1, visited); // Right
    dfs(grid, x, y - 1, visited); // Left
}