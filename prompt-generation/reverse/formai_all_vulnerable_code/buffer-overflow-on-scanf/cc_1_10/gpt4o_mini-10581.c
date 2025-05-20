//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Claude Shannon
#include <stdio.h>

// Function to implement the Tower of Hanoi algorithm
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case: If there is only one disk, just move it from source to destination
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move top n - 1 disks from source to auxiliary, using destination as a temporary peg
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    // Move the n - 1 disks from auxiliary to destination, using source as a temporary peg
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Function to display instructions and collect user input
void displayInstructions() {
    printf("Welcome to the Tower of Hanoi program!\n");
    printf("Instructions:\n");
    printf("1. You will choose the number of disks to solve the Tower of Hanoi problem.\n");
    printf("2. The solution will display the moves required to transfer all disks from one peg to another.\n");
}

// Main function
int main() {
    int numberOfDisks;

    // Display the instructions for the user
    displayInstructions();

    // Prompt the user for the number of disks
    printf("Please enter the number of disks (greater than 0): ");
    scanf("%d", &numberOfDisks);

    // Validate the user input
    if (numberOfDisks <= 0) {
        printf("Invalid number of disks. Must be greater than 0.\n");
        return 1; // Exit the program if input is invalid
    }

    // Start the Tower of Hanoi process
    printf("The sequence of moves involved in the Tower of Hanoi are as follows:\n");
    towerOfHanoi(numberOfDisks, 'A', 'C', 'B'); // A, B and C are names of rods

    printf("All disks have been moved from Rod A to Rod C using Rod B!\n");
    return 0; // Successful program termination
}