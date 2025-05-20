//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include <stdio.h>

void moveDisk(char fromPeg, char toPeg);
void solveTowerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg);
void printStatus(int n, char peg1, char peg2, char peg3);
int moveCount = 0;

int main() {
    int numberOfDisks;

    printf("Welcome to the Tower of Hanoi!\n");
    printf("Enter the number of disks (n) for the puzzle: ");
    scanf("%d", &numberOfDisks);

    if(numberOfDisks <= 0) {
        printf("Number of disks must be a positive integer.\n");
        return 1;
    }

    printf("\nThe sequence of moves involved in the Tower of Hanoi are:\n");
    solveTowerOfHanoi(numberOfDisks, 'A', 'C', 'B'); // A, B and C are names of rods
    printf("\nTotal moves made: %d\n", moveCount);
    
    return 0;
}

// Define the recursive function that solves Tower of Hanoi
void solveTowerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg) {
    // Base case: If there's only one disk, move it directly
    if (n == 1) {
        moveDisk(fromPeg, toPeg);
        return;
    }
    // Recursive step: Move n-1 disks to auxiliary peg
    solveTowerOfHanoi(n - 1, fromPeg, auxPeg, toPeg);
    // Move the nth disk to the target peg
    moveDisk(fromPeg, toPeg);
    // Move the n-1 disks from auxiliary peg to target peg
    solveTowerOfHanoi(n - 1, auxPeg, toPeg, fromPeg);
}

// Function to perform the move and print the status
void moveDisk(char fromPeg, char toPeg) {
    moveCount++;
    printf("Move disk %d from %c to %c\n", moveCount, fromPeg, toPeg);
    printStatus(moveCount, 'A', 'B', 'C');
}

// Function to display the current state of the pegs
void printStatus(int moveNumber, char peg1, char peg2, char peg3) {
    printf("Status after move %d:\n", moveNumber);
    printf("Peg %c: (disks here)\n", peg1);
    printf("Peg %c: (disks here)\n", peg2);
    printf("Peg %c: (disks here)\n", peg3);
    // In a full implementation, we'd track the actual disks on each peg
    // For now, just represent it with placeholders
    printf("--------------------------------------------------------\n");
}