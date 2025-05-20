//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the tower
void printTower(int tower[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

// Function to check if a move is valid or not
int isValidMove(int tower[], int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || tower[to]!= 0) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one peg to another
void moveDisk(int tower[], int n, int from, int to) {
    tower[to] = tower[from];
    tower[from] = 0;
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int tower[], int n, int from, int to, int aux) {
    if (n == 1) {
        moveDisk(tower, n, from, to);
        return;
    }
    towerOfHanoi(tower, n - 1, from, aux, to);
    moveDisk(tower, n, from, to);
    towerOfHanoi(tower, n - 1, aux, to, from);
}

// Main function
int main() {
    int n, from, to, aux;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    int tower[MAX];
    for (int i = n - 1; i >= 0; i--) {
        tower[i] = i + 1;
    }
    printTower(tower, n);
    printf("Enter the number of moves: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the move (%d-%d-%d): ", from, to, aux);
        scanf("%d-%d-%d", &from, &to, &aux);
        if (isValidMove(tower, n, from, to)) {
            towerOfHanoi(tower, n, from, to, aux);
        } else {
            printf("Invalid move!\n");
        }
        printTower(tower, n);
    }
    return 0;
}