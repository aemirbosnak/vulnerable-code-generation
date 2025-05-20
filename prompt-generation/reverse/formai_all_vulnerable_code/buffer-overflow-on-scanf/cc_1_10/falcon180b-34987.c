//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

void print_tower(int tower[MAX_DISKS], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

void move_disk(int tower[MAX_DISKS], int n, int from, int to) {
    int i;
    if (n == 1) {
        tower[to] = tower[0];
        tower[0] = 0;
    } else {
        for (i = n - 1; i >= from; i--) {
            tower[i + 1] = tower[i];
        }
        tower[from] = 0;
        tower[to] = tower[n - 1];
    }
}

void tower_of_hanoi(int n) {
    int tower[MAX_DISKS];
    int from, to;
    int i;

    for (i = n - 1; i >= 0; i--) {
        tower[i] = i + 1;
    }

    from = 0;
    to = 2;
    move_disk(tower, n, from, to);

    for (i = 0; i < n - 1; i++) {
        from = 0;
        to = 2;
        move_disk(tower, n - i - 1, from, to);
        printf("Move disk %d from %d to %d\n", n - i - 1, from, to);
        print_tower(tower, n - i - 1);
        printf("-----------------\n");
    }
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    tower_of_hanoi(n);

    return 0;
}