//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

// Function to print the disks on the three pegs
void print_disks(int n, int peg1, int peg2, int peg3) {
    printf("Peg 1: ");
    for (int i = n - 1; i >= 0; i--) {
        if (i <= peg1) {
            printf("* ");
        } else {
            printf("  ");
        }
    }
    printf("\n");

    printf("Peg 2: ");
    for (int i = n - 1; i >= 0; i--) {
        if (i <= peg2) {
            printf("* ");
        } else {
            printf("  ");
        }
    }
    printf("\n");

    printf("Peg 3: ");
    for (int i = n - 1; i >= 0; i--) {
        if (i <= peg3) {
            printf("* ");
        } else {
            printf("  ");
        }
    }
    printf("\n");
}

// Function to move a disk from one peg to another
void move_disk(int n, int from_peg, int to_peg, int aux_peg) {
    if (n == 1) {
        printf("Move disk 1 from peg %d to peg %d\n", from_peg, to_peg);
        return;
    }

    move_disk(n - 1, from_peg, aux_peg, to_peg);

    printf("Move disk %d from peg %d to peg %d\n", n, from_peg, to_peg);

    move_disk(n - 1, aux_peg, to_peg, from_peg);
}

// Function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(int n, int from_peg, int to_peg, int aux_peg) {
    if (n == 1) {
        printf("Solved Tower of Hanoi with 1 disk\n");
        return;
    }

    solve_tower_of_hanoi(n - 1, from_peg, aux_peg, to_peg);

    printf("Move disk %d from peg %d to peg %d\n", n, from_peg, to_peg);

    solve_tower_of_hanoi(n - 1, aux_peg, to_peg, from_peg);
}

// Function to generate a random Tower of Hanoi problem
void generate_random_tower_of_hanoi(int n) {
    srand(time(NULL));

    int from_peg = rand() % 3;
    int to_peg = rand() % 3;
    while (to_peg == from_peg) {
        to_peg = rand() % 3;
    }
    int aux_peg = 3 - from_peg - to_peg;

    printf("Random Tower of Hanoi with %d disks\n", n);
    print_disks(n, from_peg, to_peg, aux_peg);

    solve_tower_of_hanoi(n, from_peg, to_peg, aux_peg);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n > MAX_DISKS) {
        printf("Error: Number of disks cannot be greater than %d\n", MAX_DISKS);
        return 1;
    }

    generate_random_tower_of_hanoi(n);

    return 0;
}