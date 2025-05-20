//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void tower_of_hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", from, to);
        return;
    }

    tower_of_hanoi(n - 1, from, aux, to);
    printf("Move disk %d from peg %c to peg %c\n", n, from, to);
    tower_of_hanoi(n - 1, aux, to, from);
}

void print_solution(int n, char from, char to, char aux, int *solution) {
    if (n == 0) {
        printf("Peg %c is empty\n", from);
        return;
    }

    print_solution(n - 1, from, aux, to, solution);
    printf("Move disk %d from peg %c to peg %c\n", n, from, to);
    solution[n - 1] = to;
    print_solution(n - 1, to, aux, from, solution);
}

void main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        exit(1);
    }

    char from = 'A';
    char to = 'C';
    char aux = 'B';

    printf("Tower of Hanoi with %d disks:\n", n);
    tower_of_hanoi(n, from, to, aux);

    printf("\nSolution:\n");
    int solution[n];
    print_solution(n, from, to, aux, solution);
}