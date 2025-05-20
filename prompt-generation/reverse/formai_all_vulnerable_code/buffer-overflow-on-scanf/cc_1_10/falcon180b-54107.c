//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: portable
#include <stdio.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    for (int i = 0; i < n; ++i) {
        printf("%c", 'A' + i);
    }
    printf(" -> ");
    for (int i = 0; i < n; ++i) {
        printf("%c", 'A' + i);
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || from == to) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, int from, int to, char aux) {
    if (!is_valid_move(n, from, to)) {
        printf("Invalid move.\n");
        return;
    }
    if (from == to) {
        printf("No need to move disk %d.\n", from + 1);
        return;
    }
    if (from == 0 && to == n - 1) {
        printf("Congratulations! You solved the puzzle in %d moves.\n", n - 1);
        return;
    }
    if (from > to) {
        move_disk(n, from - 1, aux, to);
        move_disk(n, aux, to, from);
    } else {
        move_disk(n, from, aux, to);
    }
}

// Function to solve the Tower of Hanoi puzzle
void solve_tower_of_hanoi(int n) {
    char from = 'A', to = 'C', aux = 'B';
    printf("Solving the Tower of Hanoi puzzle with %d disks:\n", n);
    for (int i = n; i > 0; --i) {
        move_disk(n, from, to, aux);
        print_towers(n, from, to, aux);
    }
}

int main() {
    int n;
    printf("Enter the number of disks (1 to %d): ", MAX_DISKS);
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    solve_tower_of_hanoi(n);
    return 0;
}