//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(int n, char tower_from, char tower_to, char tower_aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("Move disk %d from %c to %c\n", n, tower_from, tower_to);
}

// Function to check if a move is valid
int is_valid_move(int n, char from_tower, char to_tower, char aux_tower) {
    if (from_tower == to_tower) {
        return 0;
    }
    if (from_tower == aux_tower || to_tower == aux_tower) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return is_valid_move(n - 1, from_tower, aux_tower, to_tower);
}

// Function to move n disks from source to destination using an auxiliary tower
void move_disks(int n, char source, char destination, char auxiliary) {
    if (is_valid_move(n, source, destination, auxiliary)) {
        printf("Moving disk %d from %c to %c using %c\n", n, source, destination, auxiliary);
        if (n == 1) {
            printf("Move completed!\n");
        } else {
            move_disks(n - 1, source, auxiliary, destination);
            printf("Move disk %d from %c to %c\n", n, source, destination);
            move_disks(n - 1, auxiliary, destination, source);
        }
    } else {
        printf("Invalid move!\n");
    }
}

// Main function to get user input and call the move_disks function
int main() {
    int n, from_tower, to_tower, aux_tower;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Enter the towers to use (A, B, C): ");
    scanf(" %c %c %c", &from_tower, &to_tower, &aux_tower);
    move_disks(n, from_tower, to_tower, aux_tower);
    return 0;
}