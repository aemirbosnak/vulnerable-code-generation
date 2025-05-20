//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define DELAY 100000

void move_disk(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }

    move_disk(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    move_disk(n - 1, aux_rod, to_rod, from_rod);
}

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n > 0) {
        tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
        move_disk(n, from_rod, to_rod, aux_rod);
        tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
    }
}

int main() {
    int n;
    char from_rod, to_rod, aux_rod;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n > MAX_DISKS) {
        printf("Error: Number of disks cannot exceed %d\n", MAX_DISKS);
        return 1;
    }

    srand(time(NULL));
    from_rod = 'A' + rand() % 3;
    to_rod = 'A' + rand() % 3;
    aux_rod = 'A' + rand() % 3;

    while (from_rod == to_rod || from_rod == aux_rod || to_rod == aux_rod) {
        from_rod = 'A' + rand() % 3;
        to_rod = 'A' + rand() % 3;
        aux_rod = 'A' + rand() % 3;
    }

    printf("The initial position of the disks is:\n");
    printf("From rod %c to rod %c using rod %c\n\n", from_rod, to_rod, aux_rod);

    for (int i = n; i >= 1; i--) {
        printf("Move disk %d:\n", i);
        tower_of_hanoi(i, from_rod, to_rod, aux_rod);
        printf("\n");
        usleep(DELAY);
    }

    return 0;
}