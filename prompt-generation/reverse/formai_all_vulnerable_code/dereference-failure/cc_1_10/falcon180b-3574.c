//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 20

typedef struct {
    int size;
    char *name;
} Disk;

void init_disks(Disk *disks, int num_disks) {
    for (int i = 0; i < num_disks; i++) {
        disks[i].size = rand() % MAX_DISKS + 1;
        disks[i].name = (char *)malloc(10 * sizeof(char));
        sprintf(disks[i].name, "Disk %d", disks[i].size);
    }
}

void print_disks(Disk *disks, int num_disks) {
    for (int i = 0; i < num_disks; i++) {
        printf("%s (%d)\n", disks[i].name, disks[i].size);
    }
}

void move_disk(Disk *disks, int num_disks, int from, int to) {
    if (from == to) {
        return;
    }

    if (from < to) {
        for (int i = from; i < to; i++) {
            Disk temp = disks[i];
            disks[i] = disks[i - 1];
            disks[i - 1] = temp;
        }
    } else {
        for (int i = from; i > to; i--) {
            Disk temp = disks[i];
            disks[i] = disks[i - 1];
            disks[i - 1] = temp;
        }
    }
}

int main() {
    srand(time(NULL));

    Disk disks[MAX_DISKS];
    int num_disks = rand() % MAX_DISKS + 1;

    init_disks(disks, num_disks);

    printf("Initial state:\n");
    print_disks(disks, num_disks);

    int num_moves = 0;
    while (num_moves < num_disks) {
        int from = rand() % num_disks;
        int to = rand() % num_disks;

        while (from == to) {
            to = rand() % num_disks;
        }

        move_disk(disks, num_disks, from, to);
        num_moves++;

        printf("Move %d: Move disk %d from %s to %s\n", num_moves,
               disks[from].size, disks[from].name, disks[to].name);

        printf("Current state:\n");
        print_disks(disks, num_disks);
    }

    printf("Congratulations! You solved the Tower of Hanoi problem in %d moves.\n", num_moves);

    return 0;
}