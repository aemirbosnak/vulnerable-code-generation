//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

typedef struct {
    int num_disks;
    int src_rod;
    int dest_rod;
    int aux_rod;
} Tower;

void init_tower(Tower* tower, int num_disks, int src_rod, int dest_rod, int aux_rod) {
    tower->num_disks = num_disks;
    tower->src_rod = src_rod;
    tower->dest_rod = dest_rod;
    tower->aux_rod = aux_rod;
}

void print_tower(Tower* tower) {
    int i;
    for (i = tower->num_disks - 1; i >= 0; i--) {
        printf("%d ", i + 1);
    }
    printf("\n");
}

void move_disk(Tower* tower, int num_disks, int src_rod, int dest_rod, int aux_rod) {
    if (num_disks == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", src_rod, dest_rod);
        return;
    }

    move_disk(tower, num_disks - 1, src_rod, aux_rod, dest_rod);

    printf("Move disk %d from rod %d to rod %d\n", num_disks, src_rod, dest_rod);

    move_disk(tower, num_disks - 1, aux_rod, dest_rod, src_rod);
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
    int src_rod = rand() % 3;
    int dest_rod = rand() % 3;
    int aux_rod = (src_rod + dest_rod) % 3;

    Tower tower;
    init_tower(&tower, num_disks, src_rod, dest_rod, aux_rod);

    printf("Initial state:\n");
    print_tower(&tower);

    move_disk(&tower, num_disks, src_rod, dest_rod, aux_rod);

    printf("\nFinal state:\n");
    print_tower(&tower);

    return 0;
}