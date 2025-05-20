//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

// Function to print the disks
void print_disks(int n, int from_rod, int to_rod, int aux_rod) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from_rod) {
            printf("X");
        } else if (i == to_rod) {
            printf("O");
        } else if (i == aux_rod) {
            printf("A");
        } else {
            printf("-");
        }
    }
    printf("\n");
}

// Function to check if the disks are in the correct order
int check_disks(int n, int from_rod, int to_rod, int aux_rod) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from_rod) {
            continue;
        }
        if (i!= to_rod && i!= aux_rod) {
            return 0;
        }
    }
    return 1;
}

// Function to move a disk from one rod to another
void move_disk(int n, int from_rod, int to_rod, int aux_rod) {
    int i;
    for (i = n - 1; i >= 0; i--) {
        if (i == from_rod) {
            printf("Moving disk %d from rod %d to rod %d\n", i + 1, from_rod, to_rod);
            break;
        }
    }
    for (int j = 0; j < i; j++) {
        if (j == to_rod) {
            printf("Cannot move disk %d to rod %d, it is already occupied\n", i + 1, to_rod);
            return;
        }
    }
    for (int k = 0; k < i; k++) {
        if (k == aux_rod) {
            printf("Cannot move disk %d to rod %d, it is already occupied\n", i + 1, aux_rod);
            return;
        }
    }
    printf("Moving disk %d from rod %d to rod %d\n", i + 1, from_rod, to_rod);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        move_disk(n, from_rod, to_rod, aux_rod);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    move_disk(n, from_rod, to_rod, aux_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Main function
int main() {
    int n, from_rod, to_rod, aux_rod;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    srand(time(NULL));
    from_rod = rand() % 3;
    to_rod = rand() % 3;
    aux_rod = (from_rod + to_rod) % 3;
    printf("The disks are initially on rod %d\n", from_rod);
    print_disks(n, from_rod, to_rod, aux_rod);
    tower_of_hanoi(n, from_rod, to_rod, aux_rod);
    printf("The disks are now on rod %d\n", to_rod);
    print_disks(n, from_rod, to_rod, aux_rod);
    return 0;
}