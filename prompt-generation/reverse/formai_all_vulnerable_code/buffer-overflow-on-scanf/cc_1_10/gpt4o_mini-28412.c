//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: creative
#include <stdio.h>

// Define the maximum number of disks
#define MAX_DISKS 10

// Function prototypes
void towerOfHanoi(int n, char source, char destination, char auxiliary);
void printInstructions();
void printDisks(int n, char tower);

// Main function
int main() {
    int numDisks;

    printInstructions();
    
    // Read the number of disks from user
    printf("Enter the number of disks (1 to %d): ", MAX_DISKS);
    scanf("%d", &numDisks);
    
    // Validate the input
    if (numDisks < 1 || numDisks > MAX_DISKS) {
        printf("Invalid number of disks. Please restart the program.\n");
        return 1;
    }

    printf("\nSolving Tower of Hanoi with %d disks:\n", numDisks);
    towerOfHanoi(numDisks, 'A', 'C', 'B'); // A, C, and B are names of rods

    return 0;
}

// Function to print instructions to the user
void printInstructions() {
    printf("Welcome to the Tower of Hanoi!\n");
    printf("Instructions:\n");
    printf("1. You have three rods (A, B, C) and a number of disks.\n");
    printf("2. The disks start on rod A in ascending order (smallest on top).\n");
    printf("3. Move all the disks to rod C following these rules:\n");
    printf("   - Only one disk can be moved at a time.\n");
    printf("   - Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.\n");
    printf("   - No larger disk may be placed on top of a smaller disk.\n");
}

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Function to print the disks on a specified tower
void printDisks(int n, char tower) {
    printf("Current disks on tower %c: ", tower);
    for (int i = 1; i <= n; i++) {
        printf("[%d] ", i);
    }
    printf("\n");
}