//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void hanoi(int n, char from_rod, char to_rod, char aux_rod);
void move_disk(int n, char from_rod, char to_rod);
void print_tower(int n, char *rod1, char *rod2, char *rod3);

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("Tower of Hanoi with %d disks:\n", n);

    srand(time(NULL));
    char *rods[3] = {"A", "B", "C"};
    for (int i = 0; i < 3; i++) {
        rods[i] = rods[i] + (rand() % 26);
    }

    hanoi(n, rods[0], rods[2], rods[1]);

    return 0;
}

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }

    hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

void move_disk(int n, char from_rod, char to_rod) {
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
}

void print_tower(int n, char *rod1, char *rod2, char *rod3) {
    printf("Tower of Hanoi problem with %d disks:\n", n);
    printf("Initial state:\n");
    printf("  %c: ", rod1);
    for (int i = n; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");

    printf("  %c: \n", rod2);

    printf("  %c: ", rod3);
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}