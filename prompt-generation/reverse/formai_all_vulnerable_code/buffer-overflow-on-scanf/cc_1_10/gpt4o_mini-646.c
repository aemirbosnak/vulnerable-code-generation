//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>

// Function to perform the recursive steps of Tower of Hanoi
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case: If there's only one disk to move, do it directly
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    // Move n-1 disks from source to auxiliary, using destination as a temporary peg
    towerOfHanoi(n - 1, source, auxiliary, destination);
    // Move the nth disk from source to destination
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    // Move the n-1 disks from auxiliary to destination, using source as a temporary peg
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Function to display the introduction of the problem
void displayIntro(int n) {
    printf("Welcome to the Tower of Hanoi!\n");
    printf("In this puzzle, you have %d disks.\n", n);
    printf("There are three rods: A (Source), B (Auxiliary), and C (Destination).\n");
    printf("The goal is to move all the disks from rod A to rod C while following the rules:\n");
    printf("1. Only one disk can be moved at a time.\n");
    printf("2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.\n");
    printf("3. No larger disk may be placed on top of a smaller disk.\n");
    printf("\nLet's get started!\n\n");
}

// The main function that sets everything in motion
int main() {
    int n;

    // Prompt the user for the number of disks
    printf("Enter the number of disks you want to use (1-10): ");
    scanf("%d", &n);

    // Ensure number of disks is within a reasonable range
    if (n < 1 || n > 10) {
        printf("Please enter a valid number of disks between 1 and 10.\n");
        return 1;
    }

    // Display the introduction
    displayIntro(n);

    // Perform the Tower of Hanoi solution steps
    printf("The sequence of moves involved in solving the Tower of Hanoi:\n");
    towerOfHanoi(n, 'A', 'C', 'B');

    printf("\nCongratulations! You've completed the Tower of Hanoi with %d disks!\n", n);

    return 0;
}