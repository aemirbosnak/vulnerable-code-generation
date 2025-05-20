//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(int n, char tower_from, char tower_to, char tower_aux) {
    int i;

    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("Move disk %d from tower %c to tower %c\n", n - 1, tower_from, tower_to);
        else
            printf("Move disk %d from tower %c to tower %c\n", n - 1 - i, tower_from, tower_to);
    }
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || from == to)
        return 0;

    return 1;
}

// Function to solve the Tower of Hanoi problem recursively
void tower_of_hanoi(int n, char tower_from, char tower_to, char tower_aux) {
    if (n == 1) {
        printf("Move disk %d from tower %c to tower %c\n", 1, tower_from, tower_to);
        return;
    }

    tower_of_hanoi(n - 1, tower_from, tower_aux, tower_to);

    printf("Move disk %d from tower %c to tower %c\n", n - 1, tower_from, tower_to);

    tower_of_hanoi(n - 1, tower_aux, tower_to, tower_from);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}