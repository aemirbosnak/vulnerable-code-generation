//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    int disks[MAX_DISKS];
    for (int i = num_disks - 1; i >= 0; i--) {
        disks[i] = i;
    }

    int start_rod = rand() % 3;
    int end_rod = (start_rod + 1) % 3;
    int other_rod = (start_rod + 2) % 3;

    printf("Starting rod: %d\n", start_rod + 1);
    printf("Ending rod: %d\n", end_rod + 1);
    printf("Other rod: %d\n", other_rod + 1);

    int moves = 0;
    int current_rod = start_rod;
    int prev_rod = (current_rod - 1 + 3) % 3;
    int next_rod = (current_rod + 1) % 3;

    while (current_rod!= end_rod) {
        if (current_rod == start_rod) {
            printf("Move disk %d from rod %d to rod %d\n", disks[num_disks - 1], start_rod + 1, end_rod + 1);
            current_rod = end_rod;
        } else if (current_rod == other_rod) {
            printf("Move disk %d from rod %d to rod %d\n", disks[num_disks - 1], other_rod + 1, end_rod + 1);
            current_rod = end_rod;
        } else {
            printf("Move disk %d from rod %d to rod %d\n", disks[num_disks - 1], start_rod + 1, other_rod + 1);
            current_rod = other_rod;
        }

        int temp_rod = prev_rod;
        prev_rod = current_rod;
        current_rod = next_rod;
        next_rod = temp_rod;

        moves++;
    }

    printf("Total moves: %d\n", moves);

    return 0;
}