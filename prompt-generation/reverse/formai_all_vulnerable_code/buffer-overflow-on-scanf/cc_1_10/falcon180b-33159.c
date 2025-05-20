//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    printf("\n");
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("Move disk %d from %c to %c\n", n, from, to);
    printf("Current state:\n");
    if (n == 1) {
        printf(" %c ", from);
    } else {
        printf(" %c ", from);
        for (i = 1; i < n; i++) {
            printf(" %c ", to);
        }
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int n, char from, char to) {
    if (n <= 0 || from < 'A' || from > 'C' || to < 'A' || to > 'C' || to == from) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
    } else {
        move_disk(n - 1, from, aux, to);
        printf("Move disk %d from %c to %c\n", n, from, to);
        move_disk(n - 1, aux, to, from);
    }
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        move_disk(n, from, to, aux);
    } else {
        tower_of_hanoi(n - 1, from, aux, to);
        move_disk(n, from, to, aux);
        tower_of_hanoi(n - 1, aux, to, from);
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Solving the Tower of Hanoi problem with %d disks:\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}