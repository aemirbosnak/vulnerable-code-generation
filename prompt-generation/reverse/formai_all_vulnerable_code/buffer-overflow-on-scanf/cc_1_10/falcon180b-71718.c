//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
#include <stdio.h>

#define N 3

/* Function to print the current state of the tower */
void printTower(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("Move disk 1 from %c to %c\n", from, to);
        else
            printf("Move disk %d from %c to %c\n", i + 1, from, to);
    }
}

/* Function to check if it is possible to move n disks from from to to */
int isPossible(int n, char from, char to, char aux) {
    if (n == 1)
        return 1;
    if (from == to || from == aux)
        return 0;
    if (to == aux)
        return isPossible(n - 1, from, aux, to);
    return isPossible(n - 1, from, to, aux);
}

/* Function to move n disks from from to to */
void moveDisk(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    moveDisk(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    moveDisk(n - 1, aux, to, from);
}

/* Function to solve the tower of Hanoi problem */
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > N) {
        printf("Invalid number of disks\n");
        return 0;
    }
    char from = 'A', to = 'C', aux = 'B';
    printf("Solving the Tower of Hanoi problem with %d disks\n", n);
    printf("Initial state:\n");
    printTower(n, from, to, aux);
    towerOfHanoi(n, from, to, aux);
    printf("\nFinal state:\n");
    printTower(n, from, to, aux);
    return 0;
}