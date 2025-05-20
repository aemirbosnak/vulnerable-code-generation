//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define N 4

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux)
{
    int i, j;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("%c -> ", from);
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%c\n", to);
        } else {
            printf("%c ", to);
        }
        to++;
    }
    printf("\n");
}

// Function to check if a move is valid or not
int is_valid_move(int n, int from, int to, int aux)
{
    if (from < 0 || from >= n || to < 0 || to >= n || aux < 0 || aux >= n) {
        return 0;
    }
    if (to == aux || to == from - 1 || to == from + 1) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, int from, int to, int aux)
{
    if (from == to) {
        printf("Move disk %d from %c to %c\n", n, from, to);
    } else if (from > to) {
        move_disk(n, from, aux, to);
        move_disk(n, aux, to, from);
        printf("Move disk %d from %c to %c\n", n, from, to);
    } else {
        move_disk(n, from, aux, to);
        move_disk(n, to, aux, from);
        printf("Move disk %d from %c to %c\n", n, from, to);
    }
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    move_disk(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > N) {
        printf("Invalid number of disks!\n");
        return 1;
    }
    printf("Solving Tower of Hanoi problem with %d disks...\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}