//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    printf("Move disk %d from %c to %c\n", n, from, to);
    for (i = 0; i < n; i++) {
        if (i == n - 1)
            printf("%c -> %c\n", from, to);
        else
            printf("%c -> %c\n", from, aux);
    }
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to, int aux) {
    if (from < 0 || to < 0 || aux < 0 || from >= MAX_DISKS || to >= MAX_DISKS || aux >= MAX_DISKS)
        return 0;
    if (to < from)
        return 0;
    if (aux < from || aux > to)
        return 0;
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, int from, int to, int aux) {
    printf("Moving disk %d from %c to %c\n", n, from, to);
    if (n == 1) {
        printf("%c -> %c\n", from, to);
        return;
    }
    move_disk(n - 1, from, aux, to);
    printf("%c -> %c\n", from, to);
    move_disk(n - 1, aux, to, from);
}

// Function to solve the Tower of Hanoi problem recursively
void tower_of_hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    tower_of_hanoi(n - 1, aux, to, from);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}