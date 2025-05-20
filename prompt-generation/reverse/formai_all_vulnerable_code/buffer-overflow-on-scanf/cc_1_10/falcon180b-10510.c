//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int from, int to, int aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from)
            printf("->");
        else if (i == to)
            printf("<-");
        else if (i == aux)
            printf("AUX");
        else
            printf("   ");
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || from == to)
        return 0;
    if (from == 0 && to == n - 1)
        return 0;
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, int from, int to, int aux) {
    printf("Moving disk %d from tower %d to tower %d\n", n - 1, from, to);
    print_towers(n, from, to, aux);
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        move_disk(n, from, to, aux);
        return;
    }
    hanoi(n - 1, from, aux, to);
    move_disk(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n, from, to, aux;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Initialize the towers
    int towers[MAX_DISKS][3] = {0};

    // Set the initial positions of the towers
    from = 0;
    to = n - 1;
    aux = 2;

    // Solve the Tower of Hanoi problem
    hanoi(n, from, to, aux);

    // Print the final state of the towers
    printf("Final state:\n");
    for (int i = 0; i < n; i++) {
        printf("Tower %d: ", i);
        for (int j = 0; j < 3; j++) {
            if (towers[i][j]!= 0)
                printf("%d ", towers[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }

    return 0;
}