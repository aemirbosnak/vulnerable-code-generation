//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_DISKS 10

void display_tower(int tower[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

void move_disk(int tower[], int n, int from, int to) {
    if (n > 0) {
        int temp = tower[n - 1];
        tower[n - 1] = 0;
        while (from > to) {
            from--;
            tower[from] = temp;
        }
        tower[to] = temp;
        display_tower(tower, n);
    } else {
        printf("Invalid move!\n");
    }
}

int main() {
    int n, i, j;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n > MAX_DISKS) {
        printf("Number of disks should be less than or equal to %d.\n", MAX_DISKS);
        exit(0);
    }
    int tower[n];
    for (i = n - 1; i >= 0; i--) {
        tower[i] = i + 1;
    }
    display_tower(tower, n);
    srand(time(NULL));
    int choice = rand() % 3;
    if (choice == 0) {
        move_disk(tower, n, 0, 2);
        move_disk(tower, n, 0, 1);
        move_disk(tower, n, 2, 1);
        move_disk(tower, n, 0, 2);
        move_disk(tower, n, 1, 2);
        move_disk(tower, n, 0, 1);
        move_disk(tower, n, 2, 1);
        move_disk(tower, n, 0, 2);
    } else if (choice == 1) {
        move_disk(tower, n, 0, 1);
        move_disk(tower, n, 0, 2);
        move_disk(tower, n, 1, 2);
        move_disk(tower, n, 0, 1);
        move_disk(tower, n, 2, 1);
        move_disk(tower, n, 0, 2);
        move_disk(tower, n, 1, 2);
        move_disk(tower, n, 0, 1);
    } else {
        move_disk(tower, n, 0, 2);
        move_disk(tower, n, 0, 1);
        move_disk(tower, n, 2, 1);
        move_disk(tower, n, 0, 2);
        move_disk(tower, n, 1, 2);
        move_disk(tower, n, 0, 1);
        move_disk(tower, n, 2, 1);
        move_disk(tower, n, 0, 2);
    }
    return 0;
}