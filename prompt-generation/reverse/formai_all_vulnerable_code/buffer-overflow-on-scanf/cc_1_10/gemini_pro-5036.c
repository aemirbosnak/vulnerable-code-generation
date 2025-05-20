//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#define MAX_DISKS 10

typedef struct {
    int num_disks;
    int *disks;
} tower;

tower *create_tower(int num_disks) {
    tower *t = malloc(sizeof(tower));
    t->num_disks = num_disks;
    t->disks = malloc(sizeof(int) * num_disks);
    for (int i = 0; i < num_disks; i++) {
        t->disks[i] = i + 1;
    }
    return t;
}

void destroy_tower(tower *t) {
    free(t->disks);
    free(t);
}

void print_tower(tower *t) {
    for (int i = 0; i < t->num_disks; i++) {
        printf("%d", t->disks[i]);
        if (i < t->num_disks - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

void move_disk(tower *t1, tower *t2) {
    int disk = t1->disks[t1->num_disks - 1];
    t1->num_disks--;
    t2->num_disks++;
    t2->disks[t2->num_disks - 1] = disk;
}

void tower_of_hanoi(tower *t1, tower *t2, tower *t3, int num_disks) {
    if (num_disks == 1) {
        move_disk(t1, t3);
        return;
    }
    tower_of_hanoi(t1, t3, t2, num_disks - 1);
    move_disk(t1, t3);
    tower_of_hanoi(t2, t1, t3, num_disks - 1);
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    if (num_disks <= 0 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    tower *t1 = create_tower(num_disks);
    tower *t2 = create_tower(0);
    tower *t3 = create_tower(0);
    printf("Initial state:\n");
    print_tower(t1);
    print_tower(t2);
    print_tower(t3);
    tower_of_hanoi(t1, t2, t3, num_disks);
    printf("Final state:\n");
    print_tower(t1);
    print_tower(t2);
    print_tower(t3);
    destroy_tower(t1);
    destroy_tower(t2);
    destroy_tower(t3);
    return 0;
}