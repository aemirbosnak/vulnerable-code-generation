//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

typedef struct {
    int num_disks;
    int* disk_sizes;
} Tower;

Tower* create_tower(int num_disks, int* disk_sizes) {
    Tower* tower = (Tower*)malloc(sizeof(Tower));
    tower->num_disks = num_disks;
    tower->disk_sizes = disk_sizes;
    return tower;
}

void destroy_tower(Tower* tower) {
    free(tower->disk_sizes);
    free(tower);
}

void print_tower(Tower* tower) {
    printf("Tower of Hanoi with %d disks:\n", tower->num_disks);
    for (int i = 0; i < tower->num_disks; i++) {
        printf("%d ", tower->disk_sizes[i]);
    }
    printf("\n");
}

void move_disk(Tower* tower, int from, int to, int aux) {
    if (from == to) {
        return;
    } else if (from > to) {
        move_disk(tower, from - 1, aux, to);
    } else {
        move_disk(tower, from, aux, to - 1);
    }
}

void hanoi(Tower* tower, int num_moves, int from, int to, int aux) {
    if (num_moves == 1) {
        move_disk(tower, from, to, aux);
        printf("Move disk %d from rod %d to rod %d\n", tower->disk_sizes[from], from, to);
        return;
    }

    int num_disks = tower->num_disks;
    int rod_sizes[MAX_DISKS];

    for (int i = 0; i < num_disks; i++) {
        if (i < from || i > to) {
            rod_sizes[i] = tower->disk_sizes[i];
        }
    }

    hanoi(tower, num_moves - 1, from, aux, to);

    move_disk(tower, from, to, aux);

    hanoi(tower, num_moves - 1, aux, to, from);
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    int* disk_sizes = (int*)malloc(sizeof(int) * num_disks);
    printf("Enter the sizes of the disks (in descending order):\n");
    for (int i = 0; i < num_disks; i++) {
        scanf("%d", &disk_sizes[i]);
    }

    Tower* tower = create_tower(num_disks, disk_sizes);
    print_tower(tower);

    int num_moves;
    printf("Enter the number of moves to solve the puzzle: ");
    scanf("%d", &num_moves);

    srand(time(NULL));
    int from = rand() % num_disks;
    int to = rand() % num_disks;
    int aux = rand() % num_disks;

    printf("Solving the puzzle with %d moves...\n", num_moves);
    hanoi(tower, num_moves, from, to, aux);

    destroy_tower(tower);

    return 0;
}