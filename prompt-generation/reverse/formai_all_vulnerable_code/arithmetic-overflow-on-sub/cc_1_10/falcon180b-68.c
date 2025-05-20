//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10
#define STACK_SIZE 100

// Function to display the current state of the towers
void display_towers(int n, int towers[3][MAX_DISKS], char from_rod, char to_rod, char aux_rod) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%c: ", 'A' + i);
        for (int j = 0; j < n; j++) {
            if (towers[i][j] == 0) {
                printf(" ");
            } else {
                printf("%d ", towers[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int is_valid_move(int n, int towers[3][MAX_DISKS], int from, int to, int aux) {
    // Check if the disk can be moved
    if (towers[from][n-1] > towers[to][n-1]) {
        return 0;
    }

    // Check if the auxiliary tower is empty
    if (towers[aux][n-1]!= 0) {
        return 0;
    }

    // Check if the destination tower is not full
    if (towers[to][n-1] == MAX_DISKS-1) {
        return 0;
    }

    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, int towers[3][MAX_DISKS], int from, int to, int aux) {
    towers[to][n-1] = towers[from][n-1];
    towers[from][n-1] = 0;
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, int towers[3][MAX_DISKS], char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        move_disk(n, towers, from_rod, to_rod, aux_rod);
        display_towers(n, towers, from_rod, to_rod, aux_rod);
        return;
    }

    hanoi(n-1, towers, from_rod, aux_rod, to_rod);

    if (is_valid_move(n, towers, from_rod, to_rod, aux_rod)) {
        move_disk(n, towers, from_rod, to_rod, aux_rod);
    }

    hanoi(n-1, towers, aux_rod, to_rod, from_rod);
}

// Main function
int main() {
    int towers[3][MAX_DISKS] = {{0}, {0}, {0}};
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    hanoi(n, towers, 'A', 'C', 'B');

    return 0;
}