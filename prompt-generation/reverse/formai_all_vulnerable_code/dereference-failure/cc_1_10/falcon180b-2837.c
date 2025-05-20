//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

typedef struct {
    int num_disks;
    int* disks;
} Tower;

void create_tower(Tower* tower, int num_disks) {
    tower->num_disks = num_disks;
    tower->disks = (int*)malloc(num_disks * sizeof(int));
    for (int i = 0; i < num_disks; i++) {
        tower->disks[i] = i + 1;
    }
}

void destroy_tower(Tower* tower) {
    free(tower->disks);
}

void display_tower(Tower* tower) {
    for (int i = 0; i < tower->num_disks; i++) {
        printf("%d ", tower->disks[i]);
    }
    printf("\n");
}

void move_disk(Tower* from, Tower* to, int num_disks) {
    if (num_disks == 1) {
        from->disks[0] = 0;
        to->disks[to->num_disks - 1] = from->disks[0];
        from->disks[0] = 0;
    } else {
        move_disk(from, to->disks[to->num_disks - 1], num_disks - 1);
        to->disks[to->num_disks - 1] = from->disks[0];
        from->disks[0] = 0;
    }
}

int main() {
    srand(time(NULL));
    int num_disks = rand() % MAX_DISKS + 1;
    Tower source, target, temp;
    create_tower(&source, num_disks);
    create_tower(&target, 0);
    create_tower(&temp, 0);

    printf("Initial state:\n");
    display_tower(&source);
    printf("Final state should be:\n");
    display_tower(&target);

    int steps = 0;
    while (source.num_disks > 0) {
        int disk = source.disks[0];
        move_disk(&source, &target, disk);
        display_tower(&source);
        display_tower(&target);
        steps++;
    }

    printf("Total number of steps: %d\n", steps);

    destroy_tower(&source);
    destroy_tower(&target);
    destroy_tower(&temp);

    return 0;
}