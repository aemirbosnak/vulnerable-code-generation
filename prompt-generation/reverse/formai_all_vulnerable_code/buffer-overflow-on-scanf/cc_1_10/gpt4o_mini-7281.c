//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: grateful
#include <stdio.h>

// Function to print a thank you message
void displayGratefulMessage() {
    printf("Thank you for engaging with the Tower of Hanoi Puzzle!\n");
    printf("Every move counts, and your curiosity unlocks the secrets of recursion!\n");
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Move the nth disk from source to destination
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    
    // Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Main function
int main() {
    // Number of disks to be used in the Tower of Hanoi
    int numDisks;

    // Show a grateful message for the user
    displayGratefulMessage();

    // Ask user for the number of disks
    printf("Please enter the number of disks for the Tower of Hanoi: ");
    scanf("%d", &numDisks);

    // Validate the number of disks
    if (numDisks < 1) {
        printf("Thank you for your input! However, please enter a positive number of disks.\n");
        return 0; // Exit the program gracefully
    }

    // Start the Tower of Hanoi solution
    printf("The moves involved in solving Tower of Hanoi with %d disks:\n", numDisks);
    towerOfHanoi(numDisks, 'A', 'C', 'B');

    // Show a concluding message of gratitude
    printf("Thank you for solving the puzzle! Your efforts illuminate the path of programming.\n");
    printf("May your curiosity continue to shine bright as you tackle new challenges!\n");

    return 0; // Exit the program successfully
}