//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to move disks from source to destination using helper
void moveDisks(int num, char source, char dest, char helper) {
    if (num == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    moveDisks(num - 1, source, helper, dest);
    printf("Move disk %d from %c to %c\n", num, source, dest);
    moveDisks(num - 1, helper, dest, source);
}

// Function to display the menu to the user
void displayMenu() {
    printf("\nTower of Hanoi Problem\n");
    printf("1. Solve Tower of Hanoi\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    int option, numOfDisks;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the number of disks: ");
                scanf("%d", &numOfDisks);
                
                if (numOfDisks < 1) {
                    printf("Number of disks must be at least 1.\n");
                    break;
                }

                printf("Steps to move %d disks from A to C:\n", numOfDisks);
                moveDisks(numOfDisks, 'A', 'C', 'B');
                break;

            case 2:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    }

    return 0;
}