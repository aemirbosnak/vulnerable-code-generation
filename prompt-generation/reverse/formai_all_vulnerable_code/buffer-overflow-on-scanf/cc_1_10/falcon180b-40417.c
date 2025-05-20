//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 20

// Function to print the current state of the towers
void print_towers(int n, int from_rod, int to_rod, int aux_rod) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from_rod)
            printf("From rod: ");
        else if (i == to_rod)
            printf("To rod: ");
        else if (i == aux_rod)
            printf("Aux rod: ");
        else
            printf("   ");
    }
    printf("\n");
}

// Function to move a disk from one rod to another
void move_disk(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return;
    }

    move_disk(n - 1, from_rod, aux_rod, to_rod);

    printf("Move disk %d from rod %d to rod %d\n", n, from_rod, to_rod);

    move_disk(n - 1, aux_rod, to_rod, from_rod);
}

// Function to solve the Tower of Hanoi problem recursively
void hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        move_disk(n, from_rod, to_rod, aux_rod);
        return;
    }

    hanoi(n - 1, from_rod, aux_rod, to_rod);

    move_disk(n, from_rod, to_rod, aux_rod);

    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n > MAX_DISKS || n < 1) {
        printf("Invalid number of disks\n");
        return 1;
    }

    hanoi(n, 1, 3, 2);

    return 0;
}