//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLOCKED 0
#define OPEN 1
#define FULL 2

typedef struct {
    int *grid;
    int size;
} Percolation;

Percolation* createPercolation(int n) {
    Percolation* p = (Percolation *)malloc(sizeof(Percolation));
    p->size = n;
    p->grid = (int *)malloc(n * n * sizeof(int));
    for (int i = 0; i < n * n; ++i) {
        p->grid[i] = BLOCKED; // Initialize all sites to BLOCKED
    }
    return p;
}

void freePercolation(Percolation* p) {
    free(p->grid);
    free(p);
}

void openSite(Percolation* p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        p->grid[row * p->size + col] = OPEN; // Open the site
    }
}

int isOpen(Percolation* p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        return p->grid[row * p->size + col] == OPEN;
    }
    return 0;
}

int isFull(Percolation* p, int row, int col) {
    return p->grid[row * p->size + col] == FULL;
}

void fill(Percolation* p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size && isOpen(p, row, col) && !isFull(p, row, col)) {
        p->grid[row * p->size + col] = FULL; // Fill the site
        // Recursively fill neighboring sites
        fill(p, row - 1, col);
        fill(p, row + 1, col);
        fill(p, row, col - 1);
        fill(p, row, col + 1);
    }
}

int percolates(Percolation* p) {
    for (int col = 0; col < p->size; ++col) {
        if (isOpen(p, 0, col) && !isFull(p, 0, col)) {
            fill(p, 0, col); // Try to fill from the top row
        }
    }
    // Check if any site in the bottom row is full
    for (int col = 0; col < p->size; ++col) {
        if (isFull(p, p->size - 1, col)) {
            return 1; // Percolates
        }
    }
    return 0; // Does not percolate
}

void printGrid(Percolation* p) {
    for (int row = 0; row < p->size; ++row) {
        for (int col = 0; col < p->size; ++col) {
            int site = p->grid[row * p->size + col];
            if (site == BLOCKED) {
                printf(" ─ ");
            } else if (site == OPEN) {
                printf("   ");
            } else {
                printf(" ▓ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int size;
    printf("Welcome to the Percolation Simulator!\n");
    printf("Enter the grid size (e.g., 5): ");
    scanf("%d", &size);

    Percolation* p = createPercolation(size);

    // Open random sites in a quad grid
    for (int i = 0; i < size * size / 2; ++i) {
        int row = rand() % size;
        int col = rand() % size;
        openSite(p, row, col);
    }

    printGrid(p);
    
    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freePercolation(p);
    return 0;
}