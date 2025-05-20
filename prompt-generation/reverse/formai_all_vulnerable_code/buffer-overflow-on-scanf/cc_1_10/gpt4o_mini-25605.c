//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Function to display the instructions for the Tower of Hanoi game
void displayInstructions() {
    printf("Welcome to the Tower of Hanoi Game!\n");
    printf("Your objective is to move all disks from the source tower to the destination tower.\n");
    printf("The rules are simple:\n");
    printf("1. Only one disk can be moved at a time.\n");
    printf("2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty stack.\n");
    printf("3. No disk may be placed on top of a smaller disk.\n");
    printf("Have fun solving this puzzle!\n\n");
}

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Function to get the number of disks from the user
int getNumberOfDisks() {
    int n;
    printf("Enter the number of disks: ");
    while (1) {
        scanf("%d", &n);
        if (n > 0) {
            break;
        } else {
            printf("Please enter a positive integer.\n");
        }
    }
    return n;
}

// Main function of the Tower of Hanoi program
int main() {
    int numDisks;

    displayInstructions(); // Display instructions to the user
    numDisks = getNumberOfDisks(); // Get the number of disks from the user

    // Display the initial state
    printf("\nThe Tower of Hanoi has been set up with %d disks.\n", numDisks);
    printf("Let's begin moving the disks!\n\n");

    // Start solving the Tower of Hanoi problem
    towerOfHanoi(numDisks, 'A', 'C', 'B');

    printf("\nCongratulations! You've successfully moved all the disks from Tower A to Tower C.\n");
    return 0;
}