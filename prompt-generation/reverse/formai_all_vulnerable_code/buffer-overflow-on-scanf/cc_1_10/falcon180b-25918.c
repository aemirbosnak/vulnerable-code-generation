//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(int n, char tower_from, char tower_to, char tower_aux) {
    int i;

    printf("\n");
    for (i = n; i >= 1; i--) {
        printf("  ");
    }
    printf("Move disk %d from %c to %c\n", n, tower_from, tower_to);
    printf("  ");
    for (i = 1; i <= n; i++) {
        if (i!= n) {
            printf(" %c ", 'A' + i - 1);
        } else {
            printf("->%c", tower_to);
        }
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to, int aux) {
    // The disk can only be moved if it is on top of a larger disk or an empty tower
    if (from == to) {
        return 0;
    } else if (from == aux) {
        return 0;
    } else if (to == aux) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return 1;
    }
}

// Function to move n disks from tower_from to tower_to using tower_aux as an auxiliary tower
void move_disks(int n, char tower_from, char tower_to, char tower_aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", tower_from, tower_to);
        return;
    }

    move_disks(n - 1, tower_from, tower_aux, tower_to);

    printf("Move disk %d from %c to %c\n", n, tower_from, tower_to);

    move_disks(n - 1, tower_aux, tower_to, tower_from);
}

// Function to solve the Tower of Hanoi problem with n disks
void hanoi(int n, char tower_from, char tower_to, char tower_aux) {
    int i;

    for (i = n; i >= 1; i--) {
        move_disks(i, tower_from, tower_to, tower_aux);
        print_towers(i, tower_from, tower_to, tower_aux);
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    hanoi(n, 'A', 'C', 'B');

    return 0;
}