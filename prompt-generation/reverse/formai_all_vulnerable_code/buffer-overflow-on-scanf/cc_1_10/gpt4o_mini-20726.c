//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

void moveDisk(int fromPeg, int toPeg);
void hanoi(int n, int fromPeg, int toPeg, int auxPeg);
void printHelp();

int main() {
    int numDisks;

    printf("Welcome to the Tower of Hanoi Solver!\n");
    printHelp();

    printf("Enter the number of disks (1 - %d): ", MAX_DISKS);
    scanf("%d", &numDisks);

    while (numDisks < 1 || numDisks > MAX_DISKS) {
        printf("Invalid number of disks! Please enter a number between 1 and %d: ", MAX_DISKS);
        scanf("%d", &numDisks);
    }

    printf("\nSolving Tower of Hanoi for %d disks...\n", numDisks);
    hanoi(numDisks, 1, 2, 3);

    printf("All disks moved from peg 1 to peg 3 successfully!\n");
    return 0;
}

void hanoi(int n, int fromPeg, int toPeg, int auxPeg) {
    if (n == 1) {
        moveDisk(fromPeg, toPeg);
        return;
    }
    
    hanoi(n - 1, fromPeg, auxPeg, toPeg);
    moveDisk(fromPeg, toPeg);
    hanoi(n - 1, auxPeg, toPeg, fromPeg);
}

void moveDisk(int fromPeg, int toPeg) {
    printf("Move disk from peg %d to peg %d\n", fromPeg, toPeg);
}

void printHelp() {
    printf("Instructions:\n");
    printf("1. The game consists of three pegs and a number of disks.\n");
    printf("2. Initially, all disks are stacked on one peg in descending order.\n");
    printf("3. The goal is to move all disks to another peg while following these rules:\n");
    printf("   - Only one disk can be moved at a time.\n");
    printf("   - A disk can only be moved if it is the uppermost disk on a peg.\n");
    printf("   - No disk may be placed on top of a smaller disk.\n");
    printf("4. Enter the number of disks you want to work with.\n");
    printf("5. Enjoy solving the puzzle!\n");
}