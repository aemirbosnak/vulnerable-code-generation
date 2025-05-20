//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Function to print the current state of the towers
void printTowers(int **towers, int numDisks) {
    for (int i = 0; i < numDisks; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", towers[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to move a disk from one tower to another
void moveDisk(int **towers, int disk, int fromTower, int toTower) {
    // Check if the move is valid
    if (disk > towers[0][fromTower] || disk > towers[0][toTower]) {
        printf("Invalid move\n");
        return;
    }

    // Move the disk
    towers[disk - 1][toTower] = disk;
    towers[disk - 1][fromTower] = 0;
}

// Function to solve the Tower of Hanoi problem
void solveTowerOfHanoi(int **towers, int numDisks) {
    // Check if the number of disks is valid
    if (numDisks <= 0) {
        printf("Invalid number of disks\n");
        return;
    }

    // Initialize the towers
    for (int i = 0; i < numDisks; i++) {
        towers[i][0] = i + 1;
        towers[i][1] = 0;
        towers[i][2] = 0;
    }

    // Print the initial state of the towers
    printTowers(towers, numDisks);

    // Solve the problem
    int steps = 0;
    while (towers[numDisks - 1][2] != numDisks) {
        // Check if the top disk on tower 1 can be moved to tower 2 or 3
        if (towers[0][1] == 0 || towers[towers[0][1] - 1][2] > towers[0][1]) {
            moveDisk(towers, towers[0][1], 1, 2);
            steps++;
        } else if (towers[0][2] == 0 || towers[towers[0][2] - 1][2] > towers[0][2]) {
            moveDisk(towers, towers[0][2], 1, 3);
            steps++;
        }

        // Check if the top disk on tower 2 can be moved to tower 1 or 3
        if (towers[0][2] == 0 || towers[towers[0][2] - 1][2] > towers[0][2]) {
            moveDisk(towers, towers[0][2], 2, 1);
            steps++;
        } else if (towers[0][1] == 0 || towers[towers[0][1] - 1][2] > towers[0][1]) {
            moveDisk(towers, towers[0][1], 2, 3);
            steps++;
        }

        // Check if the top disk on tower 3 can be moved to tower 1 or 2
        if (towers[0][1] == 0 || towers[towers[0][1] - 1][2] > towers[0][1]) {
            moveDisk(towers, towers[0][1], 3, 1);
            steps++;
        } else if (towers[0][2] == 0 || towers[towers[0][2] - 1][2] > towers[0][2]) {
            moveDisk(towers, towers[0][2], 3, 2);
            steps++;
        }

        // Print the current state of the towers
        printTowers(towers, numDisks);
    }

    // Print the number of steps required to solve the problem
    printf("Number of steps: %d\n", steps);
}

// Main function
int main() {
    // Get the number of disks from the user
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Allocate memory for the towers
    int **towers = malloc(sizeof(int *) * numDisks);
    for (int i = 0; i < numDisks; i++) {
        towers[i] = malloc(sizeof(int) * 3);
    }

    // Solve the Tower of Hanoi problem
    solveTowerOfHanoi(towers, numDisks);

    // Free the memory allocated for the towers
    for (int i = 0; i < numDisks; i++) {
        free(towers[i]);
    }
    free(towers);

    return 0;
}