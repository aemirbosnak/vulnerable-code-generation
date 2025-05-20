//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the towers
void print_towers(int n, char from_rod, char to_rod, char aux_rod) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("%c: ", from_rod);
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%c ", '.');
        } else {
            printf("%c ", '*');
        }
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("%c: ", to_rod);
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%c ", '.');
        } else {
            printf("%c ", '*');
        }
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int n, int from_rod, int to_rod, int aux_rod) {
    if (from_rod < 0 || from_rod >= n || to_rod < 0 || to_rod >= n || aux_rod < 0 || aux_rod >= n) {
        return 0;
    }
    if (from_rod == to_rod) {
        return 0;
    }
    if (from_rod == aux_rod || to_rod == aux_rod) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one rod to another
void move_disk(int n, int from_rod, int to_rod, int aux_rod) {
    int i;
    for (i = n - 1; i >= 0; i--) {
        if (i!= from_rod && i!= to_rod && i!= aux_rod) {
            printf("%c -> %c\n", from_rod, to_rod);
            break;
        }
    }
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        move_disk(n, from_rod, to_rod, aux_rod);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    move_disk(n, from_rod, to_rod, aux_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Main function
int main() {
    int n, i;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}