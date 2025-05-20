//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the disks
void print_disks(int n, char from_rod, char to_rod, char aux_rod) {
    int i;
    for (i = n; i >= 1; i--) {
        printf(" ");
    }
    printf("|%c ", from_rod);
    for (i = 1; i <= n; i++) {
        printf(" ");
    }
    printf("|%c ", to_rod);
    for (i = 1; i <= n; i++) {
        printf(" ");
    }
    printf("|%c ", aux_rod);
    printf("\n");
}

// Function to move a disk from one rod to another
void move_disk(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }
    move_disk(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    move_disk(n - 1, aux_rod, to_rod, from_rod);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        move_disk(n, from_rod, to_rod, aux_rod);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Solved Tower of Hanoi with %d disks\n", n);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("Solving Tower of Hanoi with %d disks\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}