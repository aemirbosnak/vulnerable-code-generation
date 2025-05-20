//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("Move disk %d from %c to %c\n", n, from, to);
        else if (i == 1)
            printf("Move disk %d from %c to %c\n", n - 1, from, to);
        else
            printf("Move disk %d from %c to %c\n", n - i, from, to);
    }
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to) {
    if (from >= 0 && to >= 0 && from < n && to < n && from!= to)
        return 1;
    else
        return 0;
}

// Function to move n disks from source to destination using the auxiliary tower
void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk %d from %c to %c\n", n, source, destination);
        return;
    }
    tower_of_hanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    tower_of_hanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of disks\n");
        return 0;
    }

    char from = 'A', to = 'C', aux = 'B';

    printf("Initial state:\n");
    print_towers(n, from, to, aux);

    tower_of_hanoi(n, from, to, aux);

    printf("\nFinal state:\n");
    print_towers(n, from, to, aux);

    return 0;
}