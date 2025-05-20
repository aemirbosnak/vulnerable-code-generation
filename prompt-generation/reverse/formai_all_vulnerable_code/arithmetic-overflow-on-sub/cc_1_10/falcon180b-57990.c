//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("%c", from);
    for (i = 0; i < n - 1; i++) {
        printf(" ");
    }
    printf("%c\n", to);
    for (i = 0; i < n - 1; i++) {
        printf(" ");
    }
    printf("%c", aux);
}

// Function to check if a move is valid
int is_valid_move(int n, char from, char to) {
    if (from == 'A' && to == 'C') {
        return 1;
    } else if (from == 'A' && to == 'B' && n > 1) {
        return 1;
    } else if (from == 'B' && to == 'A') {
        return 1;
    } else if (from == 'B' && to == 'C' && n > 1) {
        return 1;
    } else if (from == 'C' && to == 'B' && n > 1) {
        return 1;
    } else if (from == 'C' && to == 'A' && n > 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to move a disk from one tower to another
void move_disk(int n, char from, char to, char aux) {
    printf("Move disk %d from %c to %c\n", n, from, to);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        move_disk(1, from, to, aux);
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    move_disk(n, from, to, aux);
    tower_of_hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}