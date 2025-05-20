//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Function to print the current state of the towers
void printTowers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("Move disk %d from %c to %c\n", n, from, to);
}

// Function to check if the move is valid or not
int isValidMove(int n, char from, char to, char aux) {
    if (to == 'A' || to == 'C') {
        if (from == 'B') {
            return 1;
        }
    } else if (to == 'B' || to == 'A') {
        if (from == 'C') {
            return 1;
        }
    } else if (to == 'B' || to == 'C') {
        if (from == 'A') {
            return 1;
        }
    }
    return 0;
}

// Function to move n disks from fromTower to toTower using auxTower
void moveDisk(int n, char fromTower, char toTower, char auxTower) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", fromTower, toTower);
        return;
    }
    moveDisk(n - 1, fromTower, auxTower, toTower);
    printf("Move disk %d from %c to %c\n", n, fromTower, toTower);
    moveDisk(n - 1, auxTower, toTower, fromTower);
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char fromTower, char toTower, char auxTower) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", fromTower, toTower);
        return;
    }
    towerOfHanoi(n - 1, fromTower, auxTower, toTower);
    if (isValidMove(n, fromTower, toTower, auxTower)) {
        moveDisk(n, fromTower, toTower, auxTower);
    }
    towerOfHanoi(n - 1, auxTower, toTower, fromTower);
}

// Main function to run the program
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}