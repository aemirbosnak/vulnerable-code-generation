//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to move a disk from source to destination
void moveDisk(int disk, char source, char destination) {
    printf("Move disk %d from %c to %c\n", disk, source, destination);
    fflush(stdout); // Ensure the output is displayed immediately
    usleep(500000); // Half a second delay to visualize the move
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        moveDisk(n, source, destination);
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);
    
    // Move the nth disk from source to destination
    moveDisk(n, source, destination);
    
    // Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

// Function to prompt user for input
int getNumberOfDisks() {
    int n;
    printf("Enter the number of disks (1-10): ");
    while (1) {
        if (scanf("%d", &n) != 1 || n < 1 || n > 10) {
            printf("Invalid input. Please enter a number between 1 and 10: ");
            while(getchar() != '\n'); // Clear invalid input
        } else {
            break;
        }
    }
    return n;
}

int main() {
    printf("Welcome to the Tower of Hanoi Solver!\n");
    printf("This program will demonstrate how to solve the Tower of Hanoi problem.\n");

    // Get the number of disks from the user
    int numberOfDisks = getNumberOfDisks();

    // Solve the Tower of Hanoi puzzle
    printf("\nSolving the Tower of Hanoi for %d disks:\n", numberOfDisks);
    towerOfHanoi(numberOfDisks, 'A', 'B', 'C'); // A, B, C are the rods

    printf("\nPuzzle solved successfully!\n");

    return 0;
}