//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Function to print the current state of the towers
void printTowers(int numDisks, int towers[][numDisks]) {
    for (int disk = numDisks - 1; disk >= 0; disk--) {
        for (int tower = 0; tower < numDisks; tower++) {
            printf("%d ", towers[disk][tower]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to move a disk from one tower to another
void moveDisk(int numDisks, int towers[][numDisks], int fromTower, int toTower) {
    // Find the index of the top disk on the from tower
    int fromDiskIndex = -1;
    for (int disk = 0; disk < numDisks; disk++) {
        if (towers[disk][fromTower] != 0) {
            fromDiskIndex = disk;
            break;
        }
    }

    // Find the index of the top disk on the to tower
    int toDiskIndex = -1;
    for (int disk = 0; disk < numDisks; disk++) {
        if (towers[disk][toTower] != 0) {
            toDiskIndex = disk;
            break;
        }
    }

    // Move the disk from the from tower to the to tower
    towers[fromDiskIndex][fromTower] = 0;
    towers[toDiskIndex][toTower] = numDisks - fromDiskIndex;
}

// Function to solve the Tower of Hanoi problem
void solveTowers(int numDisks, int towers[][numDisks], int fromTower, int toTower, int auxTower) {
    // If there are only 1 disk, move it from the from tower to the to tower
    if (numDisks == 1) {
        moveDisk(numDisks, towers, fromTower, toTower);
        return;
    }

    // Move the top numDisks - 1 disks from the from tower to the aux tower
    solveTowers(numDisks - 1, towers, fromTower, auxTower, toTower);

    // Move the remaining disk from the from tower to the to tower
    moveDisk(numDisks, towers, fromTower, toTower);

    // Move the numDisks - 1 disks from the aux tower to the to tower
    solveTowers(numDisks - 1, towers, auxTower, toTower, fromTower);
}

int main() {
    // Get the number of disks from the user
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Create an array to represent the towers
    int towers[numDisks][numDisks];

    // Initialize the towers
    for (int disk = 0; disk < numDisks; disk++) {
        for (int tower = 0; tower < numDisks; tower++) {
            towers[disk][tower] = 0;
        }
    }

    // Place the disks on the first tower
    for (int disk = numDisks - 1; disk >= 0; disk--) {
        towers[disk][0] = numDisks - disk;
    }

    // Print the initial state of the towers
    printf("Initial state of the towers:\n");
    printTowers(numDisks, towers);

    // Solve the Tower of Hanoi problem
    solveTowers(numDisks, towers, 0, 2, 1);

    // Print the final state of the towers
    printf("Final state of the towers:\n");
    printTowers(numDisks, towers);

    return 0;
}