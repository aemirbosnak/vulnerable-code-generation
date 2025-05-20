//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Function to display the current state of the rods
void displayRods(int n, int source[], int destination[], int spare[]) {
    printf("Current State of the Rods:\n");
    printf("Source Rod: ");
    for (int i = n-1; i >= 0; i--) printf("%d ", source[i]);
    printf("\nDestination Rod: ");
    for (int i = n-1; i >= 0; i--) printf("%d ", destination[i]);
    printf("\nSpare Rod: ");
    for (int i = n-1; i >= 0; i--) printf("%d ", spare[i]);
    printf("\n\n");
}

// Function to move disks between rods with visualization
void moveDisk(int n, int source[], int destination[]) {
    if (n == 0) return;
    
    // Move n-1 disks from source to spare
    moveDisk(n - 1, source, destination);
    
    // Move the nth disk from source to destination
    destination[n-1] = source[n-1];
    source[n-1] = 0; // Clear the source
    printf("Moved disk %d from Source to Destination\n", n);
    displayRods(n, source, destination, NULL);
    
    // Move the n-1 disks from spare to destination
    moveDisk(n - 1, destination, source);
}

// Recursive function to solve Tower of Hanoi
void solveTowerOfHanoi(int n, int source[], int destination[], int spare[]) {
    if (n == 0) return;

    printf("Moving %d disks from Source to Destination using Spare\n", n);
    displayRods(n, source, destination, spare);
    
    moveDisk(n, source, destination);
}

int main() {
    int n;

    // User input for number of disks
    printf("Welcome to the Visionary Tower of Hanoi!\n");
    printf("Enter the number of disks (1-10): ");
    scanf("%d", &n);

    // Validation for the number of disks
    if (n < 1 || n > 10) {
        printf("Please enter a number between 1 and 10.\n");
        return 1;
    }

    // Initializing rods
    int *source = (int*)malloc(n * sizeof(int));
    int *destination = (int*)malloc(n * sizeof(int));
    int *spare = (int*)malloc(n * sizeof(int));
    
    // Setting up the source rod with disks
    for (int i = 0; i < n; i++) source[i] = n - i;

    // Displaying the initial setup
    printf("\nInitial Setup:\n");
    displayRods(n, source, destination, spare);
    
    // Solving the Tower of Hanoi
    solveTowerOfHanoi(n, source, destination, spare);

    // Freeing allocated memory
    free(source);
    free(destination);
    free(spare);

    printf("Congratulations! You have successfully solved the Tower of Hanoi with %d disks!\n", n);
    return 0;
}