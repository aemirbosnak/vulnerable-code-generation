//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

void display_tower(int tower[], int height) {
    for (int i = height - 1; i >= 0; i--) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

void move_disk(int tower[], int from, int to, int height) {
    if (height == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from, to);
        return;
    }

    int temp_rod = (from + to + 1) % 3;
    move_disk(tower, from, temp_rod, height - 1);
    move_disk(tower, temp_rod, to, height - 1);
    printf("Move disk %d from rod %d to rod %d\n", height, from, to);
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    int tower[MAX_DISKS];
    for (int i = num_disks; i >= 1; i--) {
        tower[num_disks - i] = i;
    }

    srand(time(NULL));
    int start_rod = rand() % 3;
    int end_rod = (start_rod + 2) % 3;
    int steps = 0;

    printf("Starting position:\n");
    display_tower(tower, num_disks);

    move_disk(tower, start_rod, end_rod, num_disks);

    printf("Final position:\n");
    display_tower(tower, num_disks);

    printf("Number of steps: %d\n", steps);

    return 0;
}