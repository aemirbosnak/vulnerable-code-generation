//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the tower of Hanoi
void printTower(int n, int from, int to, int aux) {
    int i;
    for (i = n; i >= 1; i--) {
        if (i!= from && i!= to && i!= aux) {
            printf(" ");
        } else {
            printf("*");
        }
    }
    printf("\n");
}

// Function to move the tower of Hanoi
void moveTower(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", from, to);
        return;
    }
    moveTower(n - 1, from, aux, to);
    printf("Move disk %d from %d to %d\n", n, from, to);
    moveTower(n - 1, aux, to, from);
}

// Function to solve the tower of Hanoi problem
void solveTower(int n, int from, int to, int aux) {
    if (n > 0) {
        moveTower(n, from, to, aux);
        printf("Tower of Hanoi with %d disks:\n", n);
        printTower(n, from, to, aux);
    }
}

// Function to generate a random number
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Main function
int main() {
    int n, from, to, aux;
    srand(time(NULL));
    n = randInt(1, 10);
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The tower of Hanoi with %d disks:\n", n);
    from = 1;
    to = 3;
    aux = 2;
    solveTower(n, from, to, aux);
    return 0;
}