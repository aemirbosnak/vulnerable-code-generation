//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

typedef struct {
    int num_disks;
    char from_rod;
    char to_rod;
    char aux_rod;
} Move;

void print_disks(int num_disks, char rod) {
    for (int i = num_disks; i > 0; i--) {
        printf(" ");
    }
    printf(" %c ", rod);
}

void move_disk(int num_disks, char from_rod, char to_rod, char aux_rod) {
    if (num_disks == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }

    Move move = { num_disks - 1, from_rod, aux_rod, to_rod };
    move_disk(num_disks - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", num_disks, from_rod, to_rod);
    move_disk(num_disks - 1, aux_rod, to_rod, from_rod);
}

void solve_tower_of_hanoi(int num_disks, char from_rod, char to_rod, char aux_rod) {
    move_disk(num_disks, from_rod, to_rod, aux_rod);
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    srand(time(NULL));
    int from_rod = rand() % 3;
    int to_rod = rand() % 3;
    int aux_rod = (from_rod + to_rod) % 3;

    char rods[] = { 'A', 'B', 'C' };
    printf("The initial state:\n");
    for (int i = num_disks; i >= 1; i--) {
        print_disks(i, rods[from_rod]);
        printf("\n");
    }

    solve_tower_of_hanoi(num_disks, from_rod, to_rod, aux_rod);

    printf("\nThe final state:\n");
    for (int i = num_disks; i >= 1; i--) {
        print_disks(i, rods[to_rod]);
        printf("\n");
    }

    return 0;
}