//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: optimized
#include <stdio.h>

// Function to print the current state of the towers
void printTowers(int towers[][3], int numDisks) {
    printf("Current State of Towers:\n");
    for (int i = numDisks; i > 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (towers[j][i] != 0) {
                printf("| %d | ", towers[j][i]);
            } else {
                printf("|   | ");
            }
        }
        printf("\n");
    }
    printf("---------\n");
}

// Function to validate move
int isValidMove(int towers[][3], int from, int to) {
    if (towers[from][0] == 0) {
        return 0; // No disk to move
    }

    if (towers[to][0] != 0 && towers[to][0] < towers[from][0]) {
        return 0; // Cannot place larger disk on smaller disk
    }
    
    return 1;
}

// Function to move disk
void moveDisk(int towers[][3], int from, int to) {
    for (int i = 0; i < 3; i++) {
        if (towers[from][i] != 0) {
            int disk = towers[from][i];
            towers[from][i] = 0; // Remove the disk from the source
            for (int j = 2; j >= 0; j--) {
                if (towers[to][j] == 0) {
                    towers[to][j] = disk; // Place the disk on the target
                    break;
                }
            }
            break; // Exit after moving the disk
        }
    }
}

// Recursive function to solve Tower of Hanoi
void solveHanoi(int numDisks, int from, int to, int aux, int towers[][3]) {
    if (numDisks == 1) {
        if (isValidMove(towers, from, to)) {
            moveDisk(towers, from, to);
            printTowers(towers, numDisks);
        }
    } else {
        solveHanoi(numDisks - 1, from, aux, to, towers);
        if (isValidMove(towers, from, to)) {
            moveDisk(towers, from, to);
            printTowers(towers, numDisks);
        }
        solveHanoi(numDisks - 1, aux, to, from, towers);
    }
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    int towers[3][3] = {0}; // Declare towers and initialize
    // Initialize the first tower with disks
    for (int i = 0; i < numDisks; i++) {
        towers[0][i] = numDisks - i; // Disk size corresponds to its position
    }

    printTowers(towers, numDisks); // Initial state
    solveHanoi(numDisks, 0, 1, 2, towers); // Solve the tower of hanoi

    printf("All disks have been moved to tower 2.\n");
    return 0;
}