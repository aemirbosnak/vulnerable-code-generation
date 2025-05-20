//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(char tower1[], char tower2[], char tower3[], int top) {
    printf("Current state of towers:\n");
    printf("Tower 1: ");
    for (int i = top; i >= 0; i--) {
        printf("%c ", tower1[i]);
    }
    printf("\nTower 2: ");
    for (int i = top; i >= 0; i--) {
        printf("%c ", tower2[i]);
    }
    printf("\nTower 3: ");
    for (int i = top; i >= 0; i--) {
        printf("%c ", tower3[i]);
    }
}

// Function to move n disks from source to destination using an auxiliary tower
void hanoi(char source[], char destination[], char auxiliary[], int n) {
    if (n == 1) {
        printf("Move disk 1 from %s to %s\n", source, destination);
        return;
    }
    hanoi(source, auxiliary, destination, n - 1);
    printf("Move disk %d from %s to %s\n", n, source, destination);
    hanoi(auxiliary, destination, source, n - 1);
}

// Function to solve the Tower of Hanoi problem with the given number of disks
void solve_tower_of_hanoi(int n) {
    char tower1[MAX_DISKS], tower2[MAX_DISKS], tower3[MAX_DISKS];

    // Initialize the towers with disks
    for (int i = n; i >= 1; i--) {
        tower1[i - 1] = 'A' + (n - i);
    }
    for (int i = 0; i < n; i++) {
        tower2[i] = '\0';
    }
    for (int i = 0; i < n; i++) {
        tower3[i] = '\0';
    }

    // Print the initial state of the towers
    print_towers(tower1, tower2, tower3, n);

    // Solve the Tower of Hanoi problem
    hanoi(tower1, tower3, tower2, n);

    // Print the final state of the towers
    print_towers(tower1, tower2, tower3, n);
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