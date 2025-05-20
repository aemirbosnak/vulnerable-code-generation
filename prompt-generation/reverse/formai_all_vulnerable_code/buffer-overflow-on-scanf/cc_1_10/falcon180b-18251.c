//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

struct disk {
    int size;
    int position;
};

void moveDisk(struct disk* disk, int from, int to, int n) {
    if (n == 1) {
        disk[to] = disk[from];
    } else {
        struct disk tmp;
        tmp = disk[from];
        disk[from] = disk[to];
        disk[to] = tmp;
        moveDisk(disk, from, to - 1, n - 1);
    }
}

void printDisks(struct disk* disk, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", disk[i].size);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    struct disk disks[n];
    for (int i = n - 1; i >= 0; i--) {
        disks[i].size = rand() % 10 + 1;
    }
    printf("Initial state:\n");
    printDisks(disks, n);
    printf("Solving...\n");
    moveDisk(disks, 0, 2, n);
    printf("Final state:\n");
    printDisks(disks, n);
    return 0;
}