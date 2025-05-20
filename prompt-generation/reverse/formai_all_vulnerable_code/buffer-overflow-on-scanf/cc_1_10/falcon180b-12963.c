//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

typedef struct {
    int num_disks;
    int from_rod;
    int to_rod;
    int aux_rod;
} Move;

void print_disks(int num_disks, int rod) {
    int i;
    for (i = num_disks; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
}

void move_disk(int num_disks, int from_rod, int to_rod, int aux_rod) {
    if (num_disks == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return;
    }

    Move m = {num_disks - 1, from_rod, aux_rod, to_rod};
    move_disk(num_disks - 1, from_rod, aux_rod, to_rod);
    m.num_disks = 1;
    m.from_rod = to_rod;
    m.to_rod = from_rod;
    m.aux_rod = aux_rod;
    move_disk(1, to_rod, from_rod, aux_rod);
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

    srand(time(NULL));
    int choice = rand() % 2;

    if (choice == 0) {
        printf("Solving the Tower of Hanoi problem with %d disks...\n", num_disks);
        move_disk(num_disks, from_rod, to_rod, aux_rod);
    } else {
        printf("Shuffling the disks...\n");
        int i;
        for (i = 1; i <= num_disks; i++) {
            int j = rand() % num_disks + 1;
            while (j == i) {
                j = rand() % num_disks + 1;
            }
            Move m = {i, i, j, j};
            move_disk(i, i, j, j);
        }
    }

    return 0;
}