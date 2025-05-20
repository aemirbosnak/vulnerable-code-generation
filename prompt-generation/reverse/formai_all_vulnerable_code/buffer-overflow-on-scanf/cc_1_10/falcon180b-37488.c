//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function prototypes
void towerOfHanoi(int n, char from, char to, char aux);
void printTower(int height, int disks, char from, char to, char aux);

int main() {
    int n, i;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        exit(1);
    }

    printf("Tower of Hanoi with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}

// Recursive function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

// Function to print the current state of the towers
void printTower(int height, int disks, char from, char to, char aux) {
    printf("\n");
    for (int i = height; i > 0; i--) {
        printf("  ");
    }
    printf(" %c\n", from);
    for (int i = 1; i <= disks; i++) {
        printf("  ");
    }
    printf(" %c\n", to);
    for (int i = 1; i <= height; i++) {
        printf("  ");
    }
    printf(" %c\n", aux);
}