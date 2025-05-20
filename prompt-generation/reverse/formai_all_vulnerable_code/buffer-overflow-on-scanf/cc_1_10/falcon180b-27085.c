//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(int num_disks, int from_rod, int to_rod, int aux_rod) {
    int i;
    for (i = num_disks; i >= 1; i--) {
        printf(" ");
    }
    printf("|");
    for (i = 1; i <= num_disks; i++) {
        if (i <= num_disks - from_rod + to_rod) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("|\n");
}

// Function to move n disks from source to destination using aux
void move_disks(int num_disks, int from_rod, int to_rod, int aux_rod) {
    if (num_disks == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return;
    }

    move_disks(num_disks - 1, from_rod, aux_rod, to_rod);

    printf("Move disk %d from rod %d to rod %d\n", num_disks, from_rod, to_rod);

    move_disks(num_disks - 1, aux_rod, to_rod, from_rod);
}

// Function to find the minimum number of moves required to solve the puzzle
int min_moves(int num_disks) {
    return (int) pow(2, num_disks) - 1;
}

// Function to solve the Tower of Hanoi puzzle
void solve_tower_of_hanoi(int num_disks, int from_rod, int to_rod, int aux_rod) {
    int moves = min_moves(num_disks);

    printf("Minimum number of moves required: %d\n", moves);

    move_disks(num_disks, from_rod, to_rod, aux_rod);
}

int main() {
    int num_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    int from_rod = 1;
    int to_rod = 3;
    int aux_rod = 2;

    printf("Initial state:\n");
    print_towers(num_disks, from_rod, to_rod, aux_rod);

    solve_tower_of_hanoi(num_disks, from_rod, to_rod, aux_rod);

    return 0;
}