//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep() function

void moveDisk(int disk, char fromPeg, char toPeg) {
    printf("Moving disk %d from peg %c to peg %c\n", disk, fromPeg, toPeg);
    // Simulate the moving effect
    for (int i = 0; i < disk; i++) {
        printf(" ");
    }
    printf("O\n");
    sleep(1); // Pause for a moment to simulate moving
}

void solveTowerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg) {
    if (n == 1) {
        moveDisk(1, fromPeg, toPeg);
        return;
    }
    solveTowerOfHanoi(n - 1, fromPeg, auxPeg, toPeg);
    moveDisk(n, fromPeg, toPeg);
    solveTowerOfHanoi(n - 1, auxPeg, toPeg, fromPeg);
}

void printInstructions() {
    printf("Welcome to the Tower of Hanoi Problem Solver!\n");
    printf("You will be prompted to enter the number of disks.\n");
    printf("The program will solve the Tower of Hanoi problem step by step.\n");
    printf("Press Enter to continue...\n");
    getchar();
}

int main() {
    int n;
    printInstructions();

    printf("Please enter the number of disks (1-9): ");
    scanf("%d", &n);

    // Input validation
    while (n < 1 || n > 9) {
        printf("Invalid input. Please enter a number between 1 and 9: ");
        scanf("%d", &n);
    }

    printf("Solving Tower of Hanoi for %d disks:\n", n);
    sleep(1); // Short pause before starting
    solveTowerOfHanoi(n, 'A', 'C', 'B'); // Move from A to C using B as auxiliary

    printf("All disks moved successfully!\n");
    return 0;
}