//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int a[], int c[], int b[]) {
    printf("Current state:\n");
    printf("A: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("C: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
    printf("B: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

// Function to check if the move is valid
int is_valid_move(int n, int from, int to, int c[], int b[]) {
    if (from < 0 || from >= n || to < 0 || to >= n) {
        return 0;
    }
    if (from == to) {
        return 0;
    }
    if (from == 0 && to == 2) {
        return 0;
    }
    if (c[to]!= -1 || b[to]!= -1) {
        return 0;
    }
    return 1;
}

// Function to move the disk
void move_disk(int n, int from, int to, int a[], int c[], int b[]) {
    if (from == 0) {
        printf("Move disk 1 from A to C\n");
    } else if (from == 2) {
        printf("Move disk 1 from C to B\n");
    } else {
        printf("Move disk %d from A to C\n", from + 1);
    }
    int temp = a[from];
    a[from] = -1;
    c[to] = temp;
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, int a[], int c[], int b[]) {
    int moves = 0;
    srand(time(NULL));
    int random_moves = rand() % (2 * n - 1) + 1;
    printf("Solving Tower of Hanoi with %d disks and %d moves\n", n, random_moves);
    for (int i = n - 1; i >= 0; i--) {
        a[0] = i;
        while (a[0]!= 0) {
            int to = rand() % 3;
            if (is_valid_move(n, a[0], to, c, b)) {
                move_disk(n, a[0], to, a, c, b);
                a[0] = to;
                moves++;
            }
        }
    }
    printf("Total moves: %d\n", moves);
    print_towers(n, a, c, b);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }
    int a[MAX_DISKS], c[MAX_DISKS], b[MAX_DISKS];
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    tower_of_hanoi(n, a, c, b);
    return 0;
}