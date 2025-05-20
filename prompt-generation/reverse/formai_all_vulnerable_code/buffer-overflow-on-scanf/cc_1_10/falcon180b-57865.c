//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the tower
void printTower(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("Move disk 1 from %c to %c\n", from, to);
        else if (i % 2 == 0)
            printf("Move disk %d from %c to %c\n", i + 1, from, to);
        else
            printf("Move disk %d from %c to %c\n", i + 1, from, to);
    }
}

// Function to check if a move is valid
int isValid(int n, int from, int to) {
    if (from < 0 || to < 0 || from >= n || to >= n)
        return 0;
    else if (from == to)
        return 1;
    else if (from > to)
        return 0;
    else
        return 1;
}

// Function to solve the Tower of Hanoi problem
void solve(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    solve(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    solve(n - 1, aux, to, from);
}

int main(void) {
    int n;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Check if the input is valid
    if (n <= 0) {
        printf("Invalid input!\n");
        return 0;
    }

    // Solve the Tower of Hanoi problem
    printf("Tower of Hanoi with %d disks:\n", n);
    solve(n, 'A', 'C', 'B');

    return 0;
}