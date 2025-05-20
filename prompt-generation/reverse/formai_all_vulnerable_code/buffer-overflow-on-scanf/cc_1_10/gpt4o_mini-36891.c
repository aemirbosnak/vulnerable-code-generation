//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: modular
#include <stdio.h>

void moveDisk(int disk, char from_rod, char to_rod) {
    printf("Move disk %d from rod %c to rod %c\n", disk, from_rod, to_rod);
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        moveDisk(1, from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    moveDisk(n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

void printInstructions() {
    printf("Welcome to Tower of Hanoi!\n");
    printf("Instructions:\n");
    printf("1. You have three rods.\n");
    printf("2. You start with 'n' disks on the first rod, ordered by size (smallest on top).\n");
    printf("3. The goal is to move all the disks from the first rod to the last rod.\n");
    printf("4. You can only move one disk at a time.\n");
    printf("5. A disk can only be moved if it is the uppermost disk on a rod.\n");
    printf("6. No disk may be placed on top of a smaller disk.\n");
}

int getNumberOfDisks() {
    int n;
    printf("Enter the number of disks (1-10): ");
    scanf("%d", &n);
    while (n < 1 || n > 10) {
        printf("Invalid input. Please enter a number between 1 and 10: ");
        scanf("%d", &n);
    }
    return n;
}

void startGame() {
    int n = getNumberOfDisks();
    towerOfHanoi(n, 'A', 'C', 'B');
}

int main() {
    printInstructions();
    char option;
    
    do {
        startGame();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &option);
    } while (option == 'y' || option == 'Y');

    printf("Thank you for playing Tower of Hanoi!\n");
    return 0;
}