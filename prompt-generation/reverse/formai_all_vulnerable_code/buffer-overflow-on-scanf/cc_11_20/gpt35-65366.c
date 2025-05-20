//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int grid[10][10], count = 0;
    float threshold;

    // Prompt user for probability threshold
    printf("Enter a probability threshold between 0 and 1: ");
    scanf("%f", &threshold);

    // Set up random number generator
    srand((unsigned) time(NULL));

    // Initialize grid
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            float r = (float) rand() / RAND_MAX;
            if (r < threshold) {
                grid[i][j] = 1; // Set site open
                count++; // Increment number of open sites
            } else {
                grid[i][j] = 0; // Set site blocked
            }
        }
    }

    // Print initial grid
    printf("\nInitial grid:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Perform percolation
    while (1) {
        int connected[10][10] = {0}; // Grid to store connected sites
        int visited[10][10] = {0}; // Grid to mark visited sites
        int top_connected = 0, bottom_connected = 0;

        // Perform depth-first search to find connected sites from top row
        for (int j = 0; j < 10; j++) {
            if (grid[0][j] == 1 && visited[0][j] == 0) {
                connected[0][j] = 1;
                visited[0][j] = 1;

                // We've found a connected site in the top row
                top_connected = 1;
            }
        }
        for (int j = 0; j < 10; j++) {
            if (connected[0][j] == 1) {
                if (visited[1][j] == 0 && grid[1][j] == 1) {
                    connected[1][j] = 1;
                    visited[1][j] = 1;
                }
            }
        }
        for (int i = 1; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                if (connected[i][j] == 1) {
                    if (visited[i-1][j] == 0 && grid[i-1][j] == 1) {
                        connected[i-1][j] = 1;
                        visited[i-1][j] = 1;
                    }
                    if (visited[i+1][j] == 0 && grid[i+1][j] == 1) {
                        connected[i+1][j] = 1;
                        visited[i+1][j] = 1;
                    }
                    if (j > 0 && visited[i][j-1] == 0 && grid[i][j-1] == 1) {
                        connected[i][j-1] = 1;
                        visited[i][j-1] = 1;
                    }
                    if (j < 9 && visited[i][j+1] == 0 && grid[i][j+1] == 1) {
                        connected[i][j+1] = 1;
                        visited[i][j+1] = 1;
                    }
                }
            }
        }
        for (int j = 0; j < 10; j++) {
            if (connected[8][j] == 1 && grid[9][j] == 1) {
                connected[9][j] = 1;

                // We've found a connected site in the bottom row
                bottom_connected = 1;
            }
        }

        // Check if percolation has occurred
        if (top_connected && bottom_connected) {
            printf("\nPercolation threshold reached!\n");
            printf("Number of open sites: %d\n", count);
            printf("Final grid:\n");
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (connected[i][j] == 1) {
                        printf("* ");
                    } else {
                        printf("%d ", grid[i][j]);
                    }
                }
                printf("\n");
            }
            break;
        }

        // If percolation has not occurred, randomly open a blocked site
        int random_index = rand() % count;
        int current_index = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (grid[i][j] == 0) {
                    if (current_index == random_index) {
                        grid[i][j] = 1;
                        count++;
                    }
                    current_index++;
                }
            }
        }
    }

    return 0;
}