//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to move disks from source to destination
void moveDisk(int disk, char source, char destination) {
    printf("Move disk %d from %c to %c\n", disk, source, destination);
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        moveDisk(1, source, destination);
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);
    
    // Move nth disk from source to destination
    moveDisk(n, source, destination);
    
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

// Function to display the menu
void displayMenu() {
    printf("************************************\n");
    printf("***** Tower of Hanoi Simulation *****\n");
    printf("************************************\n");
    printf("Enter the number of disks (1-10): ");
}

// Main function
int main() {
    int numDisks;
    
    displayMenu();
    scanf("%d", &numDisks);

    // Input validation
    if (numDisks < 1 || numDisks > 10) {
        printf("Error: Number of disks must be between 1 and 10.\n");
        return EXIT_FAILURE;
    }

    // Solve the Tower of Hanoi problem
    printf("Calculating the moves for %d disks...\n", numDisks);
    towerOfHanoi(numDisks, 'A', 'B', 'C');

    printf("All moves completed successfully!\n");
    return EXIT_SUCCESS;
}