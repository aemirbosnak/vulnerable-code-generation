//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the towers
void printTowers(int n, int source, int dest, int aux) {
    int i;
    for (i = 0; i <= n; i++) {
        if (i == source)
            printf("*");
        else if (i == dest)
            printf("*");
        else
            printf(" ");
    }
    printf("\n");
}

// Function to check if a move is valid or not
int isValidMove(int n, int from, int to, int aux) {
    // Base case
    if (n == 0 || n == 1)
        return 1;

    // Check if the disk can be moved from the source to the destination
    if (from == to)
        return 0;

    // Check if the destination tower is not empty
    if (to == 0 && aux!= 0)
        return 0;

    // Check if the auxiliary tower is not empty
    if (aux == 0 || aux == to)
        return 0;

    // Check if the disk can be moved from the source to the auxiliary tower
    if (!isValidMove(n - 1, from, aux, to))
        return 0;

    // Check if the disk can be moved from the auxiliary tower to the destination
    if (!isValidMove(n - 1, aux, to, from))
        return 0;

    return 1;
}

// Function to move the disks from the source to the destination using the auxiliary tower
void moveDisk(int n, int source, int dest, int aux) {
    // Base case
    if (n == 0)
        return;

    // Move n-1 disks from the source to the auxiliary tower
    moveDisk(n - 1, source, aux, dest);

    // Move the last disk from the source to the destination
    printf("Move disk %d from tower %d to tower %d\n", n, source, dest);

    // Move n-1 disks from the auxiliary tower to the destination
    moveDisk(n - 1, aux, dest, source);
}

// Function to solve the Tower of Hanoi problem
void solveTowerOfHanoi(int n, int source, int dest, int aux) {
    if (isValidMove(n, source, dest, aux)) {
        moveDisk(n, source, dest, aux);
        printf("The puzzle is solved!\n");
    } else {
        printf("Invalid move!\n");
    }
}

int main() {
    int n, source, dest, aux;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Enter the source tower: ");
    scanf("%d", &source);

    printf("Enter the destination tower: ");
    scanf("%d", &dest);

    printf("Enter the auxiliary tower: ");
    scanf("%d", &aux);

    solveTowerOfHanoi(n, source, dest, aux);

    return 0;
}