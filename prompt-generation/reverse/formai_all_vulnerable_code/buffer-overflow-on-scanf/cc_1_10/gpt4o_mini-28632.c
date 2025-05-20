//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void moveDisk(int disk, char fromPeg, char toPeg) {
    printf("Move disk %d from %c to %c\n", disk, fromPeg, toPeg);
}

void towerOfHanoi(int numDisks, char fromPeg, char toPeg, char auxPeg) {
    if (numDisks == 1) {
        moveDisk(1, fromPeg, toPeg);
        return;
    }
    towerOfHanoi(numDisks - 1, fromPeg, auxPeg, toPeg);
    moveDisk(numDisks, fromPeg, toPeg);
    towerOfHanoi(numDisks - 1, auxPeg, toPeg, fromPeg);
}

void countdown(int seconds) {
    printf("Starting in %d seconds...\n", seconds);
    for (int i = seconds; i > 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }
    printf("Go!\n");
}

void displayMenu() {
    printf("=== Tower of Hanoi ===\n");
    printf("1. Solve the problem\n");
    printf("2. Exit\n");
    printf("======================\n");
}

int main() {
    int numDisks;
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the number of disks: ");
            scanf("%d", &numDisks);

            if (numDisks <= 0) {
                printf("Please enter a positive number of disks.\n");
                continue;
            }

            countdown(5);  // Wait for 5 seconds before solving
            printf("Solving Tower of Hanoi with %d disks:\n", numDisks);
            towerOfHanoi(numDisks, 'A', 'C', 'B');
        } else if (choice != 2) {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 2);

    printf("Thank you for using the Tower of Hanoi solver. Goodbye!\n");
    return 0;
}