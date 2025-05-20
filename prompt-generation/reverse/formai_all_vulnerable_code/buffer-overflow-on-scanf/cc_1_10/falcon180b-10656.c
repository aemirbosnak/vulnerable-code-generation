//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the towers
void printTowers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", 'A' + i);
    }
    printf(" %c %c %c\n", from, to, aux);
}

// Function to check if a move is valid
int isValidMove(int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || from == to) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void moveDisk(int n, char from, char to, char aux) {
    printf("Move disk %d from %c to %c\n", n - 1, from, to);
    if (n == 1) {
        printf("Task completed!\n");
        return;
    }
    moveDisk(n - 1, aux, to, from);
    printf("Move disk %d from %c to %c\n", n - 1, aux, from);
    printf("Move disk %d from %c to %c\n", n - 1, from, to);
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk %d from %c to %c\n", 1, from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    moveDisk(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    hanoi(n, 'A', 'C', 'B');
    return 0;
}