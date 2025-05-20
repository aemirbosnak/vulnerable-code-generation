//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int **grid;
    int size;
} Percolation;

Percolation* create_percolation(int n) {
    Percolation *p = (Percolation*) malloc(sizeof(Percolation));
    p->size = n;
    p->grid = (int**) malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        p->grid[i] = (int*) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            p->grid[i][j] = BLOCKED; // Initialize as blocked
        }
    }

    return p;
}

void free_percolation(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void random_fill(Percolation *p, double probability) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if ((rand() / (double)RAND_MAX) < probability) {
                p->grid[i][j] = OPEN; // Open site
            }
        }
    }
}

void print_grid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

int is_open(Percolation *p, int row, int col) {
    return (row >= 0 && row < p->size && col >= 0 && col < p->size && p->grid[row][col] == OPEN);
}

int dfs(Percolation *p, int row, int col, int *visited) {
    if (row == p->size - 1) return 1; // Reached bottom
    visited[row * p->size + col] = 1; // Mark as visited

    // Directions: down, up, right, left
    int deltas[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    for (int i = 0; i < 4; i++) {
        int newRow = row + deltas[i][0];
        int newCol = col + deltas[i][1];

        if (is_open(p, newRow, newCol) && !visited[newRow * p->size + newCol]) {
            if (dfs(p, newRow, newCol, visited)) {
                return 1; // Path to bottom found
            }
        }
    }
    
    return 0; // No path found
}

int percolates(Percolation *p) {
    for (int col = 0; col < p->size; col++) {
        if (is_open(p, 0, col)) {
            int *visited = (int*) calloc(p->size * p->size, sizeof(int));
            if (dfs(p, 0, col, visited)) {
                free(visited);
                return 1; // System percolates
            }
            free(visited);
        }
    }
    return 0; // System does not percolate
}

int main() {
    srand(time(NULL));
    int size;
    double probability;

    printf("Enter the size of the grid (n x n): ");
    scanf("%d", &size);
    
    printf("Enter the probability of a site being open (0.0 to 1.0): ");
    scanf("%lf", &probability);

    Percolation *p = create_percolation(size);
    random_fill(p, probability);

    printf("\nGenerated Percolation Grid:\n");
    print_grid(p);
    
    if (percolates(p)) {
        printf("\nThe system percolates!\n");
    } else {
        printf("\nThe system does not percolate.\n");
    }

    free_percolation(p);
    return 0;
}