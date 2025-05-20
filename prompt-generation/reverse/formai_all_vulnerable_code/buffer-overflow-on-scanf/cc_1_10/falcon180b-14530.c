//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
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
    int temp = tower[from];
    for (int i = from; i > to; i--) {
        tower[i] = tower[i - 1];
    }
    tower[to] = temp;
}

void tower_of_hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    int tower[MAX_DISKS];
    for (int i = n; i >= 1; i--) {
        tower[i - 1] = i;
    }

    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("%d ", tower[i - 1]);
        printf("\n");
    }

    int steps = 0;
    while (n > 0) {
        if (n == 1) {
            move_disk(tower, n, from_rod, to_rod);
            printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
            break;
        }

        for (int i = 0; i < n - 1; i++) {
            move_disk(tower, n, from_rod, aux_rod);
            printf("Move disk %d from rod %d to rod %d\n", n, from_rod, aux_rod);
            steps++;

            move_disk(tower, n - 1, aux_rod, to_rod);
            printf("Move disk %d from rod %d to rod %d\n", n, aux_rod, to_rod);
            steps++;
        }

        move_disk(tower, n, from_rod, to_rod);
        printf("Move disk %d from rod %d to rod %d\n", n, from_rod, to_rod);
        steps++;
    }

    printf("Total steps: %d\n", steps);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    srand(time(NULL));
    int from_rod = rand() % 3;
    int to_rod = rand() % 3;
    int aux_rod = (from_rod + to_rod) % 3;

    printf("Initial state:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    tower_of_hanoi(n, from_rod, to_rod, aux_rod);

    return 0;
}