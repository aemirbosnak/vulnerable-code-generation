//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: enthusiastic
#include <stdio.h>

// Function to print the moves
void moveDisk(int disk, char fromPeg, char toPeg) {
    printf("Move disk %d from peg '%c' to peg '%c'\n", disk, fromPeg, toPeg);
}

// Recursive function to solve the Tower of Hanoi problem
void solveTowerOfHanoi(int numDisks, char fromPeg, char toPeg, char auxPeg) {
    // Base case: If there's only one disk, simply move it
    if (numDisks == 1) {
        moveDisk(numDisks, fromPeg, toPeg);
        return;
    }
    
    // Move the top (numDisks - 1) disks from A to C, using B as auxiliary
    solveTowerOfHanoi(numDisks - 1, fromPeg, auxPeg, toPeg);
    
    // Move the last disk from A to B
    moveDisk(numDisks, fromPeg, toPeg);
    
    // Move the (numDisks - 1) disks from C to B, using A as auxiliary
    solveTowerOfHanoi(numDisks - 1, auxPeg, toPeg, fromPeg);
}

// Main function to execute the Tower of Hanoi solution
int main() {
    int numDisks;
    
    // Welcome the user and ask for the number of disks
    printf("🎉 Welcome to the Tower of Hanoi puzzle solver! 🎉\n");
    printf("How many disks do you want to use? (1-64): ");
    scanf("%d", &numDisks);
    
    // Input validation
    if (numDisks < 1 || numDisks > 64) {
        printf("😱 Oops! Please enter a valid number of disks between 1 and 64. Try again!\n");
        return 1;
    }
    
    // Initiate the puzzle solving
    printf("🚀 Let's solve the Tower of Hanoi puzzle with %d disks! 🚀\n", numDisks);
    // Naming the pegs for better understanding
    char pegA = 'A', pegB = 'B', pegC = 'C';
    
    // Calling the function to solve the puzzle
    solveTowerOfHanoi(numDisks, pegA, pegC, pegB);
    
    // Gratitude message upon completion
    printf("🎊 Congratulations! You've successfully solved the Tower of Hanoi puzzle! 🎊\n");
    return 0;
}