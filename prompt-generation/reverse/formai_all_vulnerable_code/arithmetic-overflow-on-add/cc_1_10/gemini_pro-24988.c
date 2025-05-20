//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define TOWER_COUNT 3
#define DISK_COUNT 5

typedef struct {
    int disk_count;
    int *disks;
} tower_t;

void print_tower(tower_t *tower) {
    for (int i = 0; i < tower->disk_count; i++) {
        printf("%d ", tower->disks[i]);
    }

    printf("\n");
}

void move_disk(tower_t *source, tower_t *destination) {
    int disk = source->disks[source->disk_count - 1];
    source->disk_count--;
    destination->disk_count++;
    destination->disks[destination->disk_count - 1] = disk;
}

int can_move_disk(tower_t *source, tower_t *destination) {
    if (source->disk_count == 0) {
        return 0;
    }

    if (destination->disk_count == 0) {
        return 1;
    }

    return source->disks[source->disk_count - 1] < destination->disks[destination->disk_count - 1];
}

int solve_tower_of_hanoi(tower_t *towers, int disk_count) {
    int moves = 0;

    while (towers[2].disk_count != disk_count) {
        for (int i = 0; i < TOWER_COUNT - 1; i++) {
            for (int j = i + 1; j < TOWER_COUNT; j++) {
                if (can_move_disk(&towers[i], &towers[j])) {
                    move_disk(&towers[i], &towers[j]);
                    moves++;
                }
            }
        }
    }

    return moves;
}

int main() {
    tower_t towers[TOWER_COUNT];
    int disk_counts[TOWER_COUNT];
    int disk_values[DISK_COUNT];

    for (int i = 0; i < TOWER_COUNT; i++) {
        disk_counts[i] = 0;
        towers[i].disks = malloc(sizeof(int) * DISK_COUNT);
    }

    for (int i = 0; i < DISK_COUNT; i++) {
        disk_values[i] = i + 1;
    }

    for (int i = 0; i < DISK_COUNT; i++) {
        towers[0].disks[disk_counts[0]++] = disk_values[i];
    }

    int moves = solve_tower_of_hanoi(towers, DISK_COUNT);

    printf("Solved Tower of Hanoi in %d moves:\n", moves);
    for (int i = 0; i < TOWER_COUNT; i++) {
        printf("Tower %d: ", i + 1);
        print_tower(&towers[i]);
    }

    return 0;
}