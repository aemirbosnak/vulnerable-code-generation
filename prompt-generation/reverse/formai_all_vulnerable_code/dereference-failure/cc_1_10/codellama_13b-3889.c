//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
/*
 * Percolation Simulator
 *
 * This program simulates the percolation of a system with a given probability of
 * a site being open. The program takes in a number of rows and columns as
 * input, and outputs the number of sites that are connected to the top row.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PERCOLATION_PROBABILITY 0.5

// Structure to represent a site
typedef struct {
    int is_open;
    int is_connected_to_top;
} Site;

// Structure to represent a system
typedef struct {
    int rows;
    int cols;
    Site** sites;
} System;

// Initialize a system with a given number of rows and columns
void init_system(System* system, int rows, int cols) {
    system->rows = rows;
    system->cols = cols;
    system->sites = (Site**)malloc(rows * sizeof(Site*));
    for (int i = 0; i < rows; i++) {
        system->sites[i] = (Site*)malloc(cols * sizeof(Site));
        for (int j = 0; j < cols; j++) {
            system->sites[i][j].is_open = rand() / (RAND_MAX + 1.0) < PERCOLATION_PROBABILITY;
            system->sites[i][j].is_connected_to_top = 0;
        }
    }
}

// Check if a site is connected to the top row
int is_connected_to_top(System* system, int row, int col) {
    return system->sites[row][col].is_open &&
           (row == 0 ||
            (row > 0 && system->sites[row - 1][col].is_connected_to_top));
}

// Update the connected-to-top state of a site
void update_connected_to_top(System* system, int row, int col) {
    if (is_connected_to_top(system, row, col)) {
        system->sites[row][col].is_connected_to_top = 1;
    }
}

// Simulate the percolation of a system
void simulate(System* system) {
    for (int i = 0; i < system->rows; i++) {
        for (int j = 0; j < system->cols; j++) {
            update_connected_to_top(system, i, j);
        }
    }
}

// Print the number of connected sites
void print_connected_sites(System* system) {
    int count = 0;
    for (int i = 0; i < system->rows; i++) {
        for (int j = 0; j < system->cols; j++) {
            if (system->sites[i][j].is_connected_to_top) {
                count++;
            }
        }
    }
    printf("%d\n", count);
}

int main() {
    srand(time(NULL));

    System system;
    init_system(&system, 10, 10);

    simulate(&system);
    print_connected_sites(&system);

    return 0;
}