//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void moveDisk(int disk, char from_rod, char to_rod) {
    // Display the move of the disk
    printf("Moving disk %d from rod %c to rod %c\n", disk, from_rod, to_rod);
    fflush(stdout);
    sleep(1); // Pause for 1 second to visualize the move
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base case: When there's only one disk
    if (n == 1) {
        moveDisk(n, from_rod, to_rod);
        return;
    }

    // Move n-1 disks from source to auxiliary, using destination as auxiliary
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    
    // Move the nth disk from source to destination
    moveDisk(n, from_rod, to_rod);
    
    // Move the n-1 disks from auxiliary to destination, using source as auxiliary
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

void printMenu() {
    printf("Welcome to the Tower of Hanoi Solver!\n");
    printf("Please follow the instructions to solve the puzzle.\n");
    printf("1. Enter number of disks\n");
    printf("2. Exit\n");
}

int main() {
    int num_disks;
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the number of disks: ");
            scanf("%d", &num_disks);

            if (num_disks <= 0) {
                printf("Please enter a positive number of disks.\n");
                continue;
            }

            printf("Solving Tower of Hanoi for %d disks...\n", num_disks);
            towerOfHanoi(num_disks, 'A', 'C', 'B'); // A, B and C are the rod labels

            printf("All disks moved from rod A to rod C successfully!\n");
        } else if (choice == 2) {
            printf("Exiting the program. Thank you!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}