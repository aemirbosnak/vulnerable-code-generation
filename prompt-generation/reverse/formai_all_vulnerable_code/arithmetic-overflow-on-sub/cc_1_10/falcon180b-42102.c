//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
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

// Function to check if a move is valid
int isValidMove(int n, char from, char to, char aux) {
    if (from == to) {
        return 0;
    }
    if (from == 'A' && to == 'B' && aux == 'C') {
        return 0;
    }
    if (from == 'B' && to == 'A' && aux == 'C') {
        return 0;
    }
    if (from == 'C' && to == 'B' && aux == 'A') {
        return 0;
    }
    if (from == 'C' && to == 'A' && aux == 'B') {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void moveDisk(int n, char from, char to, char aux) {
    printf("Moving disk %d from %c to %c\n", n, from, to);
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        moveDisk(n, from, to, aux);
        return;
    }
    hanoi(n - 1, from, aux, to);
    moveDisk(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}