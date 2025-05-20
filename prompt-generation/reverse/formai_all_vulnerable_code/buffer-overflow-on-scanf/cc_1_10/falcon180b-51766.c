//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define DELAY_TIME 100000 // 0.1 seconds

void move_disk(int n, char from_rod, char to_rod, char aux_rod) {
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    printf("Using %c as auxiliary rod\n", aux_rod);
}

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    move_disk(n, from_rod, to_rod, aux_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }
    srand(time(0));
    char from_rod = 'A' + rand() % 3;
    char to_rod = 'A' + rand() % 3;
    char aux_rod = 'A' + rand() % 3;
    while (from_rod == to_rod || from_rod == aux_rod || to_rod == aux_rod) {
        from_rod = 'A' + rand() % 3;
        to_rod = 'A' + rand() % 3;
        aux_rod = 'A' + rand() % 3;
    }
    printf("Solving Tower of Hanoi with %d disks\n", n);
    printf("Using rods A, B, and C\n");
    printf("Initial configuration:\n");
    for (int i = n; i >= 1; i--) {
        printf("Disk %d on rod A\n", i);
    }
    tower_of_hanoi(n, from_rod, to_rod, aux_rod);
    printf("\nFinal configuration:\n");
    for (int i = 1; i <= n; i++) {
        printf("Disk %d on rod %c\n", i, to_rod);
    }
    return 0;
}