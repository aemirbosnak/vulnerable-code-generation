//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c: ", 'A' + i);
        if (i == n - 1)
            printf("%c\n", 'A' + i);
        else
            printf("\n");
    }
    printf("Move disk %d from %c to %c using %c\n", n, from, to, aux);
}

// Function to check if a move is valid
int is_valid_move(int n, char from, char to, char aux) {
    if (from == to)
        return 0;
    if (from == 'A' || to == 'C' || aux == 'A' || aux == 'C')
        return 0;
    return 1;
}

// Function to move n disks from from_rod to to_rod using aux_rod
void move_tower(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }
    move_tower(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    move_tower(n - 1, aux_rod, to_rod, from_rod);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n) {
    char from_rod = 'A', to_rod = 'C', aux_rod = 'B';
    int i;
    for (i = n; i >= 1; i--) {
        print_towers(n, from_rod, to_rod, aux_rod);
        move_tower(i, from_rod, to_rod, aux_rod);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\n");
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    printf("The Tower of Hanoi problem with %d disks:\n", n);
    tower_of_hanoi(n);
    return 0;
}