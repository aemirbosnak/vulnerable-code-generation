//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to randomly generate either an open or closed site
int generate_site() {
    int rand_num = rand() % 2;
    if (rand_num == 0) {
        return 0; // closed site
    } else {
        return 1; // open site
    }
}

// Function to print the grid
void print_grid(int **grid, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 1) {
                printf("O "); // open site
            } else {
                printf("X "); // closed site
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the percolation has occurred
int percolation_check(int **grid, int size) {
    int top_open = 0;
    int bottom_open = 0;
    // Check top row
    for (int i = 0; i < size; i++) {
        if (grid[0][i] == 1) {
            top_open = 1;
            break;
        }
    }
    // Check bottom row
    for (int i = 0; i < size; i++) {
        if (grid[size-1][i] == 1) {
            bottom_open = 1;
            break;
        }
    }
    // If both top and bottom are open, then there is percolation
    if (top_open == 1 && bottom_open == 1) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    int size;
    printf("Enter the size of the grid: ");
    scanf("%d", &size);
    int **grid = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(size * sizeof(int));
    }
    srand(time(NULL)); // Seed the random number generator with current time
    // Initialize the grid with open or closed sites
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = generate_site();
        }
    }
    print_grid(grid, size);
    // Iterate through the grid and randomly open sites until percolation occurs
    int percolation = 0;
    while (percolation == 0) {
        int rand_i = rand() % size;
        int rand_j = rand() % size;
        if (grid[rand_i][rand_j] == 0) {
            grid[rand_i][rand_j] = 1;
        }
        percolation = percolation_check(grid, size);
    }
    print_grid(grid, size);
    printf("Percolation has occurred!\n");
    // Free the memory allocated for the grid
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}