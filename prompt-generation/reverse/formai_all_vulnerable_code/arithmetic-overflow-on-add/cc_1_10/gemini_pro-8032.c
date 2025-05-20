//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Tower of Hanoi problem solution using recursion
// with move, print and reset functions

// Define the tower structure
typedef struct Tower {
    int numDisks;
    int *disks;
} Tower;

// Function to move a disk from one tower to another
void move(Tower *from, Tower *to) {
    // Check if there are any disks to move
    if (from->numDisks == 0) {
        return;
    }

    // Move the top disk from the from tower to the to tower
    to->disks[to->numDisks++] = from->disks[--from->numDisks];
}

// Function to print the current state of the towers
void printTowers(Tower *towers, int numTowers) {
    // Iterate over each tower
    for (int i = 0; i < numTowers; i++) {
        // Iterate over each disk in the tower
        for (int j = 0; j < towers[i].numDisks; j++) {
            // Print the disk size
            printf("%d ", towers[i].disks[j]);
        }

        // Print a newline character
        printf("\n");
    }

    // Print a newline character
    printf("\n");
}

// Function to reset the towers to their initial state
void resetTowers(Tower *towers, int numTowers) {
    // Iterate over each tower
    for (int i = 0; i < numTowers; i++) {
        // Set the number of disks in the tower to 0
        towers[i].numDisks = 0;

        // Free the memory allocated for the disks in the tower
        free(towers[i].disks);
    }
}

// Function to solve the Tower of Hanoi problem
void solveTowerOfHanoi(Tower *towers, int numTowers, int numDisks) {
    // Check if the number of disks is valid
    if (numDisks <= 0) {
        return;
    }

    // Allocate memory for the disks in each tower
    for (int i = 0; i < numTowers; i++) {
        towers[i].disks = malloc(sizeof(int) * numDisks);
    }

    // Set the number of disks in the first tower to the number of disks
    towers[0].numDisks = numDisks;

    // Iterate over each disk
    for (int i = numDisks; i > 0; i--) {
        // Move the disk from the first tower to the second tower
        move(&towers[0], &towers[1]);

        // Print the current state of the towers
        printTowers(towers, numTowers);

        // Move the disk from the second tower to the third tower
        move(&towers[1], &towers[2]);

        // Print the current state of the towers
        printTowers(towers, numTowers);

        // Move the disk from the first tower to the second tower
        move(&towers[0], &towers[1]);

        // Print the current state of the towers
        printTowers(towers, numTowers);
    }

    // Reset the towers to their initial state
    resetTowers(towers, numTowers);
}

int main() {
    // Define the number of towers and disks
    int numTowers = 3;
    int numDisks = 4;

    // Define the towers
    Tower towers[numTowers];

    // Solve the Tower of Hanoi problem
    solveTowerOfHanoi(towers, numTowers, numDisks);

    return 0;
}