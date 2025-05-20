//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Function to perform the Tower of Hanoi algorithm
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case: If there is only one disk, move it from source to destination
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    // Move n-1 disks from source to auxiliary, using destination as auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    // Move the n-1 disks from auxiliary to destination, using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Utility function to fetch the number of disks from the user
int getNumberOfDisks() {
    int n;
    printf("Enter the number of disks: ");
    while (1) {
        scanf("%d", &n);
        if (n > 0) {
            break;
        }
        printf("Please enter a valid number greater than 0: ");
    }
    return n;
}

// Function to print the current state of the towers
void printTowersState(int numDisks, char towerA, char towerB, char towerC) {
    printf("\nCurrent State of the Towers:\n");
    printf("Tower %c: ", towerA);
    for (int i = 1; i <= numDisks; i++) {
        printf("[Disk %d] ", i);
    }
    printf("\nTower %c: ", towerB);
    for (int i = 1; i <= numDisks; i++) {
        printf("[Disk %d] ", i);
    }
    printf("\nTower %c: ", towerC);
    for (int i = 1; i <= numDisks; i++) {
        printf("[Disk %d] ", i);
    }
    printf("\n");
}

// Main function to execute the Tower of Hanoi
int main() {
    int numDisks;
    printf("Welcome to the Tower of Hanoi Simulator!\n");
    
    // Get the number of disks from the user
    numDisks = getNumberOfDisks();
    
    // Print the initial state
    printTowersState(numDisks, 'A', 'B', 'C');
    
    // Solve the Tower of Hanoi problem
    printf("\nPerforming the moves...\n");
    towerOfHanoi(numDisks, 'A', 'C', 'B');

    // Print the final state of the towers
    printTowersState(numDisks, 'A', 'B', 'C');
    
    printf("\nCongratulations! All disks have been successfully moved to tower C.\n");
    
    return 0;
}