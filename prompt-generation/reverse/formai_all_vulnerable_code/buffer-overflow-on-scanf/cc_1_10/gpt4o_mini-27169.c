//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 64  // Maximum number of disks allowed

// Function prototypes
void moveDisk(char fromTower, char toTower);
void displayTowers(int disks, char towers[3][MAX_DISKS]);
void hanoi(int numDisks, char fromTower, char toTower, char auxTower, char towers[3][MAX_DISKS]);

// Move disk function
void moveDisk(char fromTower, char toTower) {
    printf("Moving disk from %c to %c\n", fromTower, toTower);
}

// Function to display the current state of the towers
void displayTowers(int disks, char towers[3][MAX_DISKS]) {
    printf("\nCurrent state of the towers:\n");
    printf("Tower A: ");
    for (int i = 0; i < disks; i++) {
        if (towers[0][i] != '\0') {
            printf("%c ", towers[0][i]);
        }
    }
    printf("\nTower B: ");
    for (int i = 0; i < disks; i++) {
        if (towers[1][i] != '\0') {
            printf("%c ", towers[1][i]);
        }
    }
    printf("\nTower C: ");
    for (int i = 0; i < disks; i++) {
        if (towers[2][i] != '\0') {
            printf("%c ", towers[2][i]);
        }
    }
    printf("\n");
}

// Recursive function to solve the Tower of Hanoi problem
void hanoi(int numDisks, char fromTower, char toTower, char auxTower, char towers[3][MAX_DISKS]) {
    if (numDisks == 1) {
        moveDisk(fromTower, toTower);
        int fromIndex = (fromTower - 'A') + numDisks - 1; // Find index in the tower base to place disk
        towers[fromTower - 'A'][fromIndex] = '\0'; // Remove disk from source tower
        int toIndex = (toTower - 'A') + MAX_DISKS - 1;
        towers[toTower - 'A'][toIndex] = fromTower + 1; // Place disk on destination tower (pseudo disk representation)
        
        displayTowers(numDisks, towers);
        return;
    }
    hanoi(numDisks - 1, fromTower, auxTower, toTower, towers);
    moveDisk(fromTower, toTower);
    int fromIndex = (fromTower - 'A') + numDisks - 1;
    towers[fromTower - 'A'][fromIndex] = '\0'; // Remove disk from source tower
    int toIndex = (toTower - 'A') + MAX_DISKS - 1;
    towers[toTower - 'A'][toIndex] = fromTower + 1; // Place disk on destination tower
    displayTowers(numDisks, towers);
    hanoi(numDisks - 1, auxTower, toTower, fromTower, towers);
}

// Main function
int main() {
    int numDisks;
    char towers[3][MAX_DISKS] = {{'A', 'B', 'C'}, {'\0'}, {'\0'}}; // Towers initialized

    printf("Welcome to the Tower of Hanoi Problem!\n");
    do {
        printf("Enter the number of disks (1 - %d): ", MAX_DISKS);
        scanf("%d", &numDisks);
        if (numDisks < 1 || numDisks > MAX_DISKS) {
            printf("Please enter a valid number of disks.\n");
        }
    } while (numDisks < 1 || numDisks > MAX_DISKS);

    // Initialize the source tower with disks
    for (int i = 0; i < numDisks; i++) {
        towers[0][MAX_DISKS - 1 - i] = 'A' + i; // Representing disks by characters
    }

    printf("\nInitial configuration:\n");
    displayTowers(numDisks, towers);
    
    hanoi(numDisks, 'A', 'C', 'B', towers); // Solve the Tower of Hanoi

    printf("\nAll disks moved to Tower C successfully!\n");
    return 0;
}