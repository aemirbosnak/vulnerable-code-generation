//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", 'A' + i);
    }
    printf(" -> ");
    printf("%c ", from);
    printf(" <- ");
    printf("%c ", to);
    if (aux!= '\0') {
        printf("%c ", aux);
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int n, char from, char to) {
    if (from == '\0' || to == '\0' || to == from) {
        return 0;
    }
    if (to < from) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one peg to another
void move_disk(int n, char from, char to) {
    char aux;
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    if (is_valid_move(n, from, to)) {
        aux = 'A' + n - 1;
        move_disk(n - 1, from, aux);
        printf("Move disk %c from %c to %c\n", n, from, to);
        move_disk(n - 1, aux, to);
    } else {
        printf("Invalid move\n");
    }
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Move disk %c from %c to %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n, i;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Invalid number of disks\n");
        return 1;
    }
    printf("Solving Tower of Hanoi problem with %d disks...\n", n);
    printf("Initial state:\n");
    print_towers(n, 'A', 'C', '\0');
    hanoi(n, 'A', 'C', 'B');
    printf("Final state:\n");
    print_towers(n, 'A', 'B', 'C');
    return 0;
}