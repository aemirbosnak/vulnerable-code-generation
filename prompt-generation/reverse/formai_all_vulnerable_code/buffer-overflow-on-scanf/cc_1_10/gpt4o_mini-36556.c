//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void moveDisk(int disk, char source, char target) {
    printf("Move disk %d from %c to %c\n", disk, source, target);
    fflush(stdout);
    sleep(1); // Pause for a second for better visualization
}

void solveHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        moveDisk(1, source, target);
        return;
    }
    solveHanoi(n - 1, source, auxiliary, target);
    moveDisk(n, source, target);
    solveHanoi(n - 1, auxiliary, target, source);
}

void displayWelcome() {
    printf("=======================================\n");
    printf("  Welcome to the Tower of Hanoi Game  \n");
    printf("=======================================\n");
    printf("A recursive puzzle where you will move\n");
    printf("the disks from one rod to another.\n");
}

void getUserInput(int *numDisks) {
    printf("Enter the number of disks (1-10): ");
    scanf("%d", numDisks);
    while (*numDisks < 1 || *numDisks > 10) {
        printf("Please enter a valid number of disks (1-10): ");
        scanf("%d", numDisks);
    }
}

void displayInstructions() {
    printf("Instructions:\n");
    printf("1. You have three rods: A, B, and C\n");
    printf("2. The objective is to move all disks from A to C\n");
    printf("3. You can only move one disk at a time\n");
    printf("4. A disk can only be placed on top of a larger disk\n");
    printf("Let's begin!\n");
}

int main() {
    int numDisks;

    displayWelcome();
    getUserInput(&numDisks);
    displayInstructions();

    printf("\nSolving Tower of Hanoi for %d disks...\n\n", numDisks);
    sleep(1);
    solveHanoi(numDisks, 'A', 'C', 'B');

    printf("=======================================\n");
    printf("            Puzzle Completed!          \n");
    printf("=======================================\n");

    return 0;
}