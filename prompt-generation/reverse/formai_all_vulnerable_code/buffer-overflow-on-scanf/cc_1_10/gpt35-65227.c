//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
/*
Percolation Simulator Example Program
Author: [Your Name]
Date: [Date]

Description:
This program simulates percolation using a square grid and the weighted quick-union algorithm.
The user inputs the size of the grid and the program outputs whether or not the grid percolates.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define EMPTY 0
#define OCCUPIED 1

// Data structure representing the grid
struct grid {
    int *cells;
    int size;
};

// Initializes a new grid of size n x n
void init_grid(struct grid *g, int n) {
    g->cells = calloc(n * n, sizeof(int));
    g->size = n;
}

// Frees the memory used by the grid
void delete_grid(struct grid *g) {
    free(g->cells);
}

// Returns the index of the cell at position (i, j)
int index_of(int i, int j, int n) {
    return i * n + j;
}

// Connects the cells at (i1, j1) and (i2, j2) if they are not already connected
void connect(struct grid *g, int i1, int j1, int i2, int j2) {
    int n = g->size;
    int p = index_of(i1, j1, n);
    int q = index_of(i2, j2, n);
    if (g->cells[p] == EMPTY || g->cells[q] == EMPTY) return;
    if (p == q) return;
    g->cells[p] = g->cells[q] = g->cells[p] + g->cells[q];
    if (g->cells[p] == n*n) g->cells[p] = -n*n;
    if (g->cells[q] == n*n) g->cells[q] = -n*n;
    if (g->cells[p] < 0) {
        g->cells[q] = p;
        g->cells[p] = -g->cells[p];
    } else {
        g->cells[p] = q;
        g->cells[q] = -g->cells[q];
    }
}

// Returns 1 if the cells at (i, j) and (k, l) are connected, 0 otherwise
int is_connected(struct grid *g, int i, int j, int k, int l) {
    int n = g->size;
    int p = index_of(i, j, n);
    int q = index_of(k, l, n);
    while (g->cells[p] >= 0) p = g->cells[p];
    while (g->cells[q] >= 0) q = g->cells[q];
    return p == q;
}

// Randomly fills the cells in the grid with a probability of p
void fill_grid(struct grid *g, double p) {
    int n = g->size;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double r = (double) rand() / RAND_MAX;
            if (r < p) {
                g->cells[index_of(i, j, n)] = OCCUPIED;
            }
        }
    }
}

// Returns 1 if the grid percolates, 0 otherwise
int does_percolate(struct grid *g) {
    int n = g->size;
    for (int j = 0; j < n; j++) {
        if (g->cells[j] == OCCUPIED) {
            for (int k = n*(n-1); k < n*n; k++) {
                if (g->cells[k] == OCCUPIED && is_connected(g, 0, j, n-1, k % n)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int n;
    double p;
    printf("Enter the size of the grid: ");
    while (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid input. Please enter an integer greater than 0: ");
        while (getchar() != '\n');
    }
    struct grid g;
    init_grid(&g, n);
    printf("Enter the probability of a cell being occupied (0 <= p <= 1): ");
    while (scanf("%lf", &p) != 1 || p < 0 || p > 1) {
        printf("Invalid input. Please enter a number between 0 and 1: ");
        while (getchar() != '\n');
    }
    fill_grid(&g, p);
    if (does_percolate(&g)) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }
    delete_grid(&g);
    return 0;
}