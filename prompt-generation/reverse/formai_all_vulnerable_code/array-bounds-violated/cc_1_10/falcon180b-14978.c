//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISKS 100

struct disk {
    int size;
    int top;
    int position;
};

void move_disk(struct disk from, struct disk to, struct disk aux) {
    if (from.size > to.size) {
        printf("Cannot move disk %d to disk %d\n", from.size, to.size);
        exit(1);
    }

    if (from.position == to.position) {
        printf("Move disk %d from rod %d to rod %d\n", from.size, from.position, to.position);
    } else if (from.position < to.position) {
        printf("Move disk %d from rod %d to rod %d\n", from.size, from.position, to.position);
        move_disk(from, aux, to);
        printf("Move disk %d from rod %d to rod %d\n", from.size, aux.position, to.position);
        move_disk(aux, to, from);
    } else {
        printf("Move disk %d from rod %d to rod %d\n", from.size, from.position, to.position);
        move_disk(from, aux, to);
        printf("Move disk %d from rod %d to rod %d\n", from.size, aux.position, to.position);
        move_disk(aux, from, to);
    }
}

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    struct disk disks[MAX_DISKS];

    int i;
    for (i = n - 1; i >= 0; i--) {
        disks[i].size = i + 1;
        disks[i].position = from_rod;
    }

    printf("Move %d disks from rod %c to rod %c using rod %c\n", n, from_rod, to_rod, aux_rod);
    move_disk(disks[n - 1], disks[0], disks[n - 1]);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    char from_rod, to_rod, aux_rod;
    printf("Enter the rods (A/B/C): ");
    scanf(" %c %c %c", &from_rod, &to_rod, &aux_rod);

    tower_of_hanoi(n, from_rod, to_rod, aux_rod);

    return 0;
}