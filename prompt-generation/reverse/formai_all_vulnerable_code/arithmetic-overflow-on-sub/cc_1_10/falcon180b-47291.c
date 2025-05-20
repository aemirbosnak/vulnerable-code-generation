//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, char from_rod, char to_rod, char aux_rod) {
    int i;
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf(" -> ");
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("\n");
}

// Function to check if the move is valid
int is_valid_move(int n, int from_rod, int to_rod, int aux_rod) {
    if (from_rod == to_rod) {
        return 0;
    }
    if (from_rod == aux_rod || to_rod == aux_rod) {
        return 0;
    }
    return 1;
}

// Function to move the disks from one rod to another
void move_disks(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
    } else {
        move_disks(n - 1, from_rod, aux_rod, to_rod);
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        move_disks(n - 1, aux_rod, to_rod, from_rod);
    }
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        print_towers(1, from_rod, to_rod, aux_rod);
        move_disks(1, from_rod, to_rod, aux_rod);
    } else {
        tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
        print_towers(n, from_rod, to_rod, aux_rod);
        move_disks(n, from_rod, to_rod, aux_rod);
        tower_of_hanoi(n - 1, to_rod, aux_rod, from_rod);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n > MAX_DISKS) {
        printf("The number of disks should not exceed %d\n", MAX_DISKS);
        return 1;
    }
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}