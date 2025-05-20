//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define MAX_DISKS 10
#define MAX_MOVES 100

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int rand_bool() {
    return rand() % 2;
}

void print_tower(int tower[MAX_DISKS], int n) {
    for (int i = 0; i <= n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

void move_disk(int from, int to, int n, int *tower) {
    if (n == 1) {
        tower[to] = tower[from];
        tower[from] = 0;
        return;
    }

    int aux = rand_int(0, 2);
    if (aux == 0) {
        move_disk(from, to - 1, n - 1, tower);
    } else {
        move_disk(from, 2 * to - 1, n - 1, tower);
    }
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    int tower[MAX_DISKS];
    for (int i = 0; i <= n; i++) {
        tower[i] = 0;
    }

    int moves = 0;
    while (true) {
        if (moves >= MAX_MOVES) {
            printf("Too many moves.\n");
            break;
        }

        int from = rand_int(0, n - 1);
        int to = rand_int(0, n - 1);

        if (from == to) {
            continue;
        }

        if (from < to) {
            move_disk(from, to, n, tower);
            moves++;
        } else {
            int aux = rand_int(0, 2);
            if (aux == 0) {
                move_disk(from, to - 1, n - 1, tower);
            } else {
                move_disk(from, 2 * to - 1, n - 1, tower);
            }
            moves++;
        }

        print_tower(tower, n);
    }

    return 0;
}