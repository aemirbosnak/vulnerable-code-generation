//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the current state of the towers
void print_towers(int n, int a[], int c[], int b[]) {
    printf("Current state of towers:\n");
    printf("A: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\nC: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }
    printf("\nB: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

// Function to move a disk from one tower to another
void move_disk(int n, int a[], int c[], int b[], int from, int to) {
    if (n == 1) {
        printf("Move disk %d from %c to %c\n", 1, 'A', 'C');
        a[0] = 0;
        c[0] = 1;
        b[0] = 0;
        return;
    }
    move_disk(n - 1, a, b, c, from, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    a[n - 1] = 0;
    c[to] = n;
    b[0] = 0;
}

// Function to generate a random tower configuration
void generate_towers(int n, int a[], int c[], int b[]) {
    srand(time(NULL));
    for (int i = n - 1; i >= 0; i--) {
        a[i] = rand() % 3;
    }
    for (int i = 0; i < n; i++) {
        c[i] = rand() % 3;
    }
}

int main() {
    int n, choice;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    int a[n], c[n], b[n];
    generate_towers(n, a, c, b);
    print_towers(n, a, c, b);
    printf("Enter your choice:\n1. Solve the puzzle\n2. Display the current state of the towers\n");
    scanf("%d", &choice);
    if (choice == 1) {
        move_disk(n, a, b, c, 'A', 'C');
        print_towers(n, a, c, b);
        move_disk(n, a, c, b, 'C', 'B');
        print_towers(n, a, c, b);
    } else if (choice == 2) {
        print_towers(n, a, c, b);
    } else {
        printf("Invalid choice\n");
    }
    return 0;
}