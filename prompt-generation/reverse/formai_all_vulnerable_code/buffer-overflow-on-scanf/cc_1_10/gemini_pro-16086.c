//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOWERS 3
#define MAX_DISKS 10

typedef struct {
    int num_disks;
    int disks[MAX_DISKS];
} tower;

void print_towers(tower towers[MAX_TOWERS]) {
    for (int i = 0; i < MAX_TOWERS; i++) {
        printf("Tower %d: ", i + 1);
        for (int j = 0; j < towers[i].num_disks; j++) {
            printf("%d ", towers[i].disks[j]);
        }
        printf("\n");
    }
}

void move_disk(tower *from, tower *to) {
    if (from->num_disks > 0) {
        to->disks[to->num_disks++] = from->disks[--from->num_disks];
    }
}

void tower_of_hanoi(tower towers[MAX_TOWERS], int num_disks, int from, int to, int via) {
    if (num_disks > 0) {
        tower_of_hanoi(towers, num_disks - 1, from, via, to);
        move_disk(&towers[from], &towers[to]);
        tower_of_hanoi(towers, num_disks - 1, via, to, from);
    }
}

int main() {
    tower towers[MAX_TOWERS] = {{0}, {0}, {0}};

    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    for (int i = 0; i < num_disks; i++) {
        towers[0].disks[i] = num_disks - i;
        towers[0].num_disks++;
    }

    print_towers(towers);

    tower_of_hanoi(towers, num_disks, 0, 2, 1);

    print_towers(towers);

    return 0;
}