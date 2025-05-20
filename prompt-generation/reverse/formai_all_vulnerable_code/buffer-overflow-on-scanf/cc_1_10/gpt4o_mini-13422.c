//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
#include <stdio.h>

void moveDisk(int disk, char source, char destination) {
    printf("Move disk %d from %c to %c\n", disk, source, destination);
}

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        // Base case: Move one disk from source to destination
        moveDisk(1, source, destination);
        return;
    }
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);
    // Move the nth disk from source to destination
    moveDisk(n, source, destination);
    // Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

void printInstructions() {
    printf("Welcome to the Tower of Hanoi Simulator!\n");
    printf("The objective of the game is to move all the disks from the source rod to the destination rod.\n");
    printf("You can only move one disk at a time, and a disk can only be placed on top of a larger disk.\n");
    printf("The rods are labeled as follows:\n");
    printf("Source Rod: A\n");
    printf("Destination Rod: C\n");
    printf("Auxiliary Rod: B\n");
}

int main() {
    int numOfDisks;

    // Print the welcome message and instructions
    printInstructions();

    // Ask user for the number of disks
    printf("\nEnter the number of disks (1-9): ");
    scanf("%d", &numOfDisks);

    // Validation of the number of disks
    if (numOfDisks < 1 || numOfDisks > 9) {
        printf("Please enter a valid number of disks between 1 and 9.\n");
        return 1;
    }

    // Call the towerOfHanoi function to solve the problem
    printf("\nThe sequence of moves involved in the Tower of Hanoi:\n");
    towerOfHanoi(numOfDisks, 'A', 'B', 'C');

    return 0;
}