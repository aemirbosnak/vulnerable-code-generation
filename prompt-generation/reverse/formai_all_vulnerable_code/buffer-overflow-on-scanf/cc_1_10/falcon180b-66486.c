//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Function to print the current state of the towers */
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", 'A' + i);
    }
    printf("-> %c\n", to);
}

/* Function to check if a move is valid */
int is_valid_move(int n, char from, char to, char aux) {
    if (from == 'A' || from == 'C') {
        if (to == 'B' && aux!= 'A' && aux!= 'B' && aux!= 'C') {
            return 1;
        } else if (to == 'C' && aux!= 'A' && aux!= 'B' && aux!= 'C') {
            return 1;
        }
    } else if (from == 'B') {
        if (to == 'A' && aux!= 'A' && aux!= 'B' && aux!= 'C') {
            return 1;
        } else if (to == 'C' && aux!= 'A' && aux!= 'B' && aux!= 'C') {
            return 1;
        }
    }
    return 0;
}

/* Function to move a disk from one tower to another */
void move_disk(int n, char from, char to, char aux) {
    printf("Move disk %d from %c to %c\n", n, from, to);
}

/* Recursive function to solve the Tower of Hanoi problem */
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
    if (n < 1 || n > MAX) {
        printf("Invalid number of disks\n");
        return 1;
    }
    printf("Solving Tower of Hanoi problem with %d disks...\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}