//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void moveDisk(int fromPeg, int toPeg) {
    printf("\033[1;92mMove disk from Peg %d to Peg %d\033[0m\n", fromPeg, toPeg);
    usleep(500000);  // Sleep for 500 milliseconds
}

void towerOfHanoi(int numDisks, int fromPeg, int toPeg, int auxPeg) {
    if (numDisks == 1) {
        moveDisk(fromPeg, toPeg);
        return;
    }
    towerOfHanoi(numDisks - 1, fromPeg, auxPeg, toPeg);
    moveDisk(fromPeg, toPeg);
    towerOfHanoi(numDisks - 1, auxPeg, toPeg, fromPeg);
}

void printIntroduction() {
    printf("=======================================\n");
    printf("\033[1;34mWelcome to the Tower of Hanoi!\033[0m\n");
    printf("=======================================\n");
    printf("This game involves moving a stack of disks from one peg to another.\n");
    printf("Rules:\n");
    printf("1. Only one disk can be moved at a time.\n");
    printf("2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or an empty peg.\n");
    printf("3. No larger disk may be placed on top of a smaller disk.\n");
    printf("=======================================\n");
}

int main() {
    int numDisks;
    
    printIntroduction();
    
    printf("Enter the number of disks (1-7): ");
    scanf("%d", &numDisks);
    
    if (numDisks < 1 || numDisks > 7) {
        printf("\033[1;31mPlease enter a valid number of disks between 1 and 7!\033[0m\n");
        return 1;
    }
    
    printf("\033[1;33mSolving Tower of Hanoi with %d disks...\033[0m\n", numDisks);
    sleep(1);  // Give a second before starting

    towerOfHanoi(numDisks, 1, 3, 2); // Peg 1 to Peg 3 using Peg 2 as auxiliary

    printf("\033[1;32mCongratulations! You've completed the Tower of Hanoi!\033[0m\n");
    printf("=======================================\n");
    return 0;
}