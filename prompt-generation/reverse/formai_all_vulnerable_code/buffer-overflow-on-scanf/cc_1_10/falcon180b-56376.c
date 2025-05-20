//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

/* Function to print the disks */
void print_disks(int n, int from_rod, int to_rod, int aux_rod) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from_rod) {
            printf("->");
        } else if (i == to_rod) {
            printf("<->");
        } else if (i == aux_rod) {
            printf("X");
        } else {
            printf("   ");
        }
    }
    printf("\n");
}

/* Function to move n disks from from_rod to to_rod using aux_rod */
void tower_of_hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);

    printf("Move disk %d from rod %d to rod %d\n", n, from_rod, to_rod);

    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

/* Main function */
int main() {
    int n;
    printf("Enter the number of disks (<= %d): ", MAX_DISKS);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    printf("The initial state of the rods:\n");
    print_disks(n, 0, 2, 1);

    tower_of_hanoi(n, 0, 2, 1);

    printf("The final state of the rods:\n");
    print_disks(n, 2, 0, 1);

    return 0;
}