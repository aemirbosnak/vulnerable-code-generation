//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: calm
/*
 * Percolation Simulator
 *
 * This program simulates the percolation of water through a network of pipes.
 * The program takes a number of pipes and a probability of each pipe being blocked
 * as input, and then simulates the percolation process until the entire network
 * is filled with water.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a pipe
typedef struct {
    int blocked; // 0 if unblocked, 1 if blocked
} Pipe;

// Function to simulate the percolation process
void percolate(int n, double p, Pipe *pipes) {
    int i, j;
    int filled = 0;
    while (filled < n) {
        // Choose a random pipe
        i = rand() % n;
        // If the pipe is not blocked, fill it with water
        if (pipes[i].blocked == 0) {
            pipes[i].blocked = 1;
            filled++;
        }
        // If the pipe is blocked, try another pipe
        else {
            continue;
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Parse command-line arguments
    int n = atoi(argv[1]);
    double p = atof(argv[2]);

    // Initialize pipes
    Pipe *pipes = (Pipe *) malloc(n * sizeof(Pipe));
    for (int i = 0; i < n; i++) {
        pipes[i].blocked = 0;
    }

    // Simulate percolation
    percolate(n, p, pipes);

    // Print results
    printf("The network is filled with water after %d pipes are blocked.\n", n);

    // Free memory
    free(pipes);

    return 0;
}