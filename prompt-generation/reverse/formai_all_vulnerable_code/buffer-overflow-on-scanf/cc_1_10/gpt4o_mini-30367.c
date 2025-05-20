//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: synchronous
#include <stdio.h>

// Function to perform the Tower of Hanoi algorithm
void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    towerOfHanoi(n - 1, auxiliary, target, source);
}

// Function to prompt the user for input
int getNumberOfDisks() {
    int n;
    printf("Enter the number of disks (1 to 10): ");
    while (1) {
        scanf("%d", &n);
        if (n >= 1 && n <= 10) {
            break;
        } else {
            printf("Invalid input. Please enter a number between 1 and 10: ");
        }
    }
    return n;
}

// Function to display the welcome message
void displayWelcomeMessage() {
    printf("Welcome to the Tower of Hanoi Solver!\n");
    printf("This program will solve the Tower of Hanoi puzzle for you.\n");
    printf("Follow the instructions to move the disks from the source peg to the target peg.\n");
    printf("Let's get started!\n");
}

// Main function
int main() {
    int numberOfDisks;
    
    // Display the welcome message
    displayWelcomeMessage();
    
    // Get the number of disks from the user
    numberOfDisks = getNumberOfDisks();
    
    // Display the instructions for moving
    printf("\nInstructions:\n");
    printf("1. Use the labels A, B, C for the pegs.\n");
    printf("2. Move the disks as per the following steps:\n");
    
    // Solve the Tower of Hanoi problem
    towerOfHanoi(numberOfDisks, 'A', 'C', 'B');
    
    printf("\nCongratulations! You have completed the Tower of Hanoi with %d disks.\n", numberOfDisks);
    return 0;
}