//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(int n, int a, int b, int c) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d ", i);
    }
    printf(" -> A\n");
    for (i = 0; i < n - 1; ++i) {
        printf("%d ", i);
    }
    printf(" -> B\n");
    for (i = 0; i < n - 1; ++i) {
        printf("%d ", i);
    }
    printf(" -> C\n");
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to, int temp) {
    if (from < 0 || from >= n || to < 0 || to >= n || temp < 0 || temp >= n) {
        return 0;
    }
    if (from == to) {
        return 0;
    }
    if (from == temp) {
        return 0;
    }
    if (to == temp) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, int from, int to, int temp) {
    int i;
    for (i = n - 1; i >= 0; --i) {
        if (i!= from && i!= to && i!= temp) {
            printf("%d -> %d\n", from, to);
            break;
        }
    }
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, int a, int b, int c) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", a, c);
        return;
    }
    hanoi(n - 1, a, c, b);
    move_disk(n, a, c, b);
    hanoi(n - 1, b, a, c);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    hanoi(n, 'A', 'B', 'C');
    return 0;
}