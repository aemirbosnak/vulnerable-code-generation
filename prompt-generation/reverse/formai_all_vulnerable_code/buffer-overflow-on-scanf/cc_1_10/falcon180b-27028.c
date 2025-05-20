//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: thoughtful
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

void move_disk(int tower[], int from_rod, int to_rod, int height) {
    if (height == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
    } else {
        move_disk(tower, from_rod, to_rod == 1? 3 : 1, height - 1);
        printf("Move disk %d from rod %d to rod %d\n", height, from_rod, to_rod);
    }
}

void hanoi(int tower[], int height, int from_rod, int to_rod) {
    if (height == 1) {
        move_disk(tower, from_rod, to_rod, height);
    } else {
        hanoi(tower, height - 1, from_rod, to_rod == 1? 3 : 1);
        move_disk(tower, from_rod, to_rod, height);
        hanoi(tower, height - 1, to_rod, from_rod);
    }
}

int main() {
    srand(time(NULL));
    int tower[MAX_DISKS];
    int height;

    printf("Enter the number of disks: ");
    scanf("%d", &height);
    if (height < 1 || height > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    printf("Random initial tower:\n");
    for (int i = height - 1; i >= 0; i--) {
        tower[i] = rand() % 4 + 1;
        printf("%d ", tower[i]);
    }
    printf("\n");

    printf("Solving...\n");
    hanoi(tower, height, 1, 3);

    printf("Final tower:\n");
    print_tower(tower, height);

    return 0;
}