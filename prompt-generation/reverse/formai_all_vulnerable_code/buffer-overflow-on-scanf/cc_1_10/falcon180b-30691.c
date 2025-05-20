//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int from_rod, int to_rod, int aux_rod, char *message) {
    printf("%s\n", message);
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
    printf(" |");
    for (int i = n - 1; i >= 0; i--) {
        if (i == from_rod) {
            printf(" ");
        } else if (i == to_rod) {
            printf("X");
        } else if (i == aux_rod) {
            printf("A");
        } else {
            printf("O");
        }
        printf(" |");
    }
    printf("\n");
}

// Function to move n disks from from_rod to to_rod, using aux_rod as auxiliary
void move_disks(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return;
    }
    move_disks(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %d to rod %d\n", n, from_rod, to_rod);
    move_disks(n - 1, aux_rod, to_rod, from_rod);
}

// Function to solve the Tower of Hanoi problem for n disks
void tower_of_hanoi(int n) {
    int from_rod = 0, to_rod = 2, aux_rod = 1;
    printf("Solving Tower of Hanoi problem for %d disks:\n", n);
    for (int i = n; i >= 1; i--) {
        move_disks(i, from_rod, to_rod, aux_rod);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    tower_of_hanoi(n);
    return 0;
}