//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // Size of the grid
#define EMPTY 0
#define BLOCKED 1
#define FLOWING_WATER 2

int grid[SIZE][SIZE];
int is_percolating = 0;

void initialize_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
}

void print_grid() {
    printf("\nCurrent Grid State:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == EMPTY) printf(" . ");
            else if (grid[i][j] == BLOCKED) printf(" # ");
            else printf(" ~ ");
        }
        printf("\n");
    }
    printf("\n");
}

void generate_blocks(float block_probability) {
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((float)rand() / RAND_MAX < block_probability) {
                grid[i][j] = BLOCKED;
            }
        }
    }
}

void flow(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || grid[x][y] != EMPTY) return;

    // Mark this cell as flowing water
    grid[x][y] = FLOWING_WATER;
    
    // Recursive calls to the neighboring cells
    flow(x - 1, y); // Up
    flow(x + 1, y); // Down
    flow(x, y - 1); // Left
    flow(x, y + 1); // Right
}

void check_percolation() {
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j] == EMPTY) {
            flow(0, j); // Start flowing from the top row
        }
    }

    // Checking if there is any FLOWING_WATER in the last row
    for (int j = 0; j < SIZE; j++) {
        if (grid[SIZE-1][j] == FLOWING_WATER) {
            is_percolating = 1;
            return;
        }
    }
}

int main() {
    printf("Welcome to the C Percolation Simulator!\n");
    float block_probability;
    printf("Enter the probability of a block (0.0 to 1.0): ");
    scanf("%f", &block_probability);
    if (block_probability < 0 || block_probability > 1) {
        printf("Invalid probability. Exiting...\n");
        return EXIT_FAILURE;
    }

    initialize_grid();
    generate_blocks(block_probability);
    print_grid();
    check_percolation();

    if (is_percolating) {
        printf("Water percolates to the bottom!\n");
    } else {
        printf("Water does not percolate to the bottom.\n");
    }

    // Cleanup and final display
    printf("Here's the final grid with water flow shown:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == EMPTY) printf(" . ");
            else if (grid[i][j] == BLOCKED) printf(" # ");
            else printf(" ~ ");
        }
        printf("\n");
    }
    
    return EXIT_SUCCESS;
}