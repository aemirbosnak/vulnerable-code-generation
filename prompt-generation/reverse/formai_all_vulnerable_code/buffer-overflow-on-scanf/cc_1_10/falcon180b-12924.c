//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int a, int b, int c) {
    int i;

    for (i = 0; i < n; i++) {
        if (i == a) {
            printf("A: ");
        } else if (i == b) {
            printf("B: ");
        } else if (i == c) {
            printf("C: ");
        } else {
            printf("-");
        }
    }

    printf("\n");
}

// Function to check if the move is valid
int is_valid_move(int n, int from, int to, int aux) {
    if (from < 0 || from >= n || to < 0 || to >= n || aux < 0 || aux >= n) {
        return 0;
    }

    if (to == aux || from == to) {
        return 0;
    }

    return 1;
}

// Function to move the disk from one tower to another
void move_disk(int n, int from, int to, int aux) {
    if (is_valid_move(n, from, to, aux)) {
        printf("Moving disk %d from tower %d to tower %d\n", n, from, to);
        int i;
        for (i = n - 1; i >= 0; i--) {
            if (i!= from && i!= to) {
                if (i == aux) {
                    printf("Moving disk %d from tower %d to tower %d\n", i, aux, to);
                    aux = from;
                } else {
                    printf("Moving disk %d from tower %d to tower %d\n", i, aux, to);
                    aux = to;
                }
            }
        }
        printf("Disk %d has been moved to tower %d\n\n", n, to);
    } else {
        printf("Invalid move\n");
    }
}

// Function to solve the Tower of Hanoi problem recursively
void tower_of_hanoi(int n, int a, int b, int c) {
    if (n == 1) {
        move_disk(1, a, c, b);
        return;
    }

    tower_of_hanoi(n - 1, a, c, b);
    move_disk(n, a, c, b);
    tower_of_hanoi(n - 1, b, a, c);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    srand(time(NULL));
    int a = rand() % 3;
    int b = rand() % 3;
    int c = 6 - a - b;

    printf("Initial state:\n");
    print_towers(n, a, b, c);

    tower_of_hanoi(n, a, b, c);

    printf("Final state:\n");
    print_towers(n, a, b, c);

    return 0;
}