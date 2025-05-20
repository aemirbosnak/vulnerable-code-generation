//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

struct tower {
    int ndisks;
    int disks[MAX_DISKS];
};

void display_tower(struct tower *tower) {
    int i;
    for (i = tower->ndisks - 1; i >= 0; i--) {
        printf("%d ", tower->disks[i]);
    }
    printf("\n");
}

void push_disk(struct tower *tower, int disk) {
    if (tower->ndisks == MAX_DISKS) {
        printf("Error: Tower is full\n");
        return;
    }
    tower->disks[tower->ndisks++] = disk;
}

void pop_disk(struct tower *tower) {
    if (tower->ndisks == 0) {
        printf("Error: Tower is empty\n");
        return;
    }
    tower->ndisks--;
}

void move_disk(struct tower *from, struct tower *to, int n) {
    if (n == 0) {
        pop_disk(from);
        push_disk(to, from->disks[from->ndisks - 1]);
        pop_disk(from);
    } else {
        move_disk(from, to, n - 1);
        push_disk(to, from->disks[from->ndisks - 1]);
        pop_disk(from);
    }
}

int main() {
    struct tower from, to, aux;
    int ndisks, disk;

    printf("Enter the number of disks: ");
    scanf("%d", &ndisks);

    printf("Enter the disks (space separated): ");
    while (ndisks > 0) {
        scanf("%d", &disk);
        push_disk(&from, disk);
        ndisks--;
    }

    printf("Initial tower:\n");
    display_tower(&from);

    printf("Enter the number of disks to move: ");
    scanf("%d", &ndisks);

    move_disk(&from, &to, ndisks);

    printf("Final tower:\n");
    display_tower(&to);

    return 0;
}