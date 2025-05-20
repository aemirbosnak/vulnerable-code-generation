//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: grateful
#include <stdio.h>

// Function to display a welcoming message
void displayWelcomeMessage() {
    printf("****************************************\n");
    printf("           Welcome to Tower of Hanoi!  \n");
    printf("****************************************\n");
    printf("This program will guide you through solving the Tower of Hanoi problem.\n");
    printf("Thank you for choosing to explore this fascinating algorithm!\n\n");
}

// Function to move disks between the towers
void moveDisk(int disk, char fromTower, char toTower) {
    printf("Moving disk %d from tower %c to tower %c\n", disk, fromTower, toTower);
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char fromTower, char toTower, char auxTower) {
    // Base case: When only one disk is left
    if (n == 1) {
        moveDisk(n, fromTower, toTower);
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n-1, fromTower, auxTower, toTower);
    
    // Move the nth disk from source to destination
    moveDisk(n, fromTower, toTower);
    
    // Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n-1, auxTower, toTower, fromTower);
}

// Main function to drive the program
int main() {
    int numberOfDisks;
    
    displayWelcomeMessage();
    
    // Prompt user for number of disks
    printf("Please enter the number of disks (1 to 10): ");
    scanf("%d", &numberOfDisks);
    
    // Validation of user input
    if (numberOfDisks < 1 || numberOfDisks > 10) {
        printf("Invalid number of disks! Please run the program again with a value between 1 and 10.\n");
        return 1; // Exit if the input is invalid
    }
    
    printf("\nStarting the Tower of Hanoi solution with %d disks:\n\n", numberOfDisks);
    
    // Call the Tower of Hanoi function
    towerOfHanoi(numberOfDisks, 'A', 'C', 'B');
    
    printf("\n****************************************\n");
    printf("           End of the Game!             \n");
    printf("****************************************\n");
    printf("Thank you for playing Tower of Hanoi!\n");
    
    return 0; // Successful termination of the program
}