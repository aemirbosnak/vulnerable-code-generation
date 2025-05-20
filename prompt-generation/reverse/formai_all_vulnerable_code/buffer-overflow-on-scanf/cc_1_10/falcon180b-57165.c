//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int a, int b, int c) {
    printf("Move disk %d from ", n);
    if (a == -1)
        printf("A\n");
    else if (b == -1)
        printf("B\n");
    else if (c == -1)
        printf("C\n");
    else
        printf("A to ");

    if (a == -1)
        printf("C\n");
    else if (b == -1)
        printf("B\n");
    else if (c == -1)
        printf("A\n");
    else
        printf("B\n");
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to) {
    if (from == -1 || to == -1 || from == to)
        return 0;

    if (from == 0 && to > 0 && to <= n - 1)
        return 1;

    if (from > 0 && to == 0 && from <= n - 1)
        return 1;

    if (from > 0 && to > 0 && to <= from - 1)
        return 1;

    return 0;
}

// Function to move the disk
void move_disk(int n, int from, int to) {
    int temp = from;

    while (temp!= to) {
        if (temp > to)
            printf("Move disk %d from %d to %d\n", n, temp, temp - 1);
        else
            printf("Move disk %d from %d to %d\n", n, temp, temp + 1);

        temp = (temp + to) / 2;
    }

    printf("Move disk %d from %d to %d\n", n, from, to);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, int a, int b, int c) {
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", a, c);
        return;
    }

    tower_of_hanoi(n - 1, a, c, b);
    move_disk(n, a, c);
    tower_of_hanoi(n - 1, b, a, c);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    tower_of_hanoi(n, 0, 1, 2);

    return 0;
}