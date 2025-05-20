//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int from, int to, int aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    printf("From tower: ");
    while (from > 0) {
        printf("%d ", from % 10);
        from /= 10;
    }
    printf("\n");
    printf("To tower: ");
    while (to > 0) {
        printf("%d ", to % 10);
        to /= 10;
    }
    printf("\n");
    printf("Auxiliary tower: ");
    while (aux > 0) {
        printf("%d ", aux % 10);
        aux /= 10;
    }
    printf("\n\n");
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to, int aux) {
    if (from == to) {
        return 0;
    }
    if (from == aux || to == aux) {
        return 0;
    }
    if (to - from > 1 && from > MAX_DISKS - aux - 1) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, int from, int to, int aux) {
    if (from > to) {
        printf("Moving disk %d from tower %d to tower %d\n", n, from, to);
        while (n > 1 && from > to) {
            move_disk(n - 1, from, aux, to);
            printf("Moving disk %d from tower %d to tower %d\n", n, from, to);
        }
        printf("Moving disk %d from tower %d to tower %d\n", n, from, to);
        from--;
        to++;
    } else {
        printf("Moving disk %d from tower %d to tower %d\n", n, from, to);
        while (n > 1 && from < to) {
            move_disk(n - 1, from, to, aux);
            printf("Moving disk %d from tower %d to tower %d\n", n, from, to);
        }
        printf("Moving disk %d from tower %d to tower %d\n", n, from, to);
        from++;
        to--;
    }
}

// Function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Moving disk %d from tower %d to tower %d\n", n, from, to);
        from--;
        to++;
        return;
    }
    move_disk(n, from, to, aux);
}

// Main function
int main() {
    int n, from, to, aux;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    srand(time(NULL));
    from = rand() % 3;
    to = rand() % 3;
    aux = (from + to) % 3;
    printf("Initial state:\n");
    print_towers(n, from, to, aux);
    solve_tower_of_hanoi(n, from, to, aux);
    printf("Final state:\n");
    print_towers(n, to, from, aux);
    return 0;
}