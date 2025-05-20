//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void print_tower(int tower[], int height) {
    for (int i = height - 1; i >= 0; i--) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

void move_disk(int tower[], int height, int from, int to) {
    if (from < to) {
        printf("Move disk %d from %d to %d\n", height, from, to);
    } else {
        printf("Move disk %d from %d to %d\n", height, from, to);
    }
    tower[to] = tower[from];
    tower[from] = 0;
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks > MAX_DISKS) {
        printf("Error: number of disks exceeds the maximum limit of %d\n", MAX_DISKS);
        return 1;
    }

    int tower[MAX_DISKS];
    for (int i = num_disks - 1; i >= 0; i--) {
        tower[i] = i + 1;
    }

    printf("Initial tower:\n");
    print_tower(tower, num_disks);

    srand(time(NULL));
    int num_moves = 0;
    for (int i = num_disks - 1; i >= 0; i--) {
        int from = rand() % i + 1;
        int to = rand() % (i + 1);
        if (from!= to) {
            move_disk(tower, num_disks, from, to);
            num_moves++;
        }
    }

    printf("Final tower:\n");
    print_tower(tower, num_disks);

    printf("Number of moves: %d\n", num_moves);

    return 0;
}