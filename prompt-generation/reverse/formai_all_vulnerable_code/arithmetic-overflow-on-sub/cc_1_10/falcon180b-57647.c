//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    int i;

    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);

    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    for (i = 1; i < n; i++) {
        tower_of_hanoi(i, aux_rod, to_rod, from_rod);
    }
}

int main() {
    int n;
    char from_rod, to_rod, aux_rod;
    time_t start_time, end_time;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    from_rod = 'A';
    to_rod = 'C';
    aux_rod = 'B';

    printf("Starting the Tower of Hanoi problem with %d disks...\n", n);

    start_time = time(NULL);
    tower_of_hanoi(n, from_rod, to_rod, aux_rod);
    end_time = time(NULL);

    printf("The Tower of Hanoi problem with %d disks was solved in %ld seconds.\n", n, end_time - start_time);

    return 0;
}