//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct Tower {
    char name;
    int num_disks;
    int *disks;
} Tower;

void move_disk(Tower *from, Tower *to) {
    if (from->num_disks == 0) {
        fprintf(stderr, "Error: cannot move disk from empty tower %c\n", from->name);
        exit(1);
    }
    if (to->num_disks != 0 && from->disks[from->num_disks - 1] > to->disks[to->num_disks - 1]) {
        fprintf(stderr, "Error: cannot move larger disk onto smaller disk\n");
        exit(1);
    }
    to->disks[to->num_disks++] = from->disks[--from->num_disks];
    printf("Moved disk %d from tower %c to tower %c\n", to->disks[to->num_disks - 1], from->name, to->name);
}

void move_tower(Tower *from, Tower *to, Tower *aux, int n) {
    if (n == 1) {
        move_disk(from, to);
        return;
    }
    move_tower(from, aux, to, n - 1);
    move_disk(from, to);
    move_tower(aux, to, from, n - 1);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Tower towers[3] = {
        {'A', 0, NULL},
        {'B', 0, NULL},
        {'C', 0, NULL}
    };

    towers[0].num_disks = n;
    towers[0].disks = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        towers[0].disks[i] = n - i;
    }

    move_tower(&towers[0], &towers[2], &towers[1], n);

    return 0;
}