//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int src, int dest, int aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == src)
            printf("->");
        else if (i == dest)
            printf("<->");
        else
            printf("   ");
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to, int aux) {
    if (from < 0 || from >= n || to < 0 || to >= n || aux < 0 || aux >= n)
        return 0;
    if (to > from) {
        if (aux > from && aux < to)
            return 0;
    } else {
        if (aux < from || aux > to)
            return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, int from, int to, int aux) {
    if (from!= to) {
        if (from < to) {
            move_disk(n, from, aux, to);
            printf("Move disk %d from tower %d to tower %d\n", n, from, to);
            move_disk(n, aux, to, from);
        } else {
            move_disk(n, from, aux, to);
            printf("Move disk %d from tower %d to tower %d\n", n, from, to);
            move_disk(n, aux, from, to);
        }
    }
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, int src, int dest, int aux) {
    if (n == 1) {
        move_disk(n, src, dest, aux);
        return;
    }
    hanoi(n - 1, src, aux, dest);
    move_disk(n, src, dest, aux);
    hanoi(n - 1, aux, dest, src);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }
    hanoi(n, 0, 2, 1);
    return 0;
}