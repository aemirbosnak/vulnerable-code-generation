//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void moveDisk(int disk, char fromRod, char toRod) {
    printf("Move disk %d from rod %c to rod %c\n", disk, fromRod, toRod);
}

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        moveDisk(1, fromRod, toRod);
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    moveDisk(n, fromRod, toRod);
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int numDisks;
    char inputChar;

    printf("Welcome to the Tower of Hanoi Solver!\n");
    printf("Enter the number of disks (1-10): ");
    
    while (1) {
        scanf("%d", &numDisks);
        if (numDisks >= 1 && numDisks <= 10) {
            break;
        } else {
            printf("Please enter a valid number of disks (1-10): ");
        }
    }

    printf("You chose to solve the Tower of Hanoi with %d disks.\n", numDisks);
    printf("The solution will be displayed below:\n");

    towerOfHanoi(numDisks, 'A', 'C', 'B');

    printf("Do you want to see the steps again? (y/n): ");
    while (1) {
        scanf(" %c", &inputChar);
        if (inputChar == 'y' || inputChar == 'Y') {
            printf("The solution is as follows:\n");
            towerOfHanoi(numDisks, 'A', 'C', 'B');
            break;
        } else if (inputChar == 'n' || inputChar == 'N') {
            printf("Thank you for using the Tower of Hanoi Solver! Goodbye!\n");
            break;
        } else {
            printf("Invalid input. Please enter 'y' or 'n': ");
        }
    }

    return 0;
}