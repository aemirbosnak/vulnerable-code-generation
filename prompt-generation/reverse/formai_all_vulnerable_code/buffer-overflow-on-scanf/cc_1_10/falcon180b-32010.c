//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the towers
void printTowers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("Move disk 1 from %c to %c\n", from, to);
        else if (i == n - 1)
            printf("Move disk %d from %c to %c\n", n, from, to);
        else
            printf("Move disk %d from %c to %c\n", i + 1, from, to);
    }
}

// Function to check if a move is valid
int isValidMove(int n, char from, char to, char aux) {
    if (from == to)
        return 0;
    else if (from == 'A' && to == 'C' && aux == 'B')
        return 0;
    else if (from == 'B' && to == 'A' && aux == 'C')
        return 0;
    else if (from == 'C' && to == 'B' && aux == 'A')
        return 0;
    else
        return 1;
}

// Function to move n disks from from rod to to rod using aux rod
void moveTower(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    moveTower(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    moveTower(n - 1, aux, to, from);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    moveTower(n, 'A', 'C', 'B');
    return 0;
}