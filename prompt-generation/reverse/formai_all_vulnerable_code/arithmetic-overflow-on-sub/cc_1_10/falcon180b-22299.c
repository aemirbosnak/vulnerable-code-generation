//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define DELAY 10000

// Function prototypes
void print_tower(int n, int from, int to);
void move_disk(int n, int from, int to, int aux);
int main();

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    int from = 0;
    int to = 2;
    int aux = 1;

    printf("Tower of Hanoi with %d disks\n", n);
    printf("Initial position:\n");
    print_tower(n, from, to);

    move_disk(n, from, to, aux);

    return 0;
}

void print_tower(int n, int from, int to) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from)
            printf("X");
        else if (i == to)
            printf("O");
        else
            printf(" ");
        printf("\n");
    }
}

void move_disk(int n, int from, int to, int aux) {
    int i;
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", from, to);
        printf("Result:\n");
        print_tower(n, to, aux);
        return;
    }

    move_disk(n - 1, from, aux, to);

    printf("Move disk %d from %d to %d\n", n, from, to);

    print_tower(n, from, to);

    move_disk(n - 1, aux, to, from);
}