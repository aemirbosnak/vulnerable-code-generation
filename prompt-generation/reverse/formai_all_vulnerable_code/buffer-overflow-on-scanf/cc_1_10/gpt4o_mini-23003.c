//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Function to print the state of the towers
void printTowers(int numDisks, char source, char target, char auxiliary, int **towers) {
    printf("\nCurrent state of Towers:\n");
    for (int i = numDisks; i > 0; i--) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            if (towers[j][i - 1] == 1) {
                printf("|   ");
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
    printf("   %c   %c   %c\n", source, auxiliary, target);
    printf("------------------------\n");
}

// Function to initialize the towers
int **initializeTowers(int numDisks) {
    int **towers = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        towers[i] = (int *)calloc(numDisks, sizeof(int));
    }
    for (int i = 0; i < numDisks; i++) {
        towers[0][i] = 1; // All disks are on source tower initially
    }
    return towers;
}

// Function to move a disk between towers
void moveDisk(int **towers, int numDisks, char from, char to) {
    int fromIdx = (from == 'A') ? 0 : (from == 'B') ? 1 : 2;
    int toIdx = (to == 'A') ? 0 : (to == 'B') ? 1 : 2;

    // Find the top disk on the source tower
    int sourceDisk = -1;
    for (int i = 0; i < numDisks; i++) {
        if (towers[fromIdx][i] == 1) {
            sourceDisk = i;
            break;
        }
    }
    // Move the disk from source to target
    if (sourceDisk != -1) {
        towers[fromIdx][sourceDisk] = 0;
        for (int i = numDisks - 1; i >= 0; i--) {
            if (towers[toIdx][i] == 0) {
                towers[toIdx][i] = 1;
                break;
            }
        }
    }
}

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int numDisks, char source, char target, char auxiliary, int **towers) {
    if (numDisks == 1) {
        moveDisk(towers, numDisks, source, target);
        printTowers(numDisks, source, target, auxiliary, towers);
        return;
    }
    towerOfHanoi(numDisks - 1, source, auxiliary, target, towers);
    moveDisk(towers, numDisks, source, target);
    printTowers(numDisks, source, target, auxiliary, towers);
    towerOfHanoi(numDisks - 1, auxiliary, target, source, towers);
}

// Function to free allocated memory for towers
void freeTowers(int **towers) {
    for (int i = 0; i < 3; i++) {
        free(towers[i]);
    }
    free(towers);
}

int main() {
    int numDisks;
    
    printf("Enter the number of disks (between 1 and 10): ");
    scanf("%d", &numDisks);
    
    if (numDisks < 1 || numDisks > 10) {
        fprintf(stderr, "Invalid number of disks. Please enter a number between 1 and 10.\n");
        return 1;
    }

    int **towers = initializeTowers(numDisks);
    
    printf("Solving Tower of Hanoi for %d disks:\n", numDisks);
    printTowers(numDisks, 'A', 'C', 'B', towers);
    
    towerOfHanoi(numDisks, 'A', 'C', 'B', towers);
    
    freeTowers(towers);
    
    return 0;
}