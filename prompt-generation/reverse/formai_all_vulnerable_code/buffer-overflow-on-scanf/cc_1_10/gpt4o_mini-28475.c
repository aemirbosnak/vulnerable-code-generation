//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: curious
#include <stdio.h>

// Function to print the current state of the towers
void printTowers(int towerA[], int sizeA, int towerB[], int sizeB, int towerC[], int sizeC) {
    printf("\nCurrent State of Towers:\n");
    printf("Tower A: ");
    for (int i = 0; i < sizeA; i++) {
        printf("%d ", towerA[i]);
    }
    printf("\nTower B: ");
    for (int i = 0; i < sizeB; i++) {
        printf("%d ", towerB[i]);
    }
    printf("\nTower C: ");
    for (int i = 0; i < sizeC; i++) {
        printf("%d ", towerC[i]);
    }
    printf("\n");
}

// Function to recursively solve the Tower of Hanoi problem
void solveHanoi(int n, int source, int target, int auxiliary, int towerA[], int towerB[], int towerC[], 
                int *sizeA, int *sizeB, int *sizeC) {
    // Base case: when there is only one disk to move
    if (n == 1) {
        if (source == 0) {
            towerC[(*sizeC)++] = towerA[--(*sizeA)];
        } else if (source == 1) {
            towerC[(*sizeC)++] = towerB[--(*sizeB)];
        } else {
            towerA[(*sizeA)++] = towerC[--(*sizeC)];
        }
        
        printTowers(towerA, *sizeA, towerB, *sizeB, towerC, *sizeC);
        return;
    }
    
    // Recursive call to move n-1 disks from source to auxiliary
    solveHanoi(n - 1, source, auxiliary, target, towerA, towerB, towerC, sizeA, sizeB, sizeC);

    // Move the nth disk from source to target
    if (source == 0) {
        towerC[(*sizeC)++] = towerA[--(*sizeA)];
    } else if (source == 1) {
        towerC[(*sizeC)++] = towerB[--(*sizeB)];
    } else {
        towerA[(*sizeA)++] = towerC[--(*sizeC)];
    }

    printTowers(towerA, *sizeA, towerB, *sizeB, towerC, *sizeC);

    // Move the n-1 disks from auxiliary to target using source as a temporary holder
    solveHanoi(n - 1, auxiliary, target, source, towerA, towerB, towerC, sizeA, sizeB, sizeC);
}

// Main function to run the Tower of Hanoi solution
int main() {
    int n; // number of disks
    printf("Welcome to the Tower of Hanoi!\n");
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    // Initializing the towers
    int towerA[n], towerB[n], towerC[n];
    int sizeA = n, sizeB = 0, sizeC = 0;
    
    // Fill tower A with disks
    for (int i = n; i >= 1; i--) {
        towerA[n - i] = i; // disks are represented as numbers
    }

    // Print initial state of the towers
    printf("\nLet's set up the Towers of Hanoi!\n");
    printTowers(towerA, sizeA, towerB, sizeB, towerC, sizeC);

    // Begin the recursive solution
    solveHanoi(n, 0, 2, 1, towerA, towerB, towerC, &sizeA, &sizeB, &sizeC);

    printf("\nCongratulations! All disks moved to Tower C successfully.\n");
    return 0;
}