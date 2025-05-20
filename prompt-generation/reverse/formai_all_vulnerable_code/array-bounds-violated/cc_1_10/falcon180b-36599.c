//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void print_tower(int tower[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

void move_disk(int tower[], int n, int from, int to) {
    for (int i = n - 1; i >= from; i--) {
        tower[i + 1] = tower[i];
    }
    tower[to] = tower[0];
}

void play_game(int n) {
    int tower[MAX_DISKS];
    for (int i = n; i > 0; i--) {
        tower[i - 1] = i;
    }
    int from_rod = 0;
    int to_rod = 2;
    int moves = 0;

    while (n > 0) {
        printf("Move disk %d from rod %d to rod %d\n", n, from_rod, to_rod);
        move_disk(tower, n, from_rod, to_rod);
        print_tower(tower, n);
        moves++;

        if (n > 1) {
            from_rod = 0;
            to_rod = 3 - from_rod - to_rod;
        } else {
            printf("Congratulations! You solved the Tower of Hanoi in %d moves.\n", moves);
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    int n = rand() % MAX_DISKS + 3;
    printf("Welcome to the Tower of Hanoi!\n");
    play_game(n);
    return 0;
}