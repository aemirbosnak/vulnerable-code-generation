//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int from, int to, int aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from)
            printf(" %d ", n - 1);
        else if (i == to)
            printf(" %d ", 0);
        else if (i == aux)
            printf(" %d ", n - 1 - from + to);
        else
            printf(" %d ", 0);
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to, int aux) {
    if (from < 0 || from >= n || to < 0 || to >= n || aux < 0 || aux >= n)
        return 0;
    if (to == aux || from == to)
        return 0;
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, int from, int to, int aux) {
    printf("Moving disk %d from tower %d to tower %d\n", n - 1, from, to);
    print_towers(n, from, to, aux);
}

// Function to solve the Tower of Hanoi problem recursively
void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        move_disk(n, from, to, aux);
        return;
    }
    hanoi(n - 1, from, aux, to);
    move_disk(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

// Function to get user input for the number of disks
int get_input() {
    int n;
    printf("Enter the number of disks (1-10): ");
    scanf("%d", &n);
    while (n < 1 || n > MAX_DISKS) {
        printf("Invalid input. Enter the number of disks (1-10): ");
        scanf("%d", &n);
    }
    return n;
}

int main() {
    int n, start_time, end_time, elapsed_time;
    srand(time(NULL));
    n = get_input();
    printf("Solving the Tower of Hanoi problem with %d disks...\n", n);
    start_time = clock();
    hanoi(n, 0, 2, 1);
    end_time = clock();
    elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken: %d seconds\n", elapsed_time);
    return 0;
}