//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 64

// Function to print the state of the rods
void printRods(int rods[3][MAX_DISKS], int diskCount) {
    printf("\nCurrent State of Towers:\n");
    for (int level = diskCount - 1; level >= 0; level--) {
        for (int rod = 0; rod < 3; rod++) {
            if (rods[rod][level] > 0) {
                printf("|%s ", rods[rod][level] == 1 ? "1" : "2");
            } else {
                printf("|  ");
            }
        }
        printf("|\n");
    }
    printf("--+---+---+\n");
    printf("  | 0 | 1 | 2 |\n");
}

// Recursive function to solve Tower of Hanoi
void hanoi(int n, int fromRod, int toRod, int auxRod, int rods[3][MAX_DISKS], int *diskCount) {
    if (n == 1) {
        rods[toRod][(*diskCount)++] = rods[fromRod][--(*diskCount)];
        printRods(rods, *diskCount);
        return;
    }
    hanoi(n - 1, fromRod, auxRod, toRod, rods, diskCount);
    rods[toRod][(*diskCount)++] = rods[fromRod][--(*diskCount)];
    printRods(rods, *diskCount);
    hanoi(n - 1, auxRod, toRod, fromRod, rods, diskCount);
}

// Function to initialize the rods
void initializeRods(int rods[3][MAX_DISKS], int n) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < MAX_DISKS; j++) {
            rods[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        rods[0][i] = i + 1; // Fill the first rod with disks
    }
}

// Main function
int main() {
    int rods[3][MAX_DISKS], n;

    printf("Welcome to the Tower of Hanoi Solver!\n");
    printf("Enter the number of disks (1 to %d): ", MAX_DISKS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks. Please choose between 1 and %d.\n", MAX_DISKS);
        return EXIT_FAILURE;
    }

    int diskCount = n;
    initializeRods(rods, n);
    printRods(rods, diskCount);

    printf("Solving Tower of Hanoi:\n");
    hanoi(n, 0, 2, 1, rods, &diskCount);

    printf("Successfully moved %d disks from tower 0 to tower 2!\n", n);
    return EXIT_SUCCESS;
}