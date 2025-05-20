//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current configuration of the towers
void print_towers(char towers[MAX][MAX], int n, int from, int to, int aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from || i == to || i == aux) {
            printf("%c ", 'A' + i);
        } else {
            printf("%c ", 'A' + i);
        }
    }
    printf("\n");
}

// Function to check if the move is valid
int is_valid_move(char towers[MAX][MAX], int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || from == to) {
        return 0;
    }
    if (towers[from][to]!= '\0') {
        return 0;
    }
    return 1;
}

// Function to move the disk from one tower to another
void move_disk(char towers[MAX][MAX], int n, int from, int to, int aux) {
    towers[to][aux] = towers[from][aux];
    towers[from][aux] = '\0';
}

// Function to solve the Tower of Hanoi problem
void hanoi(char towers[MAX][MAX], int n, int from, int to, int aux) {
    if (n == 1) {
        move_disk(towers, n, from, to, aux);
        return;
    }
    hanoi(towers, n - 1, from, aux, to);
    move_disk(towers, n, from, to, aux);
    hanoi(towers, n - 1, aux, to, from);
}

// Main function to run the program
int main() {
    int n, i;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    char towers[MAX][MAX];
    for (i = 0; i < n; i++) {
        towers[0][i] = 'A' + i;
    }
    hanoi(towers, n, 0, 2, 1);
    print_towers(towers, n, 0, 2, 1);
    return 0;
}