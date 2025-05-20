//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c: ", 'A' + i);
    }
    printf("-> %c\n", to);
}

// Function to check if a move is valid
int is_valid_move(int n, char from, char to, char aux) {
    if (from == to) {
        return 0;
    }
    if (from == 'A' || to == 'C') {
        return 1;
    }
    if (aux == 'A' || aux == 'C') {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, char from, char to, char aux) {
    if (from!= 'A' && from!= 'C') {
        printf("Invalid starting tower.\n");
        exit(1);
    }
    if (to!= 'A' && to!= 'C') {
        printf("Invalid destination tower.\n");
        exit(1);
    }
    if (!is_valid_move(n, from, to, aux)) {
        printf("Invalid move.\n");
        exit(1);
    }
    if (n == 1) {
        printf("Moving disk 1 from %c to %c.\n", from, to);
    } else {
        move_disk(n - 1, from, aux, to);
        printf("Moving disk %d from %c to %c.\n", n, from, to);
        move_disk(n - 1, aux, to, from);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        exit(1);
    }
    move_disk(n, 'A', 'C', 'B');
    return 0;
}