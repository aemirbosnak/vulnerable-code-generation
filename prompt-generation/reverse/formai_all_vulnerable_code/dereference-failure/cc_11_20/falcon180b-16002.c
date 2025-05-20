//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 20
#define DROP_RATE 0.5
#define INIT_DENSITY 0.2
#define NUM_DROPS 100

int main() {
    int rows, cols;
    double density;
    int **grid;
    int drops = 0;
    int i, j, k;
    int count = 0;
    int total_drops = 0;

    srand(time(NULL));

    // Initialize the grid with random values
    grid = (int **)malloc(MAX_ROWS * sizeof(int *));
    for (i = 0; i < MAX_ROWS; i++) {
        grid[i] = (int *)malloc(MAX_COLS * sizeof(int));
        for (j = 0; j < MAX_COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Initialize the density
    density = INIT_DENSITY;

    // Percolate the water
    while (density > 0 && drops < NUM_DROPS) {
        // Find a random cell to drop water on
        i = rand() % MAX_ROWS;
        j = rand() % MAX_COLS;

        // Check if the cell is already occupied
        if (grid[i][j] == 1) {
            continue;
        }

        // Check if the cell is on the bottom row
        if (i == MAX_ROWS - 1) {
            continue;
        }

        // Check if the cell below is occupied
        if (grid[i + 1][j] == 1) {
            continue;
        }

        // Check if the cell to the left is occupied
        if (grid[i][j - 1] == 1) {
            continue;
        }

        // Check if the cell to the right is occupied
        if (grid[i][j + 1] == 1) {
            continue;
        }

        // Drop water on the cell
        grid[i][j] = 1;
        density -= DROP_RATE;
        drops++;

        // Check if the cell below is empty
        if (grid[i + 1][j] == 0) {
            // Percolate the water down
            grid[i + 1][j] = 1;
            total_drops++;
        }

        // Check if the cell to the left is empty
        if (grid[i][j - 1] == 0) {
            // Percolate the water left
            grid[i][j - 1] = 1;
            total_drops++;
        }

        // Check if the cell to the right is empty
        if (grid[i][j + 1] == 0) {
            // Percolate the water right
            grid[i][j + 1] = 1;
            total_drops++;
        }
    }

    // Print the results
    printf("Total drops: %d\n", total_drops);
    printf("Drops on last cell: %d\n", drops);

    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (grid[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < MAX_ROWS; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}