//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>

// Function to perform the Tower of Hanoi moves
void towerOfHanoi(int n, char source, char target, char auxiliary) {
    // Base case: When there is only one disk, move it from the source to the target
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    // Move n-1 disks from source to auxiliary, using target as a temporary peg
    towerOfHanoi(n - 1, source, auxiliary, target);
    // Move the nth disk from source to target
    printf("Move disk %d from %c to %c\n", n, source, target);
    // Move the n-1 disks from auxiliary to target, using source as a temporary peg
    towerOfHanoi(n - 1, auxiliary, target, source);
}

// Function to count the total number of moves
int countMoves(int n) {
    // The formula 2^n - 1 gives the number of moves required for n disks
    return (1 << n) - 1; // Using bitwise left shift to calculate powers of 2
}

int main() {
    int numDisks;

    // Ask the user for the number of disks
    printf("Welcome to the Tower of Hanoi Solver!\n");
    printf("Please enter the number of disks (positive integer): ");
    
    // Input validation loop
    while (1) {
        scanf("%d", &numDisks);
        if (numDisks > 0) {
            break;
        } else {
            printf("Invalid input. Please enter a positive integer: ");
        }
    }

    // Display the total number of moves
    int totalMoves = countMoves(numDisks);
    printf("Total moves required for %d disks: %d\n", numDisks, totalMoves);
    printf("The moves are as follows:\n");

    // Call the function to perform Tower of Hanoi
    towerOfHanoi(numDisks, 'A', 'C', 'B');

    return 0;
}