//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to print an elegant introduction.
void peacefulIntroduction() {
    printf("Welcome to the Tower of Hanoi Challenge!\n");
    printf("A serene journey where we will gracefully move the disks.\n\n");
    printf("Observe carefully and enjoy the tranquility of the moves.\n\n");
}

// Function to perform the Tower of Hanoi algorithm.
void hanoi(int n, char source, char target, char auxiliary) {
    // Base case: If there is only one disk, simply move it.
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }

    // Move n-1 disks from source to auxiliary, using target as a helper.
    hanoi(n - 1, source, auxiliary, target);

    // Move the nth disk from source to target.
    printf("Move disk %d from %c to %c\n", n, source, target);

    // Move the n-1 disks from auxiliary to target, using source as a helper.
    hanoi(n - 1, auxiliary, target, source);
}

// Function to display the serene completion message.
void peacefulCompletion() {
    printf("\nAll disks have been moved peacefully!\n");
    printf("Thank you for participating in this calming exercise.\n");
}

// The main function serves as the entry point of the program.
int main() {
    int num_of_disks;

    peacefulIntroduction();

    // Asking the user for the number of disks, ensuring a valid input.
    printf("Enter the number of disks (1-9): ");
    scanf("%d", &num_of_disks);

    if (num_of_disks < 1 || num_of_disks > 9) {
        printf("Please enter a number between 1 and 9 for a peaceful experience.\n");
        return EXIT_FAILURE; // End the program gracefully.
    }

    // Display the initial state before starting the moves.
    printf("\nLet's begin our gentle moves...\n");
    hanoi(num_of_disks, 'A', 'C', 'B');  // A, B and C are names of the towers.

    peacefulCompletion();
    return EXIT_SUCCESS; // Indicate that the program finished successfully.
}