//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux)
{
    int i;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("%c ", from);
    for (i = 0; i < n - 1; i++) {
        printf(" ");
    }
    printf("%c ", to);
    for (i = 0; i < n - 1; i++) {
        printf(" ");
    }
    printf("%c\n", aux);
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to)
{
    if (from < 0 || from >= n || to < 0 || to >= n || from == to) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, int from, int to, char aux)
{
    if (!is_valid_move(n, from, to)) {
        printf("Invalid move!\n");
        return;
    }
    if (from == to) {
        printf("No need to move disk %d.\n", from);
    } else if (from > to) {
        move_disk(n, from - 1, aux, to);
        printf("Move disk %d from %c to %c.\n", from, from, to);
        move_disk(n, aux, to, from - 1);
    } else {
        move_disk(n, from, aux, to);
        printf("Move disk %d from %c to %c.\n", from, from, to);
    }
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("Move disk 1 from %c to %c.\n", from, to);
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    move_disk(n, from, to, aux);
    tower_of_hanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Invalid number of disks!\n");
        return 1;
    }
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}