//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: retro
#include <stdio.h>

#define MAX_DISKS 10

int disks[MAX_DISKS];
int num_disks;
int source_rod, destination_rod, temp_rod;

void init_disks(int num) {
    num_disks = num;
    for (int i = 0; i < num; i++) {
        disks[i] = i;
    }
}

void draw_tower(int num_disks) {
    for (int i = num_disks - 1; i >= 0; i--) {
        printf("%d ", disks[i]);
    }
    printf("\n");
}

int is_valid_move(int from, int to) {
    if (from == to) {
        return 0;
    }
    if (from < to) {
        for (int i = from + 1; i < to; i++) {
            if (disks[i]!= -1) {
                return 0;
            }
        }
    } else {
        for (int i = from - 1; i > to; i--) {
            if (disks[i]!= -1) {
                return 0;
            }
        }
    }
    return 1;
}

void move_disk(int from, int to) {
    if (is_valid_move(from, to)) {
        if (from < to) {
            disks[to] = disks[from];
            disks[from] = -1;
        } else {
            disks[to] = disks[from];
            disks[from] = -1;
        }
    }
}

void hanoi(int num_disks, int source, int destination, int temp) {
    if (num_disks == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", source, destination);
        move_disk(source, destination);
        draw_tower(num_disks);
        return;
    }
    hanoi(num_disks - 1, source, temp, destination);
    printf("Move disk %d from rod %d to rod %d\n", num_disks, source, destination);
    move_disk(source, destination);
    draw_tower(num_disks);
    hanoi(num_disks - 1, temp, destination, source);
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    init_disks(num_disks);
    printf("Initial tower:\n");
    draw_tower(num_disks);
    printf("Solving...\n");
    hanoi(num_disks, 0, 2, 1);
    printf("Final tower:\n");
    draw_tower(num_disks);
    return 0;
}