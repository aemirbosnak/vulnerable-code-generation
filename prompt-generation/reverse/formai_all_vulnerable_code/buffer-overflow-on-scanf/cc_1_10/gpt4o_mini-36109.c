//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void moveDisk(int disk, char fromRod, char toRod) {
    printf("Move disk %d from rod %c to rod %c\n", disk, fromRod, toRod);
}

void towerOfHanoiRecursive(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        moveDisk(1, fromRod, toRod);
        return;
    }

    // Move n-1 disks from fromRod to auxRod
    towerOfHanoiRecursive(n - 1, fromRod, auxRod, toRod);
    
    // Move the nth disk from fromRod to toRod
    moveDisk(n, fromRod, toRod);
    
    // Move the n-1 disks from auxRod to toRod
    towerOfHanoiRecursive(n - 1, auxRod, toRod, fromRod);
}

void createTowerOfHanoi(int n) {
    if (n <= 0) {
        printf("There are no disks to move!\n");
        return;
    }
    printf("Tower of Hanoi with %d disks\n", n);
    towerOfHanoiRecursive(n, 'A', 'C', 'B');
}

int main() {
    int numDisks;

    printf("Welcome to the Tower of Hanoi game!\n");
    printf("Enter the number of disks (1-10) to begin your quest: ");
    scanf("%d", &numDisks);

    if(numDisks < 1 || numDisks > 10) {
        printf("Please enter a valid number of disks between 1 and 10.\n");
        return EXIT_FAILURE;
    }

    createTowerOfHanoi(numDisks);
    printf("All disks have been successfully moved to rod C!\n");
    printf("Congratulations on solving the Tower of Hanoi!\n");

    return EXIT_SUCCESS;
}