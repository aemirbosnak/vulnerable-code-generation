//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void print_tower(int tower[], int disks, int from, int to) {
    for (int i = from; i <= to; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

int main() {
    int disks = 4;
    int tower[MAX_DISKS];
    int from_rod = 0;
    int to_rod = 2;
    int aux_rod = 1;

    srand(time(NULL));
    for (int i = 0; i < disks; i++) {
        tower[i] = rand() % 10;
    }

    printf("Initial tower:\n");
    print_tower(tower, disks, 0, 2);

    int moves = 0;
    while (disks > 0) {
        moves++;
        printf("Move %d: ", moves);
        if (disks > 1) {
            printf("Move %d disks from rod %d to rod %d\n", disks, from_rod, to_rod);
        } else {
            printf("Move disk %d from rod %d to rod %d\n", disks, from_rod, to_rod);
        }
        for (int i = disks - 1; i >= 0; i--) {
            if (i!= disks - 1) {
                tower[to_rod] = tower[i];
            } else {
                tower[to_rod] = tower[from_rod];
            }
            from_rod--;
            to_rod++;
        }
        disks--;
    }

    printf("Final tower:\n");
    print_tower(tower, disks, 0, 2);

    return 0;
}