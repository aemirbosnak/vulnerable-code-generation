//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: light-weight
#include <stdio.h>

#define MAX_DISKS 100 // Maximum number of disks
#define STACK_SIZE 200 // Maximum size of the stack

// Function to print the disks in a tower
void print_tower(int tower[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

// Function to move n disks from source to destination using an auxiliary tower
void hanoi(int n, char source, char dest, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }

    hanoi(n - 1, source, aux, dest); // Move n-1 disks from source to aux

    printf("Move disk %d from %c to %c\n", n, source, dest);

    hanoi(n - 1, aux, dest, source); // Move n-1 disks from aux to dest
}

// Function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(int n) {
    int tower[MAX_DISKS];

    // Initialize the tower with n disks
    for (int i = n; i >= 1; i--) {
        tower[n - i] = i;
    }

    printf("Initial tower of disks:\n");
    print_tower(tower, n);

    hanoi(n, 'A', 'C', 'B'); // Move n disks from A to C using B as an auxiliary tower

    printf("\nFinal tower of disks:\n");
    print_tower(tower, n);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    solve_tower_of_hanoi(n);

    return 0;
}