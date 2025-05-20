//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int size;
    int **grid;
} Percolation;

Percolation* create_percolation(int size);
void free_percolation(Percolation *perc);
void open_site(Percolation *perc, int row, int col);
int is_open(Percolation *perc, int row, int col);
void print_grid(Percolation *perc);
int percolates(Percolation *perc);
int dfs(Percolation *perc, int row, int col, int *visited);

int main() {
    srand(time(NULL));
    int grid_size;
    
    printf("Enter grid size for percolation (N x N): ");
    scanf("%d", &grid_size);

    Percolation *perc = create_percolation(grid_size);
    
    // Randomly open sites in the grid
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            if (rand() % 2 == 0) {
                open_site(perc, i, j);
            }
        }
    }

    printf("Percolation Grid:\n");
    print_grid(perc);

    if (percolates(perc)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does NOT percolate.\n");
    }

    free_percolation(perc);
    return 0;
}

Percolation* create_percolation(int size) {
    Percolation *perc = (Percolation *)malloc(sizeof(Percolation));
    perc->size = size;

    perc->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        perc->grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            perc->grid[i][j] = BLOCKED;
        }
    }
    return perc;
}

void free_percolation(Percolation *perc) {
    for (int i = 0; i < perc->size; i++) {
        free(perc->grid[i]);
    }
    free(perc->grid);
    free(perc);
}

void open_site(Percolation *perc, int row, int col) {
    if (row >= 0 && row < perc->size && col >= 0 && col < perc->size) {
        perc->grid[row][col] = OPEN;
    }
}

int is_open(Percolation *perc, int row, int col) {
    if (row >= 0 && row < perc->size && col >= 0 && col < perc->size) {
        return perc->grid[row][col] == OPEN;
    }
    return 0;
}

void print_grid(Percolation *perc) {
    for (int i = 0; i < perc->size; i++) {
        for (int j = 0; j < perc->size; j++) {
            printf("%d ", perc->grid[i][j]);
        }
        printf("\n");
    }
}

int percolates(Percolation *perc) {
    int *visited = (int *)calloc(perc->size * perc->size, sizeof(int));
    for (int col = 0; col < perc->size; col++) {
        if (is_open(perc, 0, col) && !visited[col]) {
            if (dfs(perc, 0, col, visited)) {
                free(visited);
                return 1;
            }
        }
    }
    free(visited);
    return 0;
}

int dfs(Percolation *perc, int row, int col, int *visited) {
    if (row == perc->size - 1) {
        return 1; // Reached bottom
    }
    visited[row * perc->size + col] = 1; // Mark as visited
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

    for (int d = 0; d < 4; d++) {
        int new_row = row + directions[d][0];
        int new_col = col + directions[d][1];
        if (is_open(perc, new_row, new_col) && !visited[new_row * perc->size + new_col]) {
            if (dfs(perc, new_row, new_col, visited)) {
                return 1;
            }
        }
    }
    return 0;
}