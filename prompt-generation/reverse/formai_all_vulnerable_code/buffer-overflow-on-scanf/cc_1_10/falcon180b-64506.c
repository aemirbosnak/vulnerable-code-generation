//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int from, int to, int aux, char *msg) {
    printf("%s: ", msg);
    for (int i = 0; i <= n; i++) {
        if (i == from || i == to || i == aux) {
            printf("* ");
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

// Function to move n disks from from_tower to to_tower using aux_tower
void hanoi(int n, int from_tower, int to_tower, int aux_tower) {
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", from_tower, to_tower);
        return;
    }

    hanoi(n - 1, from_tower, aux_tower, to_tower);
    printf("Move disk %d from %d to %d\n", n, from_tower, to_tower);
    hanoi(n - 1, aux_tower, to_tower, from_tower);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    srand(time(NULL));
    int from_tower = rand() % 3;
    int to_tower = (from_tower + 1) % 3;
    int aux_tower = (from_tower + 2) % 3;

    printf("Starting configuration:\n");
    print_towers(n, from_tower, to_tower, aux_tower, "Starting");

    hanoi(n, from_tower, to_tower, aux_tower);

    printf("Final configuration:\n");
    print_towers(n, from_tower, to_tower, aux_tower, "Final");

    return 0;
}