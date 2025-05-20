//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Function to print the instructions
void printInstructions() {
    printf("The Tower of Hanoi is a classic puzzle game that involves moving disks between three towers.\n");
    printf("The goal is to move all the disks from the left tower to the right tower, following these rules:\n");
    printf("1. You can only move one disk at a time.\n");
    printf("2. You can only move a disk to a tower that is either empty or has a larger disk on top of it.\n");
    printf("3. You cannot move a larger disk onto a smaller disk.\n\n");
}

// Function to get the number of disks from the user
int getNumberOfDisks() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    return numDisks;
}

// Function to move a single disk from one tower to another
void moveDisk(int disk, char fromTower, char toTower) {
    printf("Move disk %d from tower %c to tower %c\n", disk, fromTower, toTower);
}

// Function to solve the Tower of Hanoi problem recursively
void solveTowerOfHanoi(int numDisks, char fromTower, char toTower, char auxTower) {
    // Base case: no disks to move
    if (numDisks == 0) {
        return;
    }

    // Move the top n-1 disks from the fromTower to the auxTower
    solveTowerOfHanoi(numDisks - 1, fromTower, auxTower, toTower);

    // Move the nth disk from the fromTower to the toTower
    moveDisk(numDisks, fromTower, toTower);

    // Move the n-1 disks from the auxTower to the toTower
    solveTowerOfHanoi(numDisks - 1, auxTower, toTower, fromTower);
}

int main() {
    // Print the instructions
    printInstructions();

    // Get the number of disks from the user
    int numDisks = getNumberOfDisks();

    // Solve the Tower of Hanoi problem
    solveTowerOfHanoi(numDisks, 'A', 'C', 'B');

    return 0;
}