//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void moveDisk(int fromRod, int toRod) {
    printf("Move disk from rod %d to rod %d\n", fromRod, toRod);
    sleep(1);  // Sleep for 1 second to visualize the movement
}

void towerOfHanoi(int n, int fromRod, int toRod, int auxRod) {
    if (n == 1) {
        moveDisk(fromRod, toRod);
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    moveDisk(fromRod, toRod);
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

void printInstructions() {
    printf("Welcome to the Tower of Hanoi Solver!\n");
    printf("This program will visualize the movement of disks.\n");
    printf("You can customize the number of disks.\n");
    printf("Follow the instructions to solve the Tower of Hanoi!\n");
}

int getNumberOfDisks() {
    int n;
    printf("Enter the number of disks (1-9): ");
    scanf("%d", &n);
    
    // Validate input
    while(n < 1 || n > 9) {
        printf("Please enter a valid number of disks (1-9): ");
        scanf("%d", &n);
    }

    return n;
}

void visualizeProcess(int n) {
    printf("\nStarting Tower of Hanoi with %d disks...\n", n);
    towerOfHanoi(n, 1, 3, 2);  // 1: fromRod, 2: auxRod, 3: toRod
    printf("All disks have been moved from rod 1 to rod 3.\n");
}

int main() {
    printInstructions();
    int n = getNumberOfDisks();

    visualizeProcess(n);

    return 0;
}