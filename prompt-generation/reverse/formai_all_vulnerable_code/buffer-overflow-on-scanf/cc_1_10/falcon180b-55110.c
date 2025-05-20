//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the tower of Hanoi
void printTower(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    printf("Move disk %d from %c to %c\n", n, from, to);
}

// Function to check if a move is valid
int isValidMove(int n, char from, char to, char aux) {
    if (from == to)
        return 0;
    if (from == 'A' && to == 'C' && aux == 'B')
        return 0;
    if (from == 'B' && to == 'A' && aux == 'C')
        return 0;
    if (from == 'C' && to == 'B' && aux == 'A')
        return 0;
    return 1;
}

// Function to move n disks from from to to using aux
void moveTower(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    moveTower(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    moveTower(n - 1, aux, to, from);
}

// Function to solve the tower of Hanoi problem
void solveTower(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    solveTower(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    solveTower(n - 1, aux, to, from);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Invalid number of disks\n");
        return 0;
    }
    printf("Tower of Hanoi with %d disks:\n", n);
    solveTower(n, 'A', 'C', 'B');
    return 0;
}