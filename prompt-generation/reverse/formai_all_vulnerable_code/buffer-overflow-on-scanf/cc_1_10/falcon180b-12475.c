//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void print_disks(int num_disks, int from_rod, int to_rod, int aux_rod) {
    int i;
    for (i = num_disks - 1; i >= 0; i--) {
        if (i == from_rod) {
            printf("F");
        } else if (i == to_rod) {
            printf("T");
        } else if (i == aux_rod) {
            printf("A");
        } else {
            printf("-");
        }
        printf(" ");
    }
    printf("\n");
}

void move_disk(int num_disks, int from_rod, int to_rod, int aux_rod) {
    if (num_disks == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return;
    }
    move_disk(num_disks - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %d to rod %d\n", num_disks, from_rod, to_rod);
    move_disk(num_disks - 1, aux_rod, to_rod, from_rod);
}

void tower_of_hanoi(int num_disks) {
    int from_rod = 1, to_rod = 3, aux_rod = 2;
    printf("Tower of Hanoi with %d disks\n", num_disks);
    srand(time(NULL));
    int moves = rand() % (2 * num_disks - 1) + 1;
    printf("Minimum number of moves: %d\n", moves);
    printf("Starting configuration:\n");
    print_disks(num_disks, from_rod, to_rod, aux_rod);
    move_disk(num_disks, from_rod, to_rod, aux_rod);
    printf("Final configuration:\n");
    print_disks(num_disks, from_rod, to_rod, aux_rod);
}

int main() {
    int num_disks;
    printf("Enter the number of disks (1 to %d): ", MAX_DISKS);
    scanf("%d", &num_disks);
    tower_of_hanoi(num_disks);
    return 0;
}