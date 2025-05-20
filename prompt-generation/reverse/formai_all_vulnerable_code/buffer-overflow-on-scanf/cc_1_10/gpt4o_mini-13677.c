//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>

// Function prototype
void moveDisks(int, char, char, char);

// Global counter for the number of moves
int moveCount = 0;

int main() {
    int numOfDisks;

    // Prompting user for number of disks
    printf("Welcome to the Tower of Hanoi!\n");
    printf("Enter the number of disks (positive integer): ");
    scanf("%d", &numOfDisks);

    // Validate input
    if (numOfDisks <= 0) {
        printf("Error: Number of disks must be greater than zero.\n");
        return 1;
    }

    // Start solving the Tower of Hanoi Problem
    printf("\n--- Solving Tower of Hanoi for %d disks ---\n", numOfDisks);
    moveDisks(numOfDisks, 'A', 'C', 'B');  // A, C are the rods; B is the auxiliary.
    
    // Displaying total moves made
    printf("\nTotal moves made: %d\n", moveCount);
    
    return 0;  // End of the program
}

// Recursive function to solve Tower of Hanoi
void moveDisks(int n, char source, char destination, char auxiliary) {
    // Base case: If there is only one disk, move it directly
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        moveCount++;
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    moveDisks(n - 1, source, auxiliary, destination);
    
    // Move the nth disk from source to destination
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    moveCount++;
    
    // Move the n-1 disks from auxiliary to destination
    moveDisks(n - 1, auxiliary, destination, source);
}