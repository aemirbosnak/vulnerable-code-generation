//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%c ", 'A' + i);
    }

    printf(" -> ");

    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%c\n", to);
        } else {
            printf("%c ", 'A' + i);
        }
    }
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to)
{
    if (from >= 0 && from < n && to >= 0 && to < n && from!= to) {
        return 1;
    }

    return 0;
}

// Function to move a disk from one tower to another
void move_disk(int n, int from, int to)
{
    char aux;

    if (from > to) {
        aux = from;
        from = to;
        to = aux;
    }

    while (from > to) {
        printf("Move disk %d from tower %c to tower %c\n", n, 'A' + from, 'A' + to);
        from--;
        to++;
    }

    printf("Move disk %d from tower %c to tower %c\n", n, 'A' + from, 'A' + to);
}

// Function to solve the Tower of Hanoi problem recursively
void hanoi(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("Move disk 1 from tower %c to tower %c\n", from, to);
        return;
    }

    hanoi(n - 1, from, aux, to);

    move_disk(n, from, to);

    hanoi(n - 1, aux, to, from);
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    printf("Solving the Tower of Hanoi problem with %d disks:\n", n);
    hanoi(n, 'A', 'C', 'B');

    return 0;
}