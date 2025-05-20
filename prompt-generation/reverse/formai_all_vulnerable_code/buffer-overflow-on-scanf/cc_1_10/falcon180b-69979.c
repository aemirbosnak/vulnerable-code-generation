//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100
#define DELAY_TIME 100000

void move_disk(int num_disks, int from_rod, int to_rod, int aux_rod) {
    printf("Moving disk %d from rod %c to rod %c\n", num_disks, 'A' + from_rod, 'A' + to_rod);
    if (num_disks == 1) {
        printf("Disk %d has been moved to rod %c\n", num_disks, 'A' + to_rod);
    } else {
        move_disk(num_disks - 1, from_rod, aux_rod, to_rod);
        printf("Disk %d has been moved to rod %c\n", num_disks, 'A' + to_rod);
        move_disk(num_disks - 1, aux_rod, to_rod, from_rod);
    }
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    int start_rod = 'A';
    int end_rod = 'C';
    int aux_rod = 'B';

    printf("Starting configuration:\n");
    printf("Rod A: ");
    for (int i = num_disks; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");

    move_disk(num_disks, start_rod, end_rod, aux_rod);

    printf("\n\nEnding configuration:\n");
    printf("Rod A: ");
    for (int i = 1; i <= num_disks; i++) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}