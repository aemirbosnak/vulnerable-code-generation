//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Function to print the disks in a tower */
void printTower(int tower[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

/* Function to move a disk from one tower to another */
void moveDisk(int fromTower[], int toTower[], int n, int fromIndex, int toIndex)
{
    int disk = fromTower[fromIndex];
    fromTower[fromIndex] = 0;
    toTower[toIndex] = disk;
}

/* Function to check if a move is valid */
int isValidMove(int fromTower[], int toTower[], int n, int fromIndex, int toIndex)
{
    int i;
    for (i = 0; i < n; i++) {
        if (i!= fromIndex && fromTower[i] > fromTower[fromIndex])
            return 0;
        if (i!= toIndex && toTower[i] > fromTower[fromIndex])
            return 0;
    }
    return 1;
}

/* Function to solve the Tower of Hanoi problem */
void solveTower(int n, int fromTower[], int toTower[], int auxTower[])
{
    if (n == 1) {
        moveDisk(fromTower, toTower, 1, 0, 0);
        return;
    }
    solveTower(n - 1, fromTower, auxTower, toTower);
    moveDisk(fromTower, toTower, n, 0, n - 1);
    solveTower(n - 1, auxTower, toTower, fromTower);
}

/* Function to count the number of moves required to solve the problem */
int countMoves(int n)
{
    int moves = 0;
    int i;
    for (i = 0; i < n; i++) {
        moves += (2 * i + 1);
    }
    return moves;
}

int main()
{
    int n, moves;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    int fromTower[MAX], toTower[MAX], auxTower[MAX];
    for (int i = n; i >= 1; i--) {
        fromTower[n - i] = i;
    }
    solveTower(n, fromTower, toTower, auxTower);
    moves = countMoves(n);
    printf("Minimum number of moves: %d\n", moves);
    return 0;
}