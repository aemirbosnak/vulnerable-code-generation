//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complete
#include <stdio.h>

// Function to move disks from source to destination using auxiliary
void moveDisks(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    moveDisks(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    moveDisks(n - 1, auxiliary, destination, source);
}

// Function to input the number of disks
int getNumberOfDisks() {
    int disks;
    printf("Enter the number of disks: ");
    while (1) {
        int result = scanf("%d", &disks);
        if (result == 1 && disks >= 1) {
            break;
        } else {
            printf("Invalid input. Please enter a positive integer: ");
            while(getchar() != '\n'); // Clear the buffer
        }
    }
    return disks;
}

// Menu to choose running the Tower of Hanoi problem or exit
void menu() {
    int choice;
    do {
        printf("\nTower of Hanoi Problem\n");
        printf("1. Solve the Tower of Hanoi\n");
        printf("2. Exit\n");
        printf("Choose an option (1 or 2): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int disks = getNumberOfDisks();
                printf("Solving Tower of Hanoi with %d disks:\n", disks);
                moveDisks(disks, 'A', 'C', 'B'); // A, B, C are the names of rods
                break;
            }
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 2);
}

// Main function to execute the menu
int main() {
    menu();
    return 0;
}