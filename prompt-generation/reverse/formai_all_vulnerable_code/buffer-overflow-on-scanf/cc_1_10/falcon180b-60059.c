//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the towers
void printTowers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", from);
        from += 'A' - 'a';
    }
    printf(" -> ");
    for (i = 0; i < n; i++) {
        printf("%c ", to);
        to += 'A' - 'a';
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%c ", aux);
        aux += 'A' - 'a';
    }
    printf("\n");
}

// Function to check if a move is valid
int isValid(int n, char from, char to, char aux) {
    if (from == to || from == aux || to == aux) {
        return 0;
    }
    if (from < to) {
        int i;
        for (i = from + 1; i < to; i++) {
            if (i == aux) {
                return 0;
            }
        }
    } else {
        int i;
        for (i = from - 1; i > to; i--) {
            if (i == aux) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to move the disks
void moveDisk(int n, char from, char to, char aux) {
    printf("Move disk %d from %c to %c\n", n, from, to);
    printTowers(n, from, to, aux);
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        moveDisk(1, from, to, aux);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    moveDisk(n, from, to, aux);
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Invalid number of disks\n");
        return 1;
    }
    printf("Solving the Tower of Hanoi problem with %d disks...\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}