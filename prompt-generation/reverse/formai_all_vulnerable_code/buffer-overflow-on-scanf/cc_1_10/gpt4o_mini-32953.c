//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: high level of detail
#include <stdio.h>

// Function to move disks between towers
void moveTower(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary tower
    moveTower(n - 1, source, auxiliary, destination);
    // Move the nth disk from source to destination tower
    printf("Move disk %d from %c to %c\n", n, source, destination);
    // Move n-1 disks from auxiliary to destination tower
    moveTower(n - 1, auxiliary, destination, source);
}

// Function to display current instruction and tower status
void displayInstructions() {
    printf("\nWelcome to the Tower of Hanoi Solver!\n");
    printf("Instructions:\n");
    printf("1. You have three towers: A, B, and C.\n");
    printf("2. The objective is to move all disks from Tower A to Tower C.\n");
    printf("3. Only one disk can be moved at a time.\n");
    printf("4. A larger disk cannot be placed on top of a smaller disk.\n");
    printf("5. The program will show you the moves to solve the puzzle.\n");
    printf("6. You may choose the number of disks (greater than 0).\n\n");
}

// Main function
int main() {
    int numDisks;

    // Display instructions to the user
    displayInstructions();

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Validate input
    if(numDisks <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    // Solve the Tower of Hanoi problem
    printf("\nThe sequence of moves involved in solving the Tower of Hanoi are:\n");
    moveTower(numDisks, 'A', 'C', 'B');

    printf("\nCompleted the Tower of Hanoi solution with %d disks.\n", numDisks);
    return 0;
}