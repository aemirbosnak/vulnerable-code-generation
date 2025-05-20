//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int alive;
} Cell;

int main(int argc, char **argv) {
    srand(time(NULL)); // Seed the random number generator

    int width = 100; // Width of the grid
    int height = 100; // Height of the grid
    int numCells = width * height; // Total number of cells

    Cell *grid = (Cell*)malloc(numCells * sizeof(Cell)); // Allocate memory for the grid

    // Initialize the grid with random values
    for (int i = 0; i < numCells; i++) {
        grid[i].x = i % width; // Calculate the x-coordinate of the cell
        grid[i].y = i / width; // Calculate the y-coordinate of the cell
        grid[i].alive = rand() % 2 == 0; // Set the cell's alive flag to 1 with 50% probability
    }

    int maxIterations = 1000; // Maximum number of iterations
    int iteration = 0; // Current iteration counter

    // Update the grid in an asynchronous manner
    while (iteration < maxIterations) {
        // Update the grid for each cell
        for (int i = 0; i < numCells; i++) {
            int neighbors = 0;

            // Count the number of live neighbors for each cell
            for (int j = -1; j < 2; j++) {
                if (grid[i].x + j >= 0 && grid[i].x + j < width &&
                    grid[i].y + j >= 0 && grid[i].y + j < height) {
                    neighbors++; // Increment the neighbor count if the cell is alive
                }
            }

            if (grid[i].alive) { // If the cell is alive
                if (neighbors < 2 || neighbors > 3) { // If the cell has too few or too many neighbors
                    grid[i].alive = 0; // Set the cell's alive flag to 0
                }
            } else { // If the cell is dead
                if (neighbors == 3) { // If the cell has exactly 3 neighbors
                    grid[i].alive = 1; // Set the cell's alive flag to 1
                }
            }
        }

        // Print the updated grid
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (grid[i * height + j].alive) { // If the cell is alive
                    printf("*"); // Print a star
                } else {
                    printf(" "); // Print a space
                }
            }
            printf("\n");
        }

        iteration++; // Increment the iteration counter

        if (iteration % 100 == 0) {
            printf("Iteration %d\n", iteration); // Print the current iteration number
        }

        usleep(10000); // Wait for 10 milliseconds
    }

    printf("Final grid:\n");
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (grid[i * height + j].alive) { // If the cell is alive
                printf("*"); // Print a star
            } else {
                printf(" "); // Print a space
            }
        }
        printf("\n");
    }

    free(grid); // Free the memory allocated for the grid

    return 0;
}