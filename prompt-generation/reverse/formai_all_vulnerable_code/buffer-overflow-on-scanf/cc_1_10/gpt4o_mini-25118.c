//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include <stdio.h>
#include <unistd.h>

void printInstructions() {
    printf("Welcome to the Tower of Hanoi!\n");
    printf("Here's how it works:\n");
    printf("You have three rods and a number of disks of different sizes which can slide onto any rod.\n");
    printf("The puzzle starts with the disks stacked in ascending order of size on one rod, the smallest on top.\n");
    printf("The objective is to move the entire stack to another rod, following these rules:\n");
    printf("1. Only one disk can be moved at a time.\n");
    printf("2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.\n");
    printf("3. No larger disk may be placed on top of a smaller disk.\n\n");
    printf("Let's begin our magical journey through the Tower of Hanoi!\n\n");
    sleep(2);
}

void moveDisk(int fromRod, int toRod) {
    printf("Moving disk from Rod %d to Rod %d.\n", fromRod, toRod);
    fflush(stdout);
    sleep(1); // Simulating time taken to move a disk
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

int main() {
    int numberOfDisks;

    printInstructions();
    
    printf("Enter the number of disks (1-10): ");
    scanf("%d", &numberOfDisks);

    // Input validation
    if (numberOfDisks < 1 || numberOfDisks > 10) {
        printf("Invalid number of disks. Please restart the program and enter a value between 1 and 10.\n");
        return 1;
    }

    printf("\nLet's embark on the quest with %d disks:\n", numberOfDisks);
    sleep(1);
    
    // Start the Tower of Hanoi recursion
    towerOfHanoi(numberOfDisks, 1, 3, 2);
    
    printf("\nCongratulations! All disks have been moved to Rod 3!\n");
    printf("You have successfully completed the Tower of Hanoi challenge!\n");

    return 0;
}