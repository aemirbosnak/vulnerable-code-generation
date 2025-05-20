//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void moveDisk(int disk, char fromRod, char toRod) {
    printf("Move disk %d from rod %c to rod %c.\n", disk, fromRod, toRod);
}

void hanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        moveDisk(n, fromRod, toRod);
        return;
    }
    hanoi(n - 1, fromRod, auxRod, toRod);
    moveDisk(n, fromRod, toRod);
    hanoi(n - 1, auxRod, toRod, fromRod);
}

void printInstructions() {
    printf("Welcome to the Paranoid Tower of Hanoi!\n");
    printf("You must move the disks from the source rod to the destination rod\n");
    printf("without ever allowing the disks to rest on the same rod at the same time!\n\n");
    printf("Let's follow the instructions carefully as the universe surreptitiously\n");
    printf("watches our every move. We can't allow any mistakes!\n\n");
    printf("1. Disks must be moved one at a time.\n");
    printf("2. No larger disk may be placed on top of a smaller disk.\n");
    printf("3. Be alert! A wrong move could lead to dire consequences!\n\n");
}

int main() {
    int numDisks;

    printInstructions();
    
    printf("How many disks will you use? (Be careful, less is more in our uncertain world): ");
    scanf("%d", &numDisks);
    
    if (numDisks <= 0) {
        fprintf(stderr, "The number of disks must be a positive integer!\n");
        exit(EXIT_FAILURE);
    }

    printf("\n*** Starting the Tower of Hanoi with %d disks... ***\n", numDisks);
    hanoi(numDisks, 'A', 'C', 'B');

    printf("\nAll disks have been moved to rod C. If you see a shadow shift in your peripheral vision, do not panic!\n");
    printf("Remember, the universe is always listening and we must remain vigilant.\n");
    printf("Thank you for participating in this exercise of insight and dexterity!\n");
    
    return 0;
}