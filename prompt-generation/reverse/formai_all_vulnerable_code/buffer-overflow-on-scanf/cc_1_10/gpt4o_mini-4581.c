//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ultraprecise
#include <stdio.h>

// A function to perform the Tower of Hanoi algorithm
// n -> number of disks
// source -> the source rod
// target -> the target rod
// auxiliary -> the auxiliary rod
void towerOfHanoi(int n, char source, char target, char auxiliary) {
    // Base case: If only one disk is left, move it from source to target
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, target);
        return;
    }
    // Move n-1 disks from source to auxiliary, using target as a helper
    towerOfHanoi(n - 1, source, auxiliary, target);
    // Move the nth disk from source to target
    printf("Move disk %d from rod %c to rod %c\n", n, source, target);
    // Move the n-1 disks from auxiliary to target, using source as a helper
    towerOfHanoi(n - 1, auxiliary, target, source);
}

// A function to calculate and display the number of moves needed
void displayMoves(int n) {
    // The number of moves required is 2^n - 1
    long long totalMoves = (1 << n) - 1; // using bitwise left shift for power of 2
    printf("Total moves required for %d disks: %lld\n", n, totalMoves);
}

// Function to execute the Tower of Hanoi game
void playTowerOfHanoi(int n) {
    printf("Solving Tower of Hanoi for %d disks:\n", n);
    displayMoves(n);
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
}

int main() {
    int numDisks;
    
    // Prompt user for the number of disks
    printf("Enter the number of disks (1 - 15): ");
    scanf("%d", &numDisks);
    
    // Input validation - number of disks should be between 1 and 15
    if (numDisks < 1 || numDisks > 15) {
        printf("Please enter a valid number of disks between 1 and 15.\n");
        return 1;
    }

    // Start the Tower of Hanoi process
    playTowerOfHanoi(numDisks);

    return 0;
}