//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdio.h>

// Function to print the current state of the towers
void printTowers(int n, char source, char dest, char aux) {
    printf("Current state of towers with %d discs:\n", n);
    printf("Source Tower (%c): ", source);
    for(int i = n; i > 0; i--) {
        printf("%d ", i);
    }
    printf("\nAuxiliary Tower (%c): ", aux);
    printf("Empty\n");
    printf("Destination Tower (%c): ", dest);
    printf("Empty\n\n");
}

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char dest, char aux) {
    // Base case: only one disc
    if (n == 1) {
        printf("Move disc 1 from tower %c to tower %c\n", source, dest);
        printTowers(n, source, dest, aux);
        return;
    }

    // Move n-1 discs from source to auxiliary, so they are out of the way
    towerOfHanoi(n - 1, source, aux, dest);
    
    // Move the nth disc from source to destination
    printf("Move disc %d from tower %c to tower %c\n", n, source, dest);
    printTowers(n, source, dest, aux);

    // Move the n-1 discs which are now on auxiliary to destination
    towerOfHanoi(n - 1, aux, dest, source);
}

// Main function to drive the program
int main() {
    int n; // Number of discs in the Tower of Hanoi
    printf("Welcome to the Mind-Bending Tower of Hanoi!\n");
    printf("Enter the number of discs (greater than 0): ");
    scanf("%d", &n);
    
    // Validate the number of discs
    if(n <= 0) {
        printf("The number of discs must be greater than 0. Please try again!\n");
        return 1;
    }

    // Print initial state
    printTowers(n, 'A', 'C', 'B');

    // Start the Tower of Hanoi process
    printf("The steps to solve the Tower of Hanoi with %d discs are as follows:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');
    
    printf("Congratulations! You've successfully solved the Tower of Hanoi!\n");
    return 0;
}