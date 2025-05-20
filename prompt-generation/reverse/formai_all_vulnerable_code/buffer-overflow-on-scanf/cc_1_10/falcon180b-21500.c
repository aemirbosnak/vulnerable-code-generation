//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100
#define DELAY_TIME 500000

// Function to print the disks
void print_disks(int n, int from_rod, int to_rod, int aux_rod) {
    printf("Move disk %d from rod %c to rod %c\n", n, 'A' + from_rod, 'A' + to_rod);
    if (aux_rod!= -1) {
        printf("Using rod %c as auxiliary\n", 'A' + aux_rod);
    }
}

// Function to move the disks
void move_disks(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", 'A' + from_rod, 'A' + to_rod);
    } else {
        move_disks(n - 1, from_rod, aux_rod, to_rod);
        print_disks(n, from_rod, to_rod, aux_rod);
        move_disks(n - 1, aux_rod, to_rod, from_rod);
    }
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    if (n <= 0) {
        return;
    }

    for (int i = 1; i <= n; i++) {
        move_disks(n, from_rod, to_rod, aux_rod);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    int from_rod = 0;
    int to_rod = 2;
    int aux_rod = 1;

    srand(time(NULL));
    int delay = rand() % DELAY_TIME + 1;

    printf("Solving the Tower of Hanoi problem with %d disks\n", n);
    printf("Moving disks from rod %c to rod %c using rod %c as auxiliary\n", 'A' + from_rod, 'A' + to_rod, 'A' + aux_rod);

    tower_of_hanoi(n, from_rod, to_rod, aux_rod);

    printf("\nProblem solved in %d steps\n", n * 2 - 1);

    return 0;
}