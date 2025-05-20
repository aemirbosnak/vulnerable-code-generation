//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to print the instructions
void printInstructions() {
    printf("Welcome to the Tower of Hanoi!\n");
    printf("This is a puzzle involving three rods and a number of disks of different sizes.\n");
    printf("Your goal is to move all the disks from the source rod to the destination rod.\n");
    printf("You can only move one disk at a time, and you cannot place a larger disk on top of a smaller disk.\n\n");
}

// Function to perform the Tower of Hanoi algorithm
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Function to pause the execution for a while
void pauseExecution() {
    printf("Press Enter to continue...\n");
    getchar();
    printf("\n");
}

// Main function
int main() {
    int numDisks;

    printInstructions();

    // Prompt the user for the number of disks
    printf("Enter the number of disks (1-9): ");
    
    while (1) {
        scanf("%d", &numDisks);
        if (numDisks < 1 || numDisks > 9) {
            printf("Please enter a valid number of disks (1-9): ");
        } else {
            break;
        }
    }

    // Start the Tower of Hanoi process
    printf("\nMoving %d disks from rod A to rod C using rod B as auxiliary:\n\n", numDisks);
    
    // Call the function to solve the Tower of Hanoi
    towerOfHanoi(numDisks, 'A', 'C', 'B');
    
    // Indicate completed moves
    printf("\nAll disks have been successfully moved to rod C!\n");

    return 0;
}