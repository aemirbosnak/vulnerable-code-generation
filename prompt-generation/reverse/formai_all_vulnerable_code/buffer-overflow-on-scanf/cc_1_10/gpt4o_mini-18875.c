//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Specify the grid size
#define OPEN 1  // Cell status for open
#define BLOCKED 0 // Cell status for blocked

// Create a structure to hold grid information
typedef struct {
    int **grid;
    int size;
} PercolationGrid;

// Function prototypes
PercolationGrid* createGrid(int size);
void freeGrid(PercolationGrid* pg);
void displayGrid(PercolationGrid* pg);
void fillGridRandomly(PercolationGrid* pg, float probability);
int isConnected(PercolationGrid* pg, int row1, int col1, int row2, int col2);
int percolates(PercolationGrid* pg);
void simulatePercolation(float probability);

int main() {
    srand(time(0)); // Seed for random number generation
    float probability;

    printf("Enter the probability (0.0 to 1.0) that a cell is open: ");
    scanf("%f", &probability);

    if(probability < 0.0 || probability > 1.0) {
        printf("Probability should be between 0.0 and 1.0.\n");
        return 1;
    }

    simulatePercolation(probability);
    
    return 0;
}

void simulatePercolation(float probability) {
    PercolationGrid* pg = createGrid(SIZE);
    fillGridRandomly(pg, probability);
    displayGrid(pg);
    
    // Check for percolation from top to bottom
    if(percolates(pg)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate!\n");
    }

    freeGrid(pg);
}
PercolationGrid* createGrid(int size) {
    PercolationGrid* pg = (PercolationGrid*)malloc(sizeof(PercolationGrid));
    pg->size = size;

    pg->grid = (int**)malloc(size * sizeof(int*));
    for(int i = 0; i < size; i++) {
        pg->grid[i] = (int*)malloc(size * sizeof(int));
    }

    return pg;
}

void freeGrid(PercolationGrid* pg) {
    for(int i = 0; i < pg->size; i++) {
        free(pg->grid[i]);
    }
    free(pg->grid);
    free(pg);
}

void fillGridRandomly(PercolationGrid* pg, float probability) {
    for(int i = 0; i < pg->size; i++) {
        for(int j = 0; j < pg->size; j++) {
            pg->grid[i][j] = (rand() / (float)RAND_MAX) < probability ? OPEN : BLOCKED;
        }
    }
}

void displayGrid(PercolationGrid* pg) {
    printf("Grid:\n");
    for(int i = 0; i < pg->size; i++) {
        for(int j = 0; j < pg->size; j++) {
            printf("%d ", pg->grid[i][j]);
        }
        printf("\n");
    }
}

int isConnected(PercolationGrid* pg, int row1, int col1, int row2, int col2) {
    // Basic bounds checking
    if(row1 < 0 || row1 >= pg->size || col1 < 0 || col1 >= pg->size ||
       row2 < 0 || row2 >= pg->size || col2 < 0 || col2 >= pg->size) {
        return 0; // Out of bounds
    }
    return (pg->grid[row1][col1] == OPEN && pg->grid[row2][col2] == OPEN);
}

int percolates(PercolationGrid* pg) {
    for(int col = 0; col < pg->size; col++) {
        if(pg->grid[0][col] == OPEN) { // Start from the top row
            for(int row = 0; row < pg->size; row++) {
                if(isConnected(pg, row, col, row + 1, col) && row + 1 < pg->size) {
                    if (row == pg->size - 1) return 1; // Reached bottom
                }
            }
        }
    }
    return 0; // No percolation
}