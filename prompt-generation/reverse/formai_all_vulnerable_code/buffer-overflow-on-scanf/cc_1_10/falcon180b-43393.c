//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 20

void print_disks(int disks, int from, int to) {
    int i;
    for (i = 0; i < disks; i++) {
        if (i == from) {
            printf("->");
        } else if (i == to) {
            printf("<-");
        } else {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void move_disk(int disks, int from, int to, int aux) {
    if (disks == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from, to);
    } else {
        move_disk(disks - 1, from, aux, to);
        printf("Move disk %d from rod %d to rod %d\n", disks, from, to);
        move_disk(disks - 1, aux, to, from);
    }
}

void tower_of_hanoi(int disks) {
    int from = 0, to = 2, aux = 1;
    printf("Tower of Hanoi with %d disks:\n", disks);
    srand(time(NULL));
    int move_count = rand() % (2 * (disks - 1)) + 1;
    int move_num = 1;
    while (move_num <= move_count) {
        print_disks(disks, from, to);
        move_disk(disks, from, to, aux);
        move_num++;
    }
    printf("Total moves: %d\n", move_num);
}

int main() {
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    if (disks < 1 || disks > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    tower_of_hanoi(disks);
    return 0;
}