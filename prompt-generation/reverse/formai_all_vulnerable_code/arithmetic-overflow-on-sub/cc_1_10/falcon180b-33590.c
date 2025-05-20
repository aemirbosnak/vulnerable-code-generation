//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 5

// Function to print the towers
void print_tower(int tower[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

// Function to check if the move is valid
int is_valid_move(int from, int to, int n) {
    if (from < 0 || to < 0 || from >= n || to >= n) {
        return 0;
    }
    if (from == to) {
        return 0;
    }
    if (from == 0 && to == n - 1) {
        return 1;
    }
    return 0;
}

// Function to move the disk from one tower to another
void move_disk(int tower[], int from, int to) {
    int top = tower[from];
    tower[from] = 0;
    tower[to] = top;
}

// Function to solve the Tower of Hanoi problem
int solve_hanoi(int tower[], int n, int from, int to, int aux) {
    if (n == 1) {
        move_disk(tower, from, to);
        return 1;
    }
    int steps = 0;
    int i;
    for (i = 0; i < n - 1; i++) {
        if (is_valid_move(from, i, n)) {
            move_disk(tower, from, i);
            steps += solve_hanoi(tower, n - 1, from, to, i);
            move_disk(tower, i, from);
        }
    }
    return steps;
}

// Main function
int main() {
    int tower[LEN];
    int n, steps;
    srand(time(NULL));
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower[0] = n;
    tower[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        tower[i] = rand() % (n - i) + 1;
    }
    printf("Initial state:\n");
    print_tower(tower, n);
    steps = solve_hanoi(tower, n, 0, n - 1, 2);
    printf("Final state in %d steps:\n", steps);
    print_tower(tower, n);
    return 0;
}