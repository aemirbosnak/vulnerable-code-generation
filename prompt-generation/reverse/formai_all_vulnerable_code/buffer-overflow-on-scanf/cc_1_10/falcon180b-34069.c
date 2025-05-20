//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c: ", 'A' + i);
    }
    printf("\n");
    printf("Move disk %d from %c to %c\n", n, from, to);
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || to == from) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, char from, char to) {
    printf("Moving disk from %c to %c\n", from, to);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        move_disk(n, from, to);
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    move_disk(n, from, to);
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