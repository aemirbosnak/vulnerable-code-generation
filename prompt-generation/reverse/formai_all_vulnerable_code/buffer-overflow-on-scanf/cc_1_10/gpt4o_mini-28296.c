//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void moveDisk(int disk, char fromRod, char toRod) {
    printf("Move disk %d from rod %c to rod %c\n", disk, fromRod, toRod);
    usleep(500000); // Sleep for 0.5 seconds to simulate the move
}

void hanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        moveDisk(n, fromRod, toRod);
        return;
    }
    hanoi(n - 1, fromRod, auxRod, toRod);
    moveDisk(n, fromRod, toRod);
    hanoi(n - 1, auxRod, toRod, fromRod);
}

void initializeGame(int *numDisks) {
    printf("Welcome to the Tower of Hanoi Game!\n");
    printf("Please enter the number of disks (1-10): ");
    scanf("%d", numDisks);
    
    while(*numDisks < 1 || *numDisks > 10) {
        printf("Invalid input. Please enter a number between 1 and 10: ");
        scanf("%d", numDisks);
    }
}

void displayInstructions() {
    printf("\nInstructions:\n");
    printf("1. You have three rods: A, B, and C.\n");
    printf("2. The goal is to move all disks from rod A to rod C.\n");
    printf("3. You can only move one disk at a time.\n");
    printf("4. A larger disk cannot be placed on top of a smaller disk.\n");
    printf("Enjoy the game!\n");
}

int main() {
    int numDisks;
    initializeGame(&numDisks);
    displayInstructions();

    printf("\nSolving Tower of Hanoi with %d disks:\n", numDisks);
    hanoi(numDisks, 'A', 'C', 'B');

    printf("\nCongratulations! You've successfully moved all disks to rod C!\n");
    return 0;
}