//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: synchronous
#include <stdio.h>
#include <unistd.h> // For sleep function

void moveDisk(char src, char dest) {
    printf("Move disk from %c to %c\n", src, dest);
    sleep(1); // Simulate the time taken to move a disk
}

void towerOfHanoi(int n, char src, char dest, char aux) {
    if (n == 1) {
        moveDisk(src, dest);
        return;
    }
    towerOfHanoi(n - 1, src, aux, dest);
    moveDisk(src, dest);
    towerOfHanoi(n - 1, aux, dest, src);
}

void printWelcomeMessage() {
    printf("Welcome to the Tower of Hanoi!\n");
    printf("This program will solve the Tower of Hanoi problem.\n\n");
}

void printInstructions() {
    printf("Instructions:\n");
    printf("1. There are three rods: A (source), B (auxiliary), and C (destination).\n");
    printf("2. The goal is to move all disks from rod A to rod C using rod B.\n");
    printf("3. Only one disk can be moved at a time, and a disk can only be moved if it is on top of the stack.\n");
    printf("4. No larger disk may be placed on top of a smaller disk.\n\n");
}

int main() {
    int n;

    printWelcomeMessage();
    printInstructions();

    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("The number of disks must be at least 1.\n");
        return 1; // Exit with error code
    }

    printf("\nSolving Tower of Hanoi for %d disks:\n\n", n);
    
    towerOfHanoi(n, 'A', 'C', 'B');

    printf("\nAll disks have been moved from A to C successfully!\n");
    return 0; // Successful execution
}