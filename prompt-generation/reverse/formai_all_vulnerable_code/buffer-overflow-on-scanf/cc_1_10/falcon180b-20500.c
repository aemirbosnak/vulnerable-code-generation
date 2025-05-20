//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(int n, int a, int b, int c) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == a) {
            printf("A: ");
        } else if (i == b) {
            printf("B: ");
        } else if (i == c) {
            printf("C: ");
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

// Function to check if the move is valid
int is_valid_move(int n, int from, int to) {
    if (from == to || from == -1) {
        return 1;
    }
    if (to == -1) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return 0;
}

// Function to move the disk from one tower to another
void move_disk(int n, int from, int to) {
    printf("Moving disk %d from tower %c to tower %c\n", n, 'A' + from, 'A' + to);
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, int a, int b, int c) {
    if (n == 1) {
        move_disk(n, a, c);
        return;
    }
    hanoi(n - 1, a, c, b);
    move_disk(n, a, c);
    hanoi(n - 1, b, a, c);
}

int main() {
    int n, a = 0, b = 1, c = 2;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DISKS) {
        printf("Invalid number of disks!\n");
        return 1;
    }

    printf("Solving the Tower of Hanoi problem with %d disks...\n", n);
    hanoi(n, a, b, c);

    return 0;
}