//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    hanoi(n - 1, auxiliary, target, source);
}

void displayInstructions() {
    printf("Welcome to the Tower of Hanoi Solver!\n");
    printf("Follow the instructions below to solve the problem:\n");
    printf("1. Choose the number of disks.\n");
    printf("2. Watch the moves printed on the console as disks are moved.\n");
    printf("3. Enjoy the process!\n");
}

int getNumberOfDisks() {
    int n;
    printf("Enter the number of disks (1-10): ");
    scanf("%d", &n);
    while (n < 1 || n > 10) {
        printf("Invalid input. Please enter a number between 1 and 10: ");
        scanf("%d", &n);
    }
    return n;
}

int main() {
    int disks;
    char choice;

    do {
        displayInstructions();
        disks = getNumberOfDisks();
        printf("You have chosen %d disks.\n", disks);
        
        printf("The moves to solve the Tower of Hanoi are:\n");
        hanoi(disks, 'A', 'C', 'B');

        printf("\nWould you like to solve another Tower of Hanoi problem? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Tower of Hanoi Solver. Goodbye!\n");

    return 0;
}