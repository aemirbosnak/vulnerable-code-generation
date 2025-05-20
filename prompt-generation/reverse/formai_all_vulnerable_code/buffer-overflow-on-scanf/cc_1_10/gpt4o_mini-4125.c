//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
#include <stdio.h>

// Function to move disks between towers
void moveDisk(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }
    moveDisk(n - 1, fromRod, auxRod, toRod);
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
    moveDisk(n - 1, auxRod, toRod, fromRod);
}

// Function to display the current state of rods and disks
void displayState(int n, char rods[3], int tower[n][3]) {
    printf("Current State of Towers:\n");
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (tower[i][j] != 0) {
                printf("%d\t", tower[i][j]);
            } else {
                printf("|\t");
            }
        }
        printf("\n");
    }
    printf("Rods labels: %c %c %c\n\n", rods[0], rods[1], rods[2]);
}

// Initialize the game
void initGame(int n, char rods[3], int tower[n][3]) {
    // Set up initial state with all disks on the first rod
    for (int i = 0; i < n; i++) {
        tower[i][0] = n - i; // Assign disk number, larger number means larger size
        tower[i][1] = 0;     // No disks on second rod
        tower[i][2] = 0;     // No disks on third rod
    }
}

void moveAndDisplay(int n, char fromRod, char toRod, char auxRod, int tower[n][3]) {
    if (n == 1) {
        // Move the disk and update tower state
        for (int i = 0; i < n; i++) {
            if (tower[i][0] != 0) {
                tower[i][1] = tower[i][0]; // Move from rod 1 to rod 2
                tower[i][0] = 0; // Remove the disk from rod 1
                break;
            }
        }
        displayState(n, (char[]){fromRod, toRod, auxRod}, tower);
        return;
    }
    moveAndDisplay(n - 1, fromRod, auxRod, toRod, tower);
    for (int i = 0; i < n; i++) {
        if (tower[i][0] != 0) {
            tower[i][2] = tower[i][0]; // Move from rod 1 to rod 3
            tower[i][0] = 0; // Remove the disk from rod 1
            break;
        }
    }
    displayState(n, (char[]){fromRod, toRod, auxRod}, tower);
    moveAndDisplay(n - 1, auxRod, toRod, fromRod, tower);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number of disks.\n");
        return 1;
    }

    // Rod labels
    char rods[3] = {'A', 'B', 'C'};
    
    // Tower representation
    int tower[n][3]; // n disks and 3 rods
    initGame(n, rods, tower);

    printf("Initial State:\n");
    displayState(n, rods, tower);

    // Start moving disks
    printf("The sequence of moves to solve Tower of Hanoi is:\n");
    moveAndDisplay(n, rods[0], rods[1], rods[2], tower);

    return 0;
}