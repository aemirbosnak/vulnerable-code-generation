//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define MAX_MOVES 100

void move_disk(int from_rod, int to_rod, int num_disks, int *rods) {
    printf("Move disk %d from rod %d to rod %d\n", num_disks, from_rod, to_rod);
    rods[from_rod] -= num_disks;
    rods[to_rod] += num_disks;
}

void print_rods(int num_disks, int *rods) {
    for (int i = 0; i < num_disks; i++) {
        printf("%d ", rods[i]);
    }
    printf("\n");
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    int *rods = malloc(sizeof(int) * num_disks);
    for (int i = 0; i < num_disks; i++) {
        rods[i] = 0;
    }

    int moves = 0;
    int start_rod = 0;
    int end_rod = num_disks - 1;
    int temp_rod = 2 * num_disks - 1;

    srand(time(NULL));
    while (moves < MAX_MOVES) {
        int next_rod = rand() % 3;
        if (next_rod == start_rod)
            next_rod = (next_rod + 1) % 3;
        if (next_rod == end_rod)
            next_rod = (next_rod - 1 + 3) % 3;
        if (next_rod == temp_rod)
            next_rod = (next_rod - 1 + 3) % 3;

        move_disk(start_rod, next_rod, rods[start_rod], rods);
        start_rod = next_rod;
        moves++;
    }

    printf("The puzzle is solved in %d moves.\n", moves);
    print_rods(num_disks, rods);
    free(rods);
    return 0;
}