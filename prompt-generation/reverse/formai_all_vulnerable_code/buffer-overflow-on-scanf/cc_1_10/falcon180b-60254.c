//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c: ", 'A' + i);
    }
    printf("-> %c\n", to);
}

// Function to move a disk from one tower to another
void move_disk(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
    } else {
        move_disk(n - 1, from, aux, to);
        printf("Move disk %d from %c to %c\n", n, from, to);
        move_disk(n - 1, aux, to, from);
    }
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
    } else {
        tower_of_hanoi(n - 1, from, aux, to);
        printf("Move disk %d from %c to %c\n", n, from, to);
        tower_of_hanoi(n - 1, aux, to, from);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    printf("Solving the Tower of Hanoi problem with %d disks...\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}