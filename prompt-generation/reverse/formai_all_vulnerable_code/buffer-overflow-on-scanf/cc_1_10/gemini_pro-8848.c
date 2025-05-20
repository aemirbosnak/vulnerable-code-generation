//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct tower_t {
    int *disks;
    int num_disks;
} tower;

void init_tower(tower *t, int num_disks) {
    t->disks = malloc(sizeof(int) * num_disks);
    t->num_disks = num_disks;
    for (int i = 0; i < num_disks; i++) {
        t->disks[i] = num_disks - i;
    }
}

void print_tower(tower *t) {
    for (int i = t->num_disks - 1; i >= 0; i--) {
        printf("%d ", t->disks[i]);
    }
    printf("\n");
}

void move_disk(tower *from, tower *to) {
    int disk = from->disks[from->num_disks - 1];
    from->num_disks--;
    to->disks[to->num_disks++] = disk;
}

void solve_tower(tower *from, tower *to, tower *aux, int num_disks) {
    if (num_disks == 1) {
        move_disk(from, to);
    } else {
        solve_tower(from, aux, to, num_disks - 1);
        move_disk(from, to);
        solve_tower(aux, to, from, num_disks - 1);
    }
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    tower t1, t2, t3;
    init_tower(&t1, num_disks);
    init_tower(&t2, 0);
    init_tower(&t3, 0);

    printf("Initial state:\n");
    print_tower(&t1);
    print_tower(&t2);
    print_tower(&t3);

    solve_tower(&t1, &t2, &t3, num_disks);

    printf("Final state:\n");
    print_tower(&t1);
    print_tower(&t2);
    print_tower(&t3);

    return 0;
}