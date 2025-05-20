//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct _disk {
    int size;
    struct _disk *next;
} disk;

typedef struct _tower {
    disk *top;
    int num_disks;
} tower;

void print_tower(tower *t) {
    disk *d = t->top;
    printf("Tower %d: ", t->num_disks);
    while (d != NULL) {
        printf("%d ", d->size);
        d = d->next;
    }
    printf("\n");
}

void move_disk(tower *from, tower *to) {
    disk *d = from->top;
    from->top = d->next;
    d->next = to->top;
    to->top = d;
    from->num_disks--;
    to->num_disks++;
}

void solve_tower_of_hanoi(int n, tower *from, tower *to, tower *aux) {
    if (n == 1) {
        move_disk(from, to);
    } else {
        solve_tower_of_hanoi(n - 1, from, aux, to);
        move_disk(from, to);
        solve_tower_of_hanoi(n - 1, aux, to, from);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    tower *towers = malloc(sizeof(tower) * 3);
    towers[0].num_disks = n;
    towers[1].num_disks = 0;
    towers[2].num_disks = 0;

    int i;
    for (i = n; i >= 1; i--) {
        disk *d = malloc(sizeof(disk));
        d->size = i;
        d->next = towers[0].top;
        towers[0].top = d;
    }

    print_tower(&towers[0]);
    print_tower(&towers[1]);
    print_tower(&towers[2]);

    solve_tower_of_hanoi(n, &towers[0], &towers[1], &towers[2]);

    print_tower(&towers[0]);
    print_tower(&towers[1]);
    print_tower(&towers[2]);

    return 0;
}