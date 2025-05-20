//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    char *name;
} disk_t;

void print_disk(disk_t disk) {
    printf("%d %s\n", disk.num, disk.name);
}

void print_tower(disk_t *disks, int num_disks) {
    for (int i = 0; i < num_disks; i++) {
        print_disk(disks[i]);
    }
}

void move_disk(disk_t *disks, int num_disks, int from, int to) {
    disk_t disk = disks[num_disks - 1];
    disks[num_disks - 1] = disks[from];
    disks[from] = disk;
    print_tower(disks, num_disks);
    printf("\n");
}

void solve_tower_of_hanoi(disk_t *disks, int num_disks, int from, int to, int via) {
    if (num_disks == 1) {
        move_disk(disks, num_disks, from, to);
        return;
    }

    solve_tower_of_hanoi(disks, num_disks - 1, from, via, to);
    move_disk(disks, num_disks, from, to);
    solve_tower_of_hanoi(disks, num_disks - 1, via, to, from);
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    disk_t *disks = malloc(sizeof(disk_t) * num_disks);
    for (int i = 0; i < num_disks; i++) {
        disks[i].num = i + 1;
        disks[i].name = malloc(10);
        sprintf(disks[i].name, "disk%d", i + 1);
    }

    print_tower(disks, num_disks);
    printf("\n");

    solve_tower_of_hanoi(disks, num_disks, 0, 2, 1);

    free(disks);
    return 0;
}