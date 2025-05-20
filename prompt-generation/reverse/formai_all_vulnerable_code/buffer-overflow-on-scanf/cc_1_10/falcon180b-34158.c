//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DISKS 10

// Function to print the disks
void print_disks(int disks, int from_rod, int to_rod, int aux_rod) {
    for (int i = disks; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
}

// Function to check if the move is valid
bool is_valid_move(int disks, int from_rod, int to_rod, int aux_rod) {
    if (from_rod == to_rod || from_rod == aux_rod || to_rod == aux_rod) {
        return false;
    }
    if (from_rod == 1 || to_rod == MAX_DISKS) {
        return true;
    }
    return true;
}

// Function to move the disks
void move_disks(int disks, int from_rod, int to_rod, int aux_rod) {
    if (disks == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
    } else {
        move_disks(disks - 1, from_rod, aux_rod, to_rod);
        printf("Move disk %d from rod %d to rod %d\n", disks, from_rod, to_rod);
        move_disks(disks - 1, aux_rod, to_rod, from_rod);
    }
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int disks, int from_rod, int to_rod, int aux_rod) {
    if (disks == 1) {
        move_disks(disks, from_rod, to_rod, aux_rod);
        return;
    }
    tower_of_hanoi(disks - 1, from_rod, aux_rod, to_rod);
    move_disks(disks, from_rod, to_rod, aux_rod);
    tower_of_hanoi(disks - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    if (disks < 1 || disks > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }
    int from_rod = 1, to_rod = 3, aux_rod = 2;
    printf("Solving Tower of Hanoi problem with %d disks...\n", disks);
    print_disks(disks, from_rod, to_rod, aux_rod);
    tower_of_hanoi(disks, from_rod, to_rod, aux_rod);
    printf("\n");
    return 0;
}