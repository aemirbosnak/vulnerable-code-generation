//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void move_disk(int n, int from, int to, int with) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from, to);
        return;
    }

    move_disk(n - 1, from, with, to);
    printf("Move disk %d from rod %d to rod %d\n", n, from, to);
    move_disk(n - 1, with, to, from);
}

void tower_of_hanoi(int n) {
    int from = 1, to = 3, with = 2;
    printf("Tower of Hanoi with %d disks:\n", n);
    srand(time(NULL));
    for (int i = n; i >= 1; i--) {
        move_disk(i, from, to, with);
        int rand_num = rand() % 3;
        if (rand_num == 0) {
            from = 1;
            to = 3;
            with = 2;
        } else if (rand_num == 1) {
            from = 2;
            to = 1;
            with = 3;
        } else {
            from = 3;
            to = 2;
            with = 1;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n > MAX_DISKS) {
        printf("Invalid number of disks. Maximum disks allowed: %d\n", MAX_DISKS);
        return 1;
    }

    tower_of_hanoi(n);

    return 0;
}