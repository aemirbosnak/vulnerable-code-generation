//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the Tower of Hanoi
void printTower(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("Move disk 1 from %c to %c\n", from, to);
        else if (i == n - 1)
            printf("Move disk %d from %c to %c\n", n, from, to);
        else
            printf("Move disk %d from %c to %c\n", n - i, from, to);
    }
}

// Function to check if a move is valid
int isValidMove(int n, char from, char to, char aux) {
    // Base case for recursion
    if (n == 1)
        return 1;

    // Check if the move is valid
    if ((from == 'A' && to == 'C' && aux!= 'B') ||
        (from == 'B' && to == 'A' && aux!= 'C') ||
        (from == 'C' && to == 'B' && aux!= 'A'))
        return 1;

    return 0;
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    hanoi(n - 1, from, aux, to);
    printTower(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

// Main function
int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0)
        printf("Invalid number of disks\n");
    else {
        printf("Tower of Hanoi with %d disks:\n", n);
        hanoi(n, 'A', 'C', 'B');
    }

    return 0;
}