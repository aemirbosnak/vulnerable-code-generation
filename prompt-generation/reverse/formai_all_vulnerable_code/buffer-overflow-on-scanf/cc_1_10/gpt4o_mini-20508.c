//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: real-life
#include <stdio.h>

// Function to print the current state of the towers
void printTowers(int towerA[], int towerB[], int towerC[], int sizeA, int sizeB, int sizeC) {
    printf("Current Towers State:\n");
    printf("Tower A: ");
    for (int i = sizeA - 1; i >= 0; i--) {
        printf("%d ", towerA[i]);
    }
    printf("\nTower B: ");
    for (int i = sizeB - 1; i >= 0; i--) {
        printf("%d ", towerB[i]);
    }
    printf("\nTower C: ");
    for (int i = sizeC - 1; i >= 0; i--) {
        printf("%d ", towerC[i]);
    }
    printf("\n-----------------------\n");
}

// Function to move disks from one tower to another
void moveDisk(int from[], int to[], int* sizeFrom, int* sizeTo) {
    if (*sizeFrom > 0) {
        // Move the disk from from[] to to[]
        int disk = from[--(*sizeFrom)];
        to[(*sizeTo)++] = disk;
        printf("Moved disk %d from Tower %s to Tower %s\n", disk,
               (from == to) ? "C" : (from == to) ? "C" : "A",
               (to == from) ? "C" : (to == from) ? "C" : "A");
    }
}

// Recursive function to solve the Tower of Hanoi
void solveTowerOfHanoi(int n, int source[], int dest[], int temp[], 
                       int* sizeSource, int* sizeDest, int* sizeTemp) {
    if (n == 1) {
        moveDisk(source, dest, sizeSource, sizeDest);
        printTowers(source, dest, temp, *sizeSource, *sizeDest, *sizeTemp);
        return;
    }
    
    solveTowerOfHanoi(n - 1, source, temp, dest, sizeSource, sizeTemp, sizeDest);
    moveDisk(source, dest, sizeSource, sizeDest);
    printTowers(source, dest, temp, *sizeSource, *sizeDest, *sizeTemp);
    solveTowerOfHanoi(n - 1, temp, dest, source, sizeTemp, sizeDest, sizeSource);
}

// Main function for a real-life Tower of Hanoi Scenario
int main() {
    int n; // Number of disks
    printf("Welcome to the Tower of Hanoi Simulator!\n");

    printf("Please enter the number of disks (1-10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Number of disks must be between 1 and 10.\n");
        return 1;
    }

    int towerA[10], towerB[10], towerC[10];
    int sizeA = 0, sizeB = 0, sizeC = 0;

    // Initialize Tower A with disks
    for (int i = n; i >= 1; i--) {
        towerA[sizeA++] = i;
    }

    printf("Initial Towers State:\n");
    printTowers(towerA, towerB, towerC, sizeA, sizeB, sizeC);

    // Solve the Tower of Hanoi
    solveTowerOfHanoi(n, towerA, towerC, towerB, &sizeA, &sizeC, &sizeB);

    printf("Finished! All disks have been moved to Tower C.\n");
    printTowers(towerA, towerB, towerC, sizeA, sizeB, sizeC);

    return 0;
}