//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int from_rod, int to_rod, int aux_rod) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from_rod) {
            printf("From rod: ");
        } else if (i == to_rod) {
            printf("To rod: ");
        } else if (i == aux_rod) {
            printf("Aux rod: ");
        } else {
            printf("Rod %d: ", i);
        }
        printf("[");
        int j;
        for (j = 0; j < n; j++) {
            if (j == from_rod) {
                printf("*");
            } else if (j == to_rod) {
                printf("*");
            } else if (j == aux_rod) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("]\n");
    }
}

// Function to move n disks from from_rod to to_rod using aux_rod
void move_disks(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return;
    }
    move_disks(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %d to rod %d\n", n, from_rod, to_rod);
    move_disks(n - 1, aux_rod, to_rod, from_rod);
}

// Function to solve the Tower of Hanoi problem for n disks
void hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        printf("Solved Tower of Hanoi problem with 1 disk\n");
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %d to rod %d\n", n, from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n, from_rod, to_rod, aux_rod;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Enter the initial rod for the disks: ");
    scanf("%d", &from_rod);
    printf("Enter the final rod for the disks: ");
    scanf("%d", &to_rod);
    printf("Enter the auxiliary rod: ");
    scanf("%d", &aux_rod);
    printf("Initial state of the towers:\n");
    print_towers(n, from_rod, to_rod, aux_rod);
    hanoi(n, from_rod, to_rod, aux_rod);
    printf("Final state of the towers:\n");
    print_towers(n, from_rod, to_rod, aux_rod);
    return 0;
}