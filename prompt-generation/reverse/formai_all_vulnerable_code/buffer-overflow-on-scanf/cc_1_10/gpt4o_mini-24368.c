//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISCS 10

void moveDisk(int disk, char fromPeg, char toPeg) {
    printf("Move disk %d from peg %c to peg %c\n", disk, fromPeg, toPeg);
}

void solveTowerOfHanoi(int numDisks, char fromPeg, char toPeg, char auxPeg) {
    if (numDisks == 1) {
        moveDisk(1, fromPeg, toPeg);
        return;
    }
    solveTowerOfHanoi(numDisks - 1, fromPeg, auxPeg, toPeg);
    moveDisk(numDisks, fromPeg, toPeg);
    solveTowerOfHanoi(numDisks - 1, auxPeg, toPeg, fromPeg);
}

int main() {
    int numDisks = 0;
    char confirmation;

    printf("Welcome to the Tower of Hanoi!\n");
    printf("This program will solve the Tower of Hanoi problem recursively.\n");
    
    // Input validation for number of disks
    while (1) {
        printf("Enter the number of disks (1 - %d): ", MAX_DISCS);
        scanf("%d", &numDisks);
        if (numDisks >= 1 && numDisks <= MAX_DISCS) {
            break;
        } else {
            printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_DISCS);
        }
    }

    printf("You have chosen %d disks.\n", numDisks);
    printf("To start the process, we will use three pegs labeled A, B, and C.\n");
    printf("Let's solve the Tower of Hanoi problem with %d disks.\n", numDisks);

    printf("Do you want to continue with the solution? (y/n): ");
    scanf(" %c", &confirmation); // Space before %c to consume any leftover newline

    if (confirmation == 'y' || confirmation == 'Y') {
        solveTowerOfHanoi(numDisks, 'A', 'C', 'B');
    } else {
        printf("Exiting the program. Thank you!\n");
        return 0;
    }

    printf("All disks have been moved from peg A to peg C successfully!\n");
    return 0;
}