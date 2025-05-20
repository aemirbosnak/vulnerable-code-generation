//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the disks on the specified rod
void print_disks(int disks[], int n) {
    printf("Rod %d: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", disks[i]);
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int disks[], int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || to == from) {
        return 0;
    }
    if (disks[to]!= 0 && disks[to]!= disks[from]) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one rod to another
void move_disk(int disks[], int n, int from, int to) {
    int temp = disks[from];
    disks[from] = 0;
    disks[to] = temp;
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int disks[], int n, int from, int to, int aux) {
    if (n == 1) {
        move_disk(disks, n, from, to);
        return;
    }
    tower_of_hanoi(disks, n - 1, from, aux, to);
    tower_of_hanoi(disks, 1, from, to, aux);
    tower_of_hanoi(disks, n - 1, aux, to, from);
}

int main() {
    int disks[MAX_DISKS];
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Initial state:\n");
    for (int i = n; i >= 1; i--) {
        disks[n - i] = i;
    }
    print_disks(disks, n);

    tower_of_hanoi(disks, n, 0, 2, 1);

    printf("Final state:\n");
    print_disks(disks, n);

    return 0;
}