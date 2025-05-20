//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include <stdio.h>

// Function to display the state of the towers
void displayTowers(int n, char fromPeg, char auxPeg, char toPeg, int disks[]) {
    printf("Current state of Towers:\n");
    printf("Tower %c: ", fromPeg);
    for(int i = n; i >= 1; i--) {
        if(disks[i] == 1)
            printf("|%d| ", i);
    }
    printf("\n");

    printf("Tower %c: ", auxPeg);
    for(int i = n; i >= 1; i--) {
        if(disks[i] == 2)
            printf("|%d| ", i);
    }
    printf("\n");

    printf("Tower %c: ", toPeg);
    for(int i = n; i >= 1; i--) {
        if(disks[i] == 3)
            printf("|%d| ", i);
    }
    printf("\n\n");
}

// Recursive function to perform the Tower of Hanoi
void towerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg, int* moveCount, int disks[]) {
    if(n == 1) {
        // Move the disk
        disks[n] = toPeg == 'A' ? 1 : (toPeg == 'B' ? 2 : 3);
        (*moveCount)++;
        printf("Move disk 1 from %c to %c\n", fromPeg, toPeg);
        displayTowers(n, fromPeg, auxPeg, toPeg, disks);
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, fromPeg, auxPeg, toPeg, moveCount, disks);
    
    // Move the nth disk to target
    disks[n] = toPeg == 'A' ? 1 : (toPeg == 'B' ? 2 : 3);
    (*moveCount)++;
    printf("Move disk %d from %c to %c\n", n, fromPeg, toPeg);
    displayTowers(n, fromPeg, auxPeg, toPeg, disks);
    
    // Move the n-1 disks from auxiliary to target
    towerOfHanoi(n - 1, auxPeg, toPeg, fromPeg, moveCount, disks);
}

int main() {
    int n;

    // Asking user for the number of disks
    printf("Welcome to the Tower of Hanoi Problem!\n");
    printf("Enter the number of disks (1-10): ");
    scanf("%d", &n);
    
    if(n < 1 || n > 10) {
        printf("Please enter a valid number of disks between 1 and 10.\n");
        return 1;
    }

    int disks[11] = {0}; // Array to track the position of the disks (1-3 representing pegs)
    int moveCount = 0;

    printf("\nStarting Tower of Hanoi with %d disks:\n", n);
    displayTowers(n, 'A', 'B', 'C', disks);

    towerOfHanoi(n, 'A', 'C', 'B', &moveCount, disks);

    printf("Total moves: %d\n", moveCount);
    return 0;
}