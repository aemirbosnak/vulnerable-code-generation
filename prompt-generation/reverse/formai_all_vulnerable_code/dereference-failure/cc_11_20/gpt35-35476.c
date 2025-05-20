//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the grid
void printGrid(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 0) {
                printf(". ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    int size = 20;  // Size of the grid
    double p = 0.6;  // Probability of a site being open
    int **grid = (int **)malloc(size * sizeof(int *));  // 2D array to represent the grid

    // Allocate memory for the grid
    for (int i = 0; i < size; i++) {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the grid with closed sites (0)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }

    // Open the sites randomly based on the probability p
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            double r = (double)rand() / RAND_MAX;  // Generate a random number between 0 and 1
            if (r < p) {
                grid[i][j] = 1;  // Open the site
            }
        }
    }

    printf("Initial grid:\n");
    printGrid(grid, size);  // Print the initial grid

    // Perform the percolation test
    int connected = 0;  // Flag to check if the top and bottom of the grid are connected
    int *open = (int *)malloc(size * size * sizeof(int));  // 1D array to keep track of open sites
    int *visited = (int *)malloc(size * size * sizeof(int));  // 1D array to keep track of visited sites
    int top = size * size;  // Index of the virtual top site
    int bottom = size * size + 1;  // Index of the virtual bottom site
    for (int i = 0; i < size * size; i++) {
        visited[i] = 0;  // Mark all sites as unvisited
        if (grid[i / size][i % size] == 1) {
            open[i] = 1;  // Mark the site as open
        } else {
            open[i] = 0;  // Mark the site as closed
        }
    }
    open[top] = 1;  // Open the virtual top site
    open[bottom] = 1;  // Open the virtual bottom site
    visited[top] = 1;  // Mark the virtual top site as visited

    // DFS to find the path from the virtual top site to the virtual bottom site
    int stack[size * size];  // Use a stack to perform DFS
    stack[0] = top;  // Push the virtual top site onto the stack
    int topIndex = 0;  // Index of the top of the stack
    while (topIndex >= 0) {
        int current = stack[topIndex];  // Pop the top element from the stack
        topIndex--;
        visited[current] = 1;  // Mark the current site as visited
        if (current == bottom) {
            connected = 1;  // The top and bottom of the grid are connected
            break;
        }
        // Check the neighbors of the current site
        if (current % size != size - 1 && open[current + 1] && !visited[current + 1]) {
            stack[++topIndex] = current + 1;  // Push the right site onto the stack
        }
        if (current % size != 0 && open[current - 1] && !visited[current - 1]) {
            stack[++topIndex] = current - 1;  // Push the left site onto the stack
        }
        if (current / size != size - 1 && open[current + size] && !visited[current + size]) {
            stack[++topIndex] = current + size;  // Push the lower site onto the stack
        }
        if (current / size != 0 && open[current - size] && !visited[current - size]) {
            stack[++topIndex] = current - size;  // Push the upper site onto the stack
        }
    }

    printf("Final grid:\n");
    printGrid(grid, size);  // Print the final grid

    if (connected) {
        printf("The top and bottom of the grid are connected.\n");
    } else {
        printf("The top and bottom of the grid are not connected.\n");
    }

    // Free the memory allocated for the grid, open array, and visited array
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);
    free(open);
    free(visited);

    return 0;
}