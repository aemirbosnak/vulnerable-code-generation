//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the towers
void print_towers(int n, char from_rod, char to_rod, char aux_rod) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", 'A' + i);
    }
    printf(" %c -> %c\n", from_rod, to_rod);
    printf("%c ", aux_rod);
    for (i = n - 1; i >= 0; i--) {
        printf("%c ", 'A' + i);
    }
}

// Recursive function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Function to get a valid input for the number of disks
int get_valid_input(int min, int max) {
    int input;
    while (1) {
        printf("Enter the number of disks (%d-%d): ", min, max);
        if (scanf("%d", &input)!= 1 || input < min || input > max) {
            printf("Invalid input. Please try again.\n");
        } else {
            return input;
        }
    }
}

int main() {
    int n;

    // Get the number of disks from the user
    n = get_valid_input(1, MAX);

    // Solve the Tower of Hanoi problem
    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}