//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", 'A' + i);
    }
    printf(" %c -> ", from);
    for (i = 0; i < n - 1; i++) {
        printf("%c ", 'A' + i);
    }
    printf("%c\n", to);
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to, int aux) {
    if (from < 0 || from >= n || to < 0 || to >= n || aux < 0 || aux >= n) {
        return 0;
    }
    if (from == to && aux!= to) {
        return 0;
    }
    if (from == to || from == aux || to == aux) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, int from, int to, int aux) {
    if (from == to) {
        printf("Move disk %d from %c to %c\n", n, 'A' + from, 'A' + to);
    } else if (from == aux) {
        printf("Move disk %d from %c to %c\n", n, 'A' + from, 'A' + to);
    } else {
        printf("Move disk %d from %c to %c\n", n, 'A' + from, 'A' + aux);
        printf("Move disk %d from %c to %c\n", n, 'A' + aux, 'A' + to);
        printf("Move disk %d from %c to %c\n", n, 'A' + from, 'A' + to);
    }
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        move_disk(n, from, to, aux);
        return;
    }
    hanoi(n - 1, from, aux, to);
    move_disk(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}