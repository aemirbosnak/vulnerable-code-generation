//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int grid[MAX_SIZE][MAX_SIZE];
    int size;
} Percolation;

void initialize(Percolation *p, int size) {
    if (size > MAX_SIZE) {
        fprintf(stderr, "Error: Size exceeds maximum allowed.\n");
        exit(EXIT_FAILURE);
    }
    p->size = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = 0; // 0 for blocked site
        }
    }
}

void open_site(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) {
        fprintf(stderr, "Error: Site out of bounds.\n");
        return;
    }
    p->grid[row][col] = 1; // 1 for open site
}

int is_open(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) {
        return 0;
    }
    return p->grid[row][col];
}

int is_full(Percolation *p, int row, int col) {
    return is_open(p, row, col) && row == 0; // Simplified full check for the top row
}

int percolates(Percolation *p) {
    for (int j = 0; j < p->size; j++) {
        if (is_open(p, p->size - 1, j)) {
            return 1; // Found an open site in the bottom row
        }
    }
    return 0; // No open paths to the bottom
}

void print_grid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

void random_percolation(Percolation *p, float probability) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if ((float)rand() / RAND_MAX < probability) {
                open_site(p, i, j);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    
    int size;
    float probability;

    printf("Enter the grid size (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    printf("Enter the probability of opening a site (0.0 to 1.0): ");
    scanf("%f", &probability);
    
    Percolation p;
    initialize(&p, size);
    
    random_percolation(&p, probability);
    
    printf("\nGenerated percolation grid:\n");
    print_grid(&p);
    
    if (percolates(&p)) {
        printf("\nThe system percolates!\n");
    } else {
        printf("\nThe system does not percolate.\n");
    }

    return 0;
}