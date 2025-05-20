//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DISKS 100

typedef struct {
    int disks;
    int* towers;
} Tower;

Tower* create_towers(int disks) {
    Tower* towers = malloc(sizeof(Tower));
    towers->disks = disks;
    towers->towers = malloc(sizeof(int) * disks);
    for (int i = 0; i < disks; i++) {
        towers->towers[i] = -1;
    }
    return towers;
}

void move_disk(Tower* towers, int from, int to) {
    if (from == to) {
        return;
    }
    if (from < to) {
        move_disk(towers, from, to - 1);
        towers->towers[to] = from;
    } else {
        move_disk(towers, from, to + 1);
        towers->towers[to] = from;
    }
}

void print_towers(Tower* towers) {
    for (int i = 0; i < towers->disks; i++) {
        if (towers->towers[i]!= -1) {
            printf("%d -> Tower %d\n", i, towers->towers[i]);
        }
    }
}

int main() {
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);

    Tower* towers = create_towers(disks);
    move_disk(towers, 0, 2);
    print_towers(towers);

    free(towers->towers);
    free(towers);
    return 0;
}