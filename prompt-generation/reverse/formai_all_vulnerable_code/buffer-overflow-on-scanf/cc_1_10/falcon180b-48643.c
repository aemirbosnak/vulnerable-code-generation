//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

void print_towers(int towers[MAX_DISKS], int n) {
    for (int i = 0; i < n; i++) {
        printf("Tower %d: ", i + 1);
        for (int j = n - 1; j >= 0; j--) {
            if (towers[i] & (1 << j)) {
                printf("%d ", j + 1);
            }
        }
        printf("\n");
    }
}

void move_disk(int from, int to, int aux, int n) {
    int mask = ~(1 << from) & (n - 1);
    int disks = n - 1;
    while (disks > 0) {
        if (disks == from || disks == to || disks == aux) {
            printf("Move disk %d from %d to %d\n", disks + 1, from + 1, to + 1);
        } else if (disks < from) {
            printf("Move disk %d from %d to %d\n", disks + 1, from + 1, to + 1);
        } else {
            printf("Move disk %d from %d to %d\n", disks + 1, to + 1, from + 1);
        }
        disks--;
    }
}

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", from + 1, to + 1);
        return;
    }
    hanoi(n - 1, from, aux, to);
    move_disk(from, to, aux, n);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }
    hanoi(n, 1, 3, 2);
    return 0;
}