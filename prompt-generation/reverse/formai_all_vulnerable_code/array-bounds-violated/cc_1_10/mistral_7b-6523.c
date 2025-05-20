//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DISKS 5
#define SOURCE 1
#define TARGET 3
#define AUX 2

char *names[4] = {"A", "B", "C", "D"};
int disks[NUM_DISKS];

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n > 0) {
        hanoi(n - 1, from_rod, aux_rod, to_rod);
        printf("Move disk %d from %s to %s\n", n, names[from_rod - 'A'], names[to_rod - 'A']);
        disks[to_rod]++;
        hanoi(n - 1, aux_rod, to_rod, from_rod);
    }
}

void init() {
    int i;
    for (i = 0; i < NUM_DISKS; i++)
        disks[i] = i;
}

void print_status() {
    int i;
    printf("\n");
    for (i = 0; i < NUM_DISKS; i++)
        printf("Disk %d on rod %d\n", disks[i], i + 'A');
}

int main() {
    srand(time(NULL));

    init();
    printf("Move %d disks from rod %c to rod %c using rod %c\n", NUM_DISKS, SOURCE, TARGET, AUX);

    hanoi(NUM_DISKS, SOURCE, AUX, TARGET);
    print_status();

    return 0;
}

// Ken Thompson style randomization
#define SWAP(a, b) (t=(a), (a)=(b), (b)=t)
int rand_r(unsigned int *seed) {
    static int t;
    *seed = (*seed) * 1103515245 + 12345;
    SWAP(*seed, t);
    return (*seed) >> 16;
}