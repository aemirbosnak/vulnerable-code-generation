//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DISKS 100

void print_disks(int disks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", disks[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    int disks[MAX_DISKS];
    for (int i = n; i >= 1; i--) {
        disks[i] = i;
    }
    disks[0] = 0;

    int source = 0;
    int dest = 2;
    int temp = 1;

    printf("Initial state:\n");
    print_disks(disks, n);

    while (true) {
        if (source == dest) {
            printf("Congratulations! You solved the Tower of Hanoi problem.\n");
            return 0;
        }

        if (source == 0 && dest == 1) {
            temp = 2;
        } else if (source == 1 && dest == 0) {
            temp = 0;
        } else if (source == 2 && dest == 1) {
            temp = 0;
        }

        if (disks[source] > disks[dest]) {
            printf("Invalid move. The disk at the source peg is larger than the disk at the destination peg.\n");
            return 1;
        }

        disks[temp] = disks[source];
        disks[source] = 0;

        printf("Move disk %d from peg %d to peg %d:\n", disks[source], source, dest);
        print_disks(disks, n);

        source = dest;
        dest = temp;
    }

    return 0;
}