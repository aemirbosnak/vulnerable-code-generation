//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the current state of the tower
void print_tower(int n, char from_rod, char to_rod, char aux_rod) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == 0) {
            printf("%c: ", from_rod);
        } else if (i == n - 1) {
            printf("%c: ", to_rod);
        } else {
            printf("%c: ", 'A' + i);
        }
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int n, char from_rod, char to_rod, char aux_rod) {
    if (from_rod == to_rod || from_rod == aux_rod || to_rod == aux_rod) {
        return 0;
    }
    if (from_rod == 'A' && to_rod == 'C' && aux_rod == 'B') {
        return 0;
    }
    if (from_rod == 'B' && to_rod == 'C' && aux_rod == 'A') {
        return 0;
    }
    if (from_rod == 'C' && to_rod == 'A' && aux_rod == 'B') {
        return 0;
    }
    return 1;
}

// Function to move a disk from one rod to another
void move_disk(int n, char from_rod, char to_rod, char aux_rod) {
    printf("Moving disk from %c to %c using %c\n", from_rod, to_rod, aux_rod);
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        move_disk(n, from_rod, to_rod, aux_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    move_disk(n, from_rod, to_rod, aux_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }
    hanoi(n, 'A', 'C', 'B');
    return 0;
}