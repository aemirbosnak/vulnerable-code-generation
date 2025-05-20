//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int grid[MAX_SIZE][MAX_SIZE];
    int size;
} Percolation;

void initialize(Percolation *p, int size) {
    p->size = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = 0;  // 0 means blocked, 1 means open
        }
    }
}

void openSite(Percolation *p, int row, int col) {
    if (row < 0 || col < 0 || row >= p->size || col >= p->size) {
        printf("Invalid site: (%d, %d)\n", row, col);
        return;
    }
    p->grid[row][col] = 1;  // Open the site
}

int isOpen(Percolation *p, int row, int col) {
    return (row >= 0 && row < p->size && col >= 0 && col < p->size && p->grid[row][col] == 1);
}

void printGrid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

int percolates(Percolation *p) {
    for (int j = 0; j < p->size; j++) {  // Check every cell on the top row
        if (isOpen(p, 0, j)) {
            if (checkPath(p, 0, j)) {
                return 1;  // If any path to the bottom is found
            }
        }
    }
    return 0;  // No path to the bottom
}

int checkPath(Percolation *p, int row, int col) {
    if (row == p->size - 1) {
        return 1;  // Reached bottom
    }
    if (!isOpen(p, row, col)) {
        return 0;  // If site is blocked
    }

    // Temporarily mark the site as visited
    p->grid[row][col] = -1; 

    // Check all 4 possible directions
    int found = checkPath(p, row + 1, col) ||   // down
                checkPath(p, row - 1, col) ||   // up
                checkPath(p, row, col + 1) ||   // right
                checkPath(p, row, col - 1);     // left

    // Restore the value
    p->grid[row][col] = 1;

    return found;
}

int main() {
    srand(time(NULL));
    Percolation p;
    int size;
    printf("Enter grid size (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size. Exiting...\n");
        return 1;
    }
    
    initialize(&p, size);
    
    int nOpenSites = 0;
    for (int i = 0; i < size * size; ) {
        int row = rand() % size;
        int col = rand() % size;

        if (p.grid[row][col] == 0) {
            openSite(&p, row, col);
            nOpenSites++;
            i++;
            printf("Open site: (%d, %d)\n", row, col);  
            printGrid(&p); 
            printf("\n");
        }
    }

    if (percolates(&p)) {
        printf("The system percolates! Open sites: %d\n", nOpenSites);
    } else {
        printf("The system does not percolate. Open sites: %d\n", nOpenSites);
    }

    return 0;
}