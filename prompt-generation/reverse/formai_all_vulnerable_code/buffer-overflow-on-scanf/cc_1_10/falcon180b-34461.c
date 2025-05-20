//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the towers
void print_towers(char towers[MAX][MAX], int n, int from, int to, int aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from || i == to || i == aux) {
            printf(" %c ", towers[i][0]);
        } else {
            printf(" %c ", '-');
        }
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(char towers[MAX][MAX], int n, int from, int to) {
    if (from >= 0 && from < n && to >= 0 && to < n && towers[from][0]!= '-' && towers[to] == '-') {
        return 1;
    }
    return 0;
}

// Function to move a disk from one tower to another
void move_disk(char towers[MAX][MAX], int n, int from, int to) {
    int i;
    char temp = towers[from][0];
    for (i = from; i >= to; i--) {
        towers[i][0] = towers[i - 1][0];
    }
    towers[to][0] = temp;
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char towers[MAX][MAX], int from, int to, int aux) {
    if (n == 1) {
        move_disk(towers, n, from, to);
        print_towers(towers, n, from, to, aux);
        return;
    }
    hanoi(n - 1, towers, from, aux, to);
    move_disk(towers, n, from, to);
    hanoi(n - 1, towers, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    char towers[MAX][MAX];
    int i;
    for (i = 0; i < n; i++) {
        towers[i][0] = 'A' + i;
    }
    towers[n - 1][0] = '-';
    hanoi(n, towers, 0, 2, 1);
    return 0;
}