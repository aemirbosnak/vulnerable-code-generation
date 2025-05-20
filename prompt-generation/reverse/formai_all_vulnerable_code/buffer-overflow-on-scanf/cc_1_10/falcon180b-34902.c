//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define NUM_DISKS 10
#define STACK_SIZE 100

// Function to print the current state of the towers
void print_towers(int towers[NUM_DISKS], int num_disks) {
    int i;
    for (i = num_disks - 1; i >= 0; i--) {
        printf("%d ", towers[i]);
    }
    printf("\n");
}

// Function to check if a move is legal
int is_legal_move(int from, int to, int num_disks) {
    if (from < 0 || from >= num_disks || to < 0 || to >= num_disks || to == from) {
        return 0;
    }

    if (from == 0 || to == num_disks - 1) {
        return 1;
    }

    if (from == to - 1 || from == to + 1) {
        return 1;
    }

    return 0;
}

// Function to move a disk from one tower to another
void move_disk(int from, int to, int aux, int towers[NUM_DISKS]) {
    int top = towers[from];
    towers[from] = 0;
    towers[to] += top;
}

// Function to solve the Tower of Hanoi problem
void hanoi(int num_disks, int from, int to, int aux, int towers[NUM_DISKS]) {
    if (num_disks == 1) {
        move_disk(from, to, aux, towers);
        return;
    }

    hanoi(num_disks - 1, from, aux, to, towers);
    move_disk(from, to, aux, towers);
    hanoi(num_disks - 1, aux, to, from, towers);
}

// Main function
int main() {
    int towers[NUM_DISKS];
    int num_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks < 1 || num_disks > NUM_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    hanoi(num_disks, 0, NUM_DISKS - 1, 1, towers);

    print_towers(towers, num_disks);

    return 0;
}