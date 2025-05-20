//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Function to print the current state of the towers
void printTowers(int n, int from, int to, int aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from)
            printf(" %d ", from);
        else if (i == to)
            printf(" %d ", to);
        else if (i == aux)
            printf(" %d ", aux);
        else
            printf("   ");
    }
    printf("\n");
}

// Function to check if a move is valid or not
int isValidMove(int n, int from, int to, int aux) {
    // The tower to be moved should not be empty
    if (from == -1)
        return 0;

    // The tower to be moved should have at least one disk
    if (n == 1)
        return 0;

    // The destination tower should be empty or have a larger disk on top
    if (to!= -1 && n - to < from)
        return 0;

    // The auxiliary tower should be different from both the source and destination towers
    if (aux == from || aux == to)
        return 0;

    return 1;
}

// Function to move n disks from the source tower to the destination tower using the auxiliary tower
void moveTower(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk 1 from tower %d to tower %d\n", from, to);
        return;
    }

    moveTower(n - 1, from, aux, to);
    printf("Move disk %d from tower %d to tower %d\n", n, from, to);
    moveTower(n - 1, aux, to, from);
}

// Function to solve the Tower of Hanoi problem recursively
void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk 1 from tower %d to tower %d\n", from, to);
        return;
    }

    hanoi(n - 1, from, aux, to);
    printf("Move disk %d from tower %d to tower %d\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n, from, to, aux;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Initial state:\n");
    printTowers(n, 0, 2, 1);

    hanoi(n, 0, 2, 1);

    printf("\nFinal state:\n");
    printTowers(n, 2, 0, 1);

    return 0;
}