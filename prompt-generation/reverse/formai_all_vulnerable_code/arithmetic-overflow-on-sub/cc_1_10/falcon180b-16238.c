//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the disks on the rod
void printDisks(int rod, int n) {
    int i;
    for (i = n; i >= 1; i--) {
        if (i <= n - rod)
            printf("*");
        else
            printf(" ");
    }
    printf("\n");
}

// Function to check if a move is valid
int isValidMove(int from, int to, int aux, int n) {
    // The disk can only be moved if it is the topmost disk
    if (from > 0 && from <= n - 1 && to > 0 && to <= n - 1) {
        if (to == aux || to < from)
            return 0;
        return 1;
    }
    return 0;
}

// Function to move the disk from one rod to another
void moveDisk(int from, int to, int aux, int n) {
    printf("Move disk %d from rod %d to rod %d\n", n, from, to);
}

// Function to solve the tower of Hanoi problem
void towerOfHanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        moveDisk(from, to, aux, n);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    moveDisk(from, to, aux, n);
    towerOfHanoi(n - 1, aux, to, from);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Initialize the rods
    int from = 1, to = 3, aux = 2;

    // Solve the tower of Hanoi problem
    printf("Tower of Hanoi with %d disks:\n", n);
    towerOfHanoi(n, from, to, aux);

    return 0;
}