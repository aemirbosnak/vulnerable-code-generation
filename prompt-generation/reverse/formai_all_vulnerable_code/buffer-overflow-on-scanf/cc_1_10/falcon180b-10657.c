//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the tower
void print_tower(int n, char from, char to, char aux)
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
int is_valid_move(int n, int from, int to, int aux)
{
    // Check if the disk can be moved
    if (from < 0 || to < 0 || aux < 0 || from >= n || to >= n || aux >= n) {
        return 0;
    }

    // Check if the destination rod is empty
    if (to!= -1 && aux!= -1 && to == aux) {
        return 0;
    }

    // Check if the source rod is not empty
    if (from == -1) {
        return 0;
    }

    return 1;
}

// Function to move a disk from one rod to another
void move_disk(int n, int from, int to, int aux)
{
    int temp = from;

    while (from!= to) {
        from = temp;
        temp = aux;
        aux = from;
    }

    from = -1;
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        move_disk(n, from, to, aux);
        print_tower(n, from, to, aux);
    } else {
        tower_of_hanoi(n - 1, from, aux, to);
        printf("Move disk %d from rod %c to rod %c\n", n, from, to);
        move_disk(n, from, to, aux);
        print_tower(n, from, to, aux);
        tower_of_hanoi(n - 1, aux, to, from);
    }
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}