//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ultraprecise
#include <stdio.h>

// Function to move disks between the rods
void moveDisk(int n, char from_rod, char to_rod) {
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
}

// Recursive function to implement Tower of Hanoi
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        moveDisk(1, from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    moveDisk(n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Function to display the introduction and instructions
void displayIntro() {
    printf("Welcome to the Tower of Hanoi Problem Solver!\n");
    printf("The Tower of Hanoi consists of three rods and a number of disks of different sizes which can slide onto any rod.\n");
    printf("The puzzle starts with the disks stacked in ascending order of size on one rod, the smallest on top.\n");
    printf("The objective of the puzzle is to move the entire stack to another rod, obeying the following rules:\n");
    printf("1. Only one disk can be moved at a time.\n");
    printf("2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.\n");
    printf("3. No larger disk may be placed on top of a smaller disk.\n\n");
}

// Function to read user input for number of disks
int readNumberOfDisks() {
    int numDisks = 0;
    printf("Please enter the number of disks (1 to 10): ");
    while (1) {
        scanf("%d", &numDisks);
        if (numDisks >= 1 && numDisks <= 10) {
            break;
        }
        printf("Invalid input. Please enter a number between 1 and 10: ");
    }
    return numDisks;
}

// Main function
int main() {
    displayIntro();
    
    int numDisks = readNumberOfDisks();
    
    // Displaying the starting configuration
    printf("\nThe following moves will solve the Tower of Hanoi with %d disks:\n", numDisks);
    
    // Solve the Tower of Hanoi problem
    towerOfHanoi(numDisks, 'A', 'C', 'B');
    
    printf("\nCongratulations! You have successfully solved the Tower of Hanoi puzzle!\n");
    
    return 0;
}