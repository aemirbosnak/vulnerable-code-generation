//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: unmistakable
#include <stdio.h>

void moveDisk(int num, char source, char destination) {
    printf("Move disk %d from %c to %c\n", num, source, destination);
}

void solveTowerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        moveDisk(1, source, destination);
        return;
    }
    solveTowerOfHanoi(n - 1, source, destination, auxiliary);
    moveDisk(n, source, destination);
    solveTowerOfHanoi(n - 1, auxiliary, source, destination);
}

void printInstructions() {
    printf("--------------------------------------------------\n");
    printf("Welcome to the Tower of Hanoi Problem Solver!\n");
    printf("--------------------------------------------------\n");
    printf("Instructions:\n");
    printf("1. You have three rods and a number of disks of different sizes that can slide onto any rod.\n");
    printf("2. The puzzle starts with the disks stacked in ascending order of size on one rod, the smallest on top.\n");
    printf("3. The objective is to move the entire stack to another rod, obeying the following rules:\n");
    printf("   - Only one disk can be moved at a time.\n");
    printf("   - Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.\n");
    printf("   - No larger disk may be placed on top of a smaller disk.\n");
    printf("--------------------------------------------------\n");
}

int main() {
    int numDisks;

    printInstructions();
    
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    if (numDisks <= 0) {
        printf("Please enter a valid number of disks greater than zero.\n");
        return 1;
    }

    printf("\nThe sequence of moves involved in solving the Tower of Hanoi with %d disks:\n", numDisks);
    solveTowerOfHanoi(numDisks, 'A', 'B', 'C');

    printf("--------------------------------------------------\n");
    printf("Congratulations! You have completed the Tower of Hanoi.\n");
    return 0;
}