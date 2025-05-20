//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10
#define MIN_DISKS 3

// Function to print the current state of the towers
void print_towers(int n, int from_rod, int to_rod, int aux_rod) {
    int i;
    for (i = 0; i < n; ++i) {
        printf(" ");
    }
    printf("->");
    for (i = 0; i < n; ++i) {
        printf(" ");
    }
    printf("\n");
    while (n > 0) {
        if (n == from_rod) {
            printf("   ");
        } else if (n == to_rod) {
            printf("X  ");
        } else {
            printf("   ");
        }
        --n;
    }
    printf("\n");
}

// Function to move n disks from from_rod to to_rod using aux_rod as auxiliary
void tower_of_hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    if (n > 0) {
        tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
        printf("Move disk %d from rod %d to rod %d\n", n, from_rod, to_rod);
        print_towers(n, from_rod, to_rod, aux_rod);
        tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
    }
}

// Function to solve the Tower of Hanoi problem for n disks
void solve_tower_of_hanoi(int n) {
    int i;
    for (i = MIN_DISKS; i <= MAX_DISKS; ++i) {
        if (i == n) {
            tower_of_hanoi(n, 1, 3, 2);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < MIN_DISKS || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    solve_tower_of_hanoi(n);
    return 0;
}