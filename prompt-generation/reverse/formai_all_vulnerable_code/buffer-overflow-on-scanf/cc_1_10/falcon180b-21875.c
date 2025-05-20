//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

// Function to print the tower of Hanoi
void print_tower(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", from);
        from++;
    }
    printf(" -> %c\n", to);
}

// Function to check if a move is valid
int is_valid_move(int n, char from, char to, char aux) {
    // Base case
    if (n == 1) {
        return 1;
    }

    // Check if the disk can be moved from the source rod
    if (from == 'A' || from == 'C') {
        return 0;
    }

    // Check if the destination rod is empty or has a larger disk
    if (to == 'B' && n > 1) {
        return 0;
    }

    // Check if the auxiliary rod is not being used
    if (aux!= 'B' && aux!= 'C') {
        return 0;
    }

    // Check if the disk can be placed on the destination rod
    if (n > 1 && to == 'A' && aux == 'B') {
        return 0;
    }

    return 1;
}

// Function to move a disk from one rod to another
void move_disk(int n, char from, char to, char aux) {
    printf("%c -> %c\n", from, to);
    if (n > 1) {
        move_disk(n - 1, aux, from, to);
    }
}

// Function to solve the tower of Hanoi problem recursively
void solve_tower(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("%c -> %c\n", from, to);
        return;
    }

    if (is_valid_move(n, from, to, aux)) {
        move_disk(n, from, to, aux);
    } else {
        char temp = aux;
        aux = from;
        from = to;
        to = temp;
        solve_tower(n - 1, from, aux, to);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    printf("Solving the tower of Hanoi problem with %d disks:\n", n);
    solve_tower(n, 'A', 'B', 'C');

    return 0;
}