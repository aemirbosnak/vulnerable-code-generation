//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to move disks between towers
void moveDisk(int n, char fromTower, char toTower) {
    printf("Move disk %d from %c to %c\n", n, fromTower, toTower);
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char fromTower, char toTower, char auxTower) {
    // Base case: Move a single disk directly
    if (n == 1) {
        moveDisk(n, fromTower, toTower);
        return;
    }
    // Move n-1 disks from source to auxiliary tower
    towerOfHanoi(n - 1, fromTower, auxTower, toTower);
    
    // Move the nth disk to target tower
    moveDisk(n, fromTower, toTower);
    
    // Move the n-1 disks from auxiliary tower to target tower
    towerOfHanoi(n - 1, auxTower, toTower, fromTower);
}

// Driver function
int main() {
    int numOfDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numOfDisks);

    if (numOfDisks <= 0) {
        printf("Number of disks must be a positive integer.\n");
        return 1;
    }

    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towerOfHanoi(numOfDisks, 'A', 'C', 'B');

    return 0;
}

// Additional functions for output formatting
void printTowerState(int numOfDisks, char towerA, char towerB, char towerC) {
    printf("\nCurrent Tower State:\n");
    printf("Tower %c: ", towerA);
    for (int i = numOfDisks; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\nTower %c: ", towerB);
    for (int i = numOfDisks; i >= 1; i--) {
        printf("%d ", 0);
    }
    printf("\nTower %c: ", towerC);
    for (int i = numOfDisks; i >= 1; i--) {
        printf("%d ", 0);
    }
}

void printFinalState(int numOfDisks, char towerSource, char towerDestination) {
    printf("\nFinal State of Towers:\n");
    printf("Tower %c: ", towerSource);
    for (int i = numOfDisks; i >= 1; i--) {
        printf("%d ", 0);
    }
    printf("\nTower %c: ", towerDestination);
    for (int i = numOfDisks; i >= 1; i--) {
        printf("%d ", i); // All disks should be on Destination
    }
    printf("\n");
}

// An extended version of the main to demonstrate tower states
int main_extended() {
    int numOfDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numOfDisks);

    if (numOfDisks <= 0) {
        printf("Number of disks must be a positive integer.\n");
        return 1;
    }

    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towerOfHanoi(numOfDisks, 'A', 'C', 'B');

    printFinalState(numOfDisks, 'A', 'C');

    return 0;
}