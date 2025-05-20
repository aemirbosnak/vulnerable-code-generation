//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Helper function to move a disk from one peg to another
void move_disk(int* disks, int from_peg, int to_peg, int n) {
    // Move the disk from the 'from_peg' to the 'to_peg'
    disks[to_peg] = disks[from_peg];
    // Update the number of disks in the 'from_peg' and 'to_peg'
    disks[from_peg] = 0;
    disks[to_peg]++;
}

// Helper function to print the current state of the disks
void print_disks(int* disks, int n) {
    // Print the current state of the disks
    printf("Peg 1: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", disks[1]);
    }
    printf("\nPeg 2: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", disks[2]);
    }
    printf("\nPeg 3: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", disks[3]);
    }
    printf("\n");
}

// Main function to solve the Tower of Hanoi problem
void hanoi(int n, int source_peg, int target_peg, int helper_peg) {
    // Initialize the number of disks to 'n'
    int disks[n+1];
    for (int i = 1; i <= n; i++) {
        disks[i] = i;
    }
    // Print the initial state of the disks
    printf("Initial state:\n");
    print_disks(disks, n);
    // Move all disks from the'source_peg' to the 'target_peg'
    if (n > 0) {
        hanoi(n-1, source_peg, helper_peg, target_peg);
        move_disk(disks, source_peg, target_peg, n);
        hanoi(n-1, helper_peg, target_peg, source_peg);
    }
    // Print the final state of the disks
    printf("Final state:\n");
    print_disks(disks, n);
}

// Main function to run the program
int main() {
    // Get the number of disks from the user
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    // Check if the number of disks is valid
    if (n < 0 || n > INT_MAX) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    // Run the Tower of Hanoi algorithm
    hanoi(n, 1, 3, 2);
    // Print a message to indicate the program has finished
    printf("Program finished.\n");
    return 0;
}