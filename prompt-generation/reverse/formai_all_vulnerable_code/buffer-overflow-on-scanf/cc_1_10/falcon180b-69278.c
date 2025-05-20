//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function prototypes
void moveDisk(int n, char from, char to, char aux);
void hanoi(int n, char from, char to, char aux);

int main() {
    int n;

    // Get number of disks from user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Check if number of disks is valid
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    // Call hanoi function to solve the problem
    hanoi(n, 'A', 'C', 'B');

    return 0;
}

// Function to move a disk from one peg to another using a third peg as auxiliary
void moveDisk(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("%c -> %c\n", from, to);
        return;
    }

    // Move n-1 disks from from to aux
    moveDisk(n - 1, from, aux, to);

    // Move the nth disk from from to to
    printf("%c -> %c\n", from, to);

    // Move the n-1 disks from aux to to
    moveDisk(n - 1, aux, to, from);
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char from, char to, char aux) {
    printf("Solving Tower of Hanoi with %d disks...\n", n);

    // Move n disks from from to to using aux as auxiliary
    moveDisk(n, from, to, aux);
}