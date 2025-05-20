//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX_DISKS 100
#define MAX_MOVES 1000
#define MAX_TIME 100

void print_tower(int towers[MAX_DISKS], int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", towers[i]);
    }
    printf("\n");
}

void move_disk(int from, int to, int aux, int n) {
    if (n == 1) {
        printf("Move disk 1 from tower %d to tower %d\n", from, to);
        return;
    }
    move_disk(from, aux, to, n - 1);
    printf("Move disk %d from tower %d to tower %d\n", n, from, to);
    move_disk(aux, to, from, n - 1);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        exit(1);
    }
    int towers[MAX_DISKS];
    for (int i = 0; i < n; i++) {
        towers[i] = -1;
    }
    int source = 0;
    int destination = n - 1;
    int aux = -1;
    int moves = 0;
    clock_t start = clock();
    move_disk(source, destination, aux, n);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    if (time > MAX_TIME) {
        printf("Too slow\n");
    } else {
        printf("Time: %.2f seconds\n", time);
    }
    printf("Number of moves: %d\n", moves);
    return 0;
}