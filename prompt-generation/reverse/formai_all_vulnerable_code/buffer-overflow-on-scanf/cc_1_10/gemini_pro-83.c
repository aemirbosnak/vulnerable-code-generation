//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function to print the current state of the towers
void printTowers(int numDisks, int towerA[], int towerB[], int towerC[]) {
    printf("Tower A: ");
    for (int i = 0; i < numDisks; i++) {
        printf("%d ", towerA[i]);
    }
    printf("\n");

    printf("Tower B: ");
    for (int i = 0; i < numDisks; i++) {
        printf("%d ", towerB[i]);
    }
    printf("\n");

    printf("Tower C: ");
    for (int i = 0; i < numDisks; i++) {
        printf("%d ", towerC[i]);
    }
    printf("\n\n");
}

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int numDisks, int towerA[], int towerB[], int towerC[]) {
    // Base case: If there are no disks, do nothing
    if (numDisks == 0) {
        return;
    }

    // Recursive case:
    // 1. Move the top disk from tower A to tower B
    towerB[numDisks - 1] = towerA[numDisks - 1];

    // 2. Print the current state of the towers
    printTowers(numDisks, towerA, towerB, towerC);

    // 3. Solve the problem for the remaining disks
    towerOfHanoi(numDisks - 1, towerA, towerC, towerB);

    // 4. Move the top disk from tower B to tower C
    towerC[numDisks - 1] = towerB[numDisks - 1];

    // 5. Print the current state of the towers
    printTowers(numDisks, towerA, towerB, towerC);

    // 6. Solve the problem for the remaining disks
    towerOfHanoi(numDisks - 1, towerC, towerB, towerA);
}

// Main function
int main() {
    // Get the number of disks from the user
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Create three towers to hold the disks
    int towerA[numDisks], towerB[numDisks], towerC[numDisks];

    // Initialize the towers
    for (int i = 0; i < numDisks; i++) {
        towerA[i] = numDisks - i;
        towerB[i] = 0;
        towerC[i] = 0;
    }

    // Print the initial state of the towers
    printTowers(numDisks, towerA, towerB, towerC);

    // Solve the Tower of Hanoi problem
    towerOfHanoi(numDisks, towerA, towerB, towerC);

    return 0;
}