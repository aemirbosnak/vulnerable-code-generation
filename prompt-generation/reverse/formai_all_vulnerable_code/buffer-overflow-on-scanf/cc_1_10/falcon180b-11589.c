//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define MOVE_DELAY 50000 // 50ms

// Function to print the current state of the towers
void print_towers(int n, int from, int to, int aux) {
    printf("Tower 1: ");
    for (int i = n; i >= 1; i--) {
        if (i <= n - from) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("\nTower 2: ");
    for (int i = 0; i <= n - 1; i++) {
        if (i == to) {
            printf("*");
        } else if (i == aux) {
            printf("X");
        } else {
            printf(" ");
        }
    }
    printf("\nTower 3: ");
    for (int i = 0; i <= n - 1; i++) {
        if (i >= from && i <= n - to - 1) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

// Function to move a disk from one tower to another
void move_disk(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Moving disk 1 from tower 1 to tower 2...\n");
        sleep(MOVE_DELAY);
        printf("Disk 1 successfully moved to tower 2.\n");
        return;
    }
    move_disk(n - 1, from, aux, to);
    printf("Moving disk %d from tower 1 to tower 3...\n", n);
    sleep(MOVE_DELAY);
    printf("Disk %d successfully moved to tower 3.\n", n);
    move_disk(n - 1, aux, to, from);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n) {
    int from = 1, to = 3, aux = 2;
    printf("Solving Tower of Hanoi problem with %d disks...\n", n);
    for (int i = n; i >= 1; i--) {
        move_disk(i, from, to, aux);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    printf("Solving Tower of Hanoi problem with %d disks...\n", n);
    tower_of_hanoi(n);
    return 0;
}