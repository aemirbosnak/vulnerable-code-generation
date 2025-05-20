//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int size;
    int *disks;
} Tower;

void print_tower(Tower *tower) {
    for (int i = 0; i < tower->size; i++) {
        printf("%d ", tower->disks[i]);
    }
    printf("\n");
}

void move_disk(Tower *from, Tower *to) {
    int disk = from->disks[from->size - 1];
    from->size--;
    to->disks[to->size++] = disk;
}

void tower_of_hanoi(Tower *towers, int n, Tower *from, Tower *to, Tower *aux) {
    if (n == 1) {
        move_disk(from, to);
        return;
    }

    tower_of_hanoi(towers, n - 1, from, aux, to);
    move_disk(from, to);
    tower_of_hanoi(towers, n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid number of disks. Must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    Tower towers[3];
    for (int i = 0; i < 3; i++) {
        towers[i].size = 0;
        towers[i].disks = malloc(MAX_SIZE * sizeof(int));
    }

    for (int i = n; i >= 1; i--) {
        towers[0].disks[towers[0].size++] = i;
    }

    tower_of_hanoi(towers, n, &towers[0], &towers[1], &towers[2]);

    printf("Final state of towers:\n");
    for (int i = 0; i < 3; i++) {
        printf("Tower %d: ", i + 1);
        print_tower(&towers[i]);
    }

    for (int i = 0; i < 3; i++) {
        free(towers[i].disks);
    }

    return 0;
}