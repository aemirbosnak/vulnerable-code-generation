//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the disks on a rod
void print_disks(int rod, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", rod + i);
    }
    printf("\n");
}

// Function to move a disk from one rod to another
void move_disk(int from, int to, int aux, int n) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from, to);
        return;
    }

    move_disk(from, aux, to, n - 1);

    printf("Move disk %d from rod %d to rod %d\n", n, from, to);

    move_disk(to, aux, from, n - 1);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from, to);
        return;
    }

    tower_of_hanoi(n - 1, from, aux, to);

    printf("Move disk %d from rod %d to rod %d\n", n, from, to);

    tower_of_hanoi(n - 1, aux, to, from);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    printf("Initial state:\n");
    print_disks(1, n);

    printf("\nSolving the Tower of Hanoi problem...\n");
    tower_of_hanoi(n, 1, 3, 2);

    printf("\nFinal state:\n");
    print_disks(3, n);

    return 0;
}