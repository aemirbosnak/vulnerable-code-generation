//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the disks on the peg
void print_disks(int peg, int n) {
    int i;
    for(i = n; i >= 1; i--) {
        printf(" ");
    }
    printf("|%c|", 'A' + peg - 1);
    for(i = 1; i <= n; i++) {
        printf(" ");
    }
    printf("\n");
}

// Function to move n disks from source peg to destination peg
void move_disks(int n, char source, char destination, char auxiliary) {
    if(n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", source, destination);
        return;
    }
    move_disks(n - 1, source, auxiliary, destination);
    printf("Move disk %d from peg %c to peg %c\n", n, source, destination);
    move_disks(n - 1, auxiliary, destination, source);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    if(n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", source, destination);
        return;
    }
    tower_of_hanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from peg %c to peg %c\n", n, source, destination);
    tower_of_hanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if(n <= 0 || n > MAX) {
        printf("Invalid number of disks.\n");
        return 0;
    }

    printf("Initial state:\n");
    print_disks(1, n);

    tower_of_hanoi(n, 'A', 'C', 'B');

    printf("\nFinal state:\n");
    print_disks(1, n);

    return 0;
}