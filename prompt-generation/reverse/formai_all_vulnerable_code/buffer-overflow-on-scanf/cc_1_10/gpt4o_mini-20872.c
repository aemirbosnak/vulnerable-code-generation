//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: curious
#include <stdio.h>

// Function to perform the recursive steps of the Tower of Hanoi
void solveTowerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, target);
        return;
    }
    
    // Move n-1 disks from source to auxiliary, using target as a temporary peg
    solveTowerOfHanoi(n - 1, source, auxiliary, target);
    
    // Move the nth disk from source to target
    printf("Move disk %d from rod %c to rod %c\n", n, source, target);
    
    // Move the n-1 disks from auxiliary to target, using source as a temporary peg
    solveTowerOfHanoi(n - 1, auxiliary, target, source);
}

// Function to display a whimsical introduction to the Tower of Hanoi
void magicalIntroduction() {
    printf("Welcome to the enchanting world of the Tower of Hanoi!\n");
    printf("Behold the mesmerizing challenge of moving a stack of disks,\n");
    printf("but beware, for certain rules must be followed! 🎩✨\n\n");
    printf("The Rules:\n");
    printf("1. Only one disk can be moved at a time.\n");
    printf("2. A disk can only be placed on an empty rod or on top of a larger disk.\n");
    printf("3. Your goal is to move the entire stack from one rod to another.\n");
    printf("Good luck, brave mover!\n\n");
}

// Function to capture user input for number of disks
int getNumberOfDisks() {
    int n;
    printf("Enter the number of disks you wish to challenge: ");
    scanf("%d", &n);
    return n;
}

// Function for the whimsical farewell
void magicalFarewell() {
    printf("\nYou have successfully completed the Tower of Hanoi challenge!\n");
    printf("Your courage and intellect have shone brightly!\n");
    printf("Until we meet again, may your paths be filled with magic! 🌟👋\n");
}

int main() {
    magicalIntroduction(); // Start with a whimsical introduction

    int numberOfDisks = getNumberOfDisks(); // Get the number of disks from the user

    // Display the solution to the Tower of Hanoi puzzle
    printf("\nHere are the magical moves to solve the puzzle:\n");
    solveTowerOfHanoi(numberOfDisks, 'A', 'C', 'B'); // Rods are A (source), C (target), and B (auxiliary)

    magicalFarewell(); // End with a fanciful farewell

    return 0; // Return successful after execution
}