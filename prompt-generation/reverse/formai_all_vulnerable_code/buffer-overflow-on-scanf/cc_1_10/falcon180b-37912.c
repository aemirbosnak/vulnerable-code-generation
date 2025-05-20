//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 1000 // maximum number of disks allowed in the tower
#define TOWER_SIZE 4 // number of towers
#define MOVE_DELAY 200000 // delay in microseconds between moves

void move_disk(int from, int to, int disks[], int n)
{
    if (n == 1) {
        printf("Move disk 1 from tower %d to tower %d\n", from, to);
        return;
    }

    move_disk(from, to + 1, disks, n - 1);
    printf("Move disk %d from tower %d to tower %d\n", n, from, to);
    move_disk(to, from, disks, n - 1);
}

int main()
{
    int disks[MAX_DISKS];
    int n = 0;
    int from = 0;
    int to = 2;
    int i;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Initial tower:");
    for (i = n; i >= 1; i--) {
        printf(" %d", i);
    }
    printf("\n");

    while (n > 0) {
        move_disk(from, to, disks, n);
        usleep(MOVE_DELAY);

        printf("Tower %d: ", to);
        for (i = 0; i < n; i++) {
            printf(" %d", disks[i]);
        }
        printf("\n");

        if (to == 1) {
            to = 3;
        } else if (to == 3) {
            to = 2;
        } else {
            from = to;
            to++;
        }

        n--;
    }

    printf("Congratulations! You solved the Tower of Hanoi problem.\n");

    return 0;
}