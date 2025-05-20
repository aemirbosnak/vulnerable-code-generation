//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISK 10

// Struct to represent a stack (used for implementing rod)
typedef struct {
    int disks[MAX_DISK];
    int top;
} Rod;

// Function prototypes
void initializeRod(Rod *rod);
void push(Rod *rod, int disk);
int pop(Rod *rod);
void printTowers(Rod *A, Rod *B, Rod *C, int numDisks);
void towerOfHanoi(int n, Rod *source, Rod *target, Rod *auxiliary);

// Main function
int main() {
    int numDisks;
    printf("Welcome to the Tower of Hanoi simulation!\n");
    printf("Enter the number of disks (1 to %d): ", MAX_DISK);
    scanf("%d", &numDisks);
    
    // Validate user input
    if (numDisks < 1 || numDisks > MAX_DISK) {
        printf("Invalid number of disks. Please enter a number between 1 and %d.\n", MAX_DISK);
        return EXIT_FAILURE;
    }

    // Initializing rods
    Rod A, B, C;
    initializeRod(&A);
    initializeRod(&B);
    initializeRod(&C);

    // Push disks onto rod A (source)
    for (int i = numDisks; i >= 1; i--) {
        push(&A, i);
    }

    // Print initial state of the rods
    printf("\nInitial state of the rods:\n");
    printTowers(&A, &B, &C, numDisks);
    printf("\nStarting the Tower of Hanoi...\n");

    // Solve the Tower of Hanoi
    towerOfHanoi(numDisks, &A, &C, &B);

    // Final state of the rods
    printf("\nFinal state of the rods:\n");
    printTowers(&A, &B, &C, numDisks);

    return EXIT_SUCCESS;
}

// Initialize a rod as empty
void initializeRod(Rod *rod) {
    rod->top = -1;
}

// Push a disk onto the rod
void push(Rod *rod, int disk) {
    if (rod->top < MAX_DISK - 1) {
        rod->disks[++rod->top] = disk;
    } else {
        printf("Cannot push disk %d onto the rod! Maximum limit reached.\n", disk);
    }
}

// Pop a disk from the rod
int pop(Rod *rod) {
    if (rod->top != -1) {
        return rod->disks[rod->top--];
    } else {
        printf("Cannot pop from the rod! It's empty.\n");
        return -1;  // Indicate an error
    }
}

// Function to print the current state of the rods
void printTowers(Rod *A, Rod *B, Rod *C, int numDisks) {
    printf("Rod A: ");
    for (int i = A->top; i >= 0; i--) {
        printf("%d ", A->disks[i]);
    }
    printf("\nRod B: ");
    for (int i = B->top; i >= 0; i--) {
        printf("%d ", B->disks[i]);
    }
    printf("\nRod C: ");
    for (int i = C->top; i >= 0; i--) {
        printf("%d ", C->disks[i]);
    }
    printf("\n\n");
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, Rod *source, Rod *target, Rod *auxiliary) {
    if (n == 1) {
        // Move disk from source to target
        int disk = pop(source);
        push(target, disk);
        printTowers(source, target, auxiliary, n);
        return;
    }

    // Move n-1 disks from source to auxiliary using target as a buffer
    towerOfHanoi(n - 1, source, auxiliary, target);
    
    // Move the nth disk from source to target
    int disk = pop(source);
    push(target, disk);
    printTowers(source, target, auxiliary, n);

    // Move the n-1 disks from auxiliary to target using source as a buffer
    towerOfHanoi(n - 1, auxiliary, target, source);
}