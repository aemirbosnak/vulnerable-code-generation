//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int grid[MAX_SIZE][MAX_SIZE];
    int size;
} Percolation;

void initializePercolation(Percolation *p, int size) {
    p->size = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = 0; // 0 represents blocked site
        }
    }
}

void displayGrid(Percolation *p) {
    printf("\nPercolation grid:\n");
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

void openSite(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        p->grid[row][col] = 1; // 1 represents open site
    }
}

int isOpen(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        return p->grid[row][col] == 1;
    }
    return 0;
}

int isFull(Percolation *p, int row, int col) {
    return isOpen(p, row, col) && (row == 0 || isFull(p, row - 1, col));
}

int percolates(Percolation *p) {
    for (int col = 0; col < p->size; col++) {
        if (isFull(p, p->size - 1, col)) {
            return 1; // The system percolates
        }
    }
    return 0; // The system does not percolate
}

void simulatePercolation(Percolation *p, float probability) {
    srand(time(NULL));
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if ((float)rand() / RAND_MAX < probability) {
                openSite(p, i, j);
            }
        }
    }
}

void runSimulation(int size, float probability) {
    Percolation p;
    initializePercolation(&p, size);
    simulatePercolation(&p, probability);
    displayGrid(&p);
    
    if (percolates(&p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
}

int main() {
    int size;
    float probability;

    printf("Enter the size of the grid (1 to %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if(size < 1 || size > MAX_SIZE) {
        printf("Size must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }
    
    printf("Enter the probability of opening a site (0.0 to 1.0): ");
    scanf("%f", &probability);
    
    if (probability < 0.0 || probability > 1.0) {
        printf("Probability must be between 0.0 and 1.0.\n");
        return 1;
    }

    runSimulation(size, probability);
    return 0;
}