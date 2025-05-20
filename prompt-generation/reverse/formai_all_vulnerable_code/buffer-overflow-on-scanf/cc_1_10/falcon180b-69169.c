//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function prototypes
void move_tower(int n, char from_rod, char to_rod, char aux_rod);
void print_tower(int n, char rod);

// Main function
int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    printf("Solving Tower of Hanoi problem with %d disks...\n", n);
    move_tower(n, 'A', 'C', 'B');

    printf("\nTower of Hanoi solved!\n");
    return 0;
}

// Move n disks from from_rod to to_rod, using aux_rod as auxiliary
void move_tower(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }

    move_tower(n - 1, from_rod, aux_rod, to_rod);

    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);

    move_tower(n - 1, aux_rod, to_rod, from_rod);
}

// Print the current state of the tower
void print_tower(int n, char rod) {
    int i;

    for (i = n; i >= 1; i--) {
        printf("Disk %d is on rod %c\n", i, rod);
    }
}