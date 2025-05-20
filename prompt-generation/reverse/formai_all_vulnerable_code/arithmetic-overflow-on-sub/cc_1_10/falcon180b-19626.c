//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", 'A' + i);
    }
    printf(" %c -> %c\n", from, to);
}

// Function to check if a move is valid
int is_valid_move(int n, char from, char to) {
    if (from == 'A' || from == 'C') {
        if (to == 'B' && to!= from) {
            return 1;
        }
    } else if (from == 'B') {
        if (to == 'A' || to == 'C' && to!= from) {
            return 1;
        }
    }
    return 0;
}

// Function to move a disk from one tower to another
void move_disk(int n, char from, char to) {
    if (is_valid_move(n, from, to)) {
        printf("%c -> %c\n", from, to);
    } else {
        printf("Invalid move\n");
    }
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        move_disk(n, from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    move_disk(n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}