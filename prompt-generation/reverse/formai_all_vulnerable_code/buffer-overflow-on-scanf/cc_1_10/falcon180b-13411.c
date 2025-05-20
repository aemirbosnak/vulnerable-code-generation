//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // maximum number of disks

// function to print the current state of the towers
void print_towers(int n, char source, char target, char auxiliary) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", 'A' + i);
    }
    printf(" -> ");
    printf("%c ", source);
    for (i = 0; i < n - 1; i++) {
        printf("%c ", 'A' + i);
    }
    printf(" <- ");
    printf("%c\n", target);
}

// function to check if a move is valid
int is_valid_move(int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || from == to) {
        return 0;
    }
    if (from == 0 && to == 2) {
        return 0;
    }
    if (from == 1 && to == 0) {
        return 0;
    }
    return 1;
}

// function to move a disk from one tower to another
void move_disk(int n, int from, int to) {
    int i;
    for (i = n - 1; i >= from; i--) {
        printf("%c -> %c\n", 'A' + i, 'A' + to);
        sleep(1);
    }
    for (i = 0; i <= to; i++) {
        printf("%c <- %c\n", 'A' + i, 'A' + from);
        sleep(1);
    }
}

// function to solve the Tower of Hanoi problem recursively
void hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        move_disk(1, source, target);
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    move_disk(n, source, target);
    hanoi(n - 1, auxiliary, target, source);
}

// main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    printf("Solving the Tower of Hanoi problem with %d disks:\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}