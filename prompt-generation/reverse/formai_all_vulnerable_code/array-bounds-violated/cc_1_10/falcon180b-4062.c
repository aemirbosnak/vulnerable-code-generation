//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100
#define TOWER_SIZE 3

int towers[TOWER_SIZE];
int num_disks;
int moves = 0;

void init_tower(int num_disks) {
    int i;

    for (i = num_disks - 1; i >= 0; i--) {
        towers[TOWER_SIZE - 1 - i] = i;
    }
}

void print_tower(int tower_size) {
    int i;

    for (i = 0; i < tower_size; i++) {
        printf("%d ", towers[i]);
    }
    printf("\n");
}

int is_valid_move(int from, int to) {
    int i;

    if (from < 0 || from >= TOWER_SIZE || to < 0 || to >= TOWER_SIZE || from == to) {
        return 0;
    }

    for (i = from + 1; i <= to - 1; i++) {
        if (towers[i]!= -1) {
            return 0;
        }
    }

    return 1;
}

int move_disk(int from, int to) {
    int i;

    if (!is_valid_move(from, to)) {
        return 0;
    }

    towers[to] = towers[from];
    towers[from] = -1;

    moves++;

    return 1;
}

int main() {
    int num_disks;
    int i;

    srand(time(NULL));
    num_disks = rand() % MAX_DISKS + 1;

    printf("Number of disks: %d\n", num_disks);

    init_tower(num_disks);
    print_tower(TOWER_SIZE);

    printf("Moves: %d\n", moves);

    return 0;
}