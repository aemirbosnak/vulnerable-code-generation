//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

struct disk {
    int size;
    int position;
    int top;
};

void print_disks(struct disk disks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Disk %d: size %d, position %d, top %d\n", i + 1, disks[i].size, disks[i].position, disks[i].top);
    }
}

void move_disk(struct disk disks[], int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || from == to) {
        return;
    }

    if (disks[to].size < disks[from].size) {
        for (int i = to; i > from; i--) {
            disks[i].top = i - 1;
        }
    }

    disks[to].position = disks[from].position;
    disks[to].top = disks[from].top;
    disks[from].position = to;
}

void tower_of_hanoi(int n, struct disk disks[]) {
    int from = 0, to = 2 * n - 1, temp;

    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            move_disk(disks, n, from, to);
        }
        move_disk(disks, n, from, 2 * n - 1);
        from = temp;
        to--;
    }
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    struct disk disks[MAX_DISKS];

    for (int i = 0; i < n; i++) {
        disks[i].size = rand() % 100;
        disks[i].position = 0;
        disks[i].top = 2 * n - 1;
    }

    printf("Initial configuration:\n");
    print_disks(disks, n);

    tower_of_hanoi(n, disks);

    printf("\nFinal configuration:\n");
    print_disks(disks, n);

    return 0;
}