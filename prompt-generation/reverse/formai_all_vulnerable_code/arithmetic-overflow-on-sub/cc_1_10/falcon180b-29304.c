//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int from, int to, int aux, char* towers[3]) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", towers[0][i]);
    }
    printf(" -> ");
    for (i = 0; i < n; i++) {
        printf("%c ", towers[1][i]);
    }
    printf(" -> ");
    for (i = 0; i < n; i++) {
        printf("%c ", towers[2][i]);
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to, int aux, char* towers[3]) {
    if (from < 0 || from >= n || to < 0 || to >= n || aux < 0 || aux >= n) {
        return 0;
    }
    if (from == to && aux!= from) {
        return 0;
    }
    if (from == to && aux == from) {
        return 1;
    }
    if (from == to && aux == 6 - from - to) {
        return 1;
    }
    if (from!= to && aux == 6 - from - to) {
        return 1;
    }
    return 0;
}

// Function to move a disk from one tower to another
void move_disk(int n, int from, int to, int aux, char* towers[3]) {
    int i;
    for (i = n - 1; i >= 0; i--) {
        if (towers[from][i]!= '\0') {
            towers[from][i] = '\0';
            towers[to][i] = towers[from][i - 1];
            towers[aux][i] = towers[to][i - 1];
            towers[from][i - 1] = '\0';
            break;
        }
    }
}

// Function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(int n, int from, int to, int aux, char* towers[3]) {
    if (n == 1) {
        move_disk(n, from, to, aux, towers);
        print_towers(n, from, to, aux, towers);
        return;
    }
    solve_tower_of_hanoi(n - 1, from, aux, to, towers);
    move_disk(n, from, to, aux, towers);
    solve_tower_of_hanoi(n - 1, aux, to, from, towers);
}

// Main function to start the program
int main() {
    int n, i;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    char towers[3][MAX_DISKS];
    for (i = 0; i < 3; i++) {
        towers[i][0] = 'A';
        towers[i][n - 1] = '\0';
    }
    solve_tower_of_hanoi(n, 0, 2, 1, towers);
    return 0;
}