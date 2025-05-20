//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to print the disks in the tower
void print_tower(int tower[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

// Function to move a disk from one peg to another
void move_disk(int tower[], int from, int to, int n) {
    if (n == 1) {
        printf("Move disk 1 from peg %d to peg %d\n", from, to);
        return;
    }

    int temp_peg = 6 - from - to; // The temporary peg is the opposite of the two pegs

    move_disk(tower, from, temp_peg, n - 1); // Move all disks except the last one to the temporary peg
    printf("Move disk %d from peg %d to peg %d\n", n, from, to);
    move_disk(tower, temp_peg, to, n - 1); // Move all disks from the temporary peg to the final peg
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n) {
    int tower[MAX_SIZE]; // The tower is an array of integers

    // Initialize the tower with n disks
    for (int i = 0; i < n; i++) {
        tower[i] = i + 1;
    }

    printf("Tower of Hanoi problem with %d disks:\n", n);
    print_tower(tower, n);

    // Solve the problem
    move_disk(tower, 0, 2, n);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE) {
        printf("Invalid number of disks\n");
        return 1;
    }

    tower_of_hanoi(n);

    return 0;
}