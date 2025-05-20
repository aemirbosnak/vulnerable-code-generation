//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the tower
void print_tower(int n, char from, char to, char aux)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%c ", 'A' + i);
    printf("\n");
    printf("Move disk %d from %c to %c\n", n, from, to);
}

// Function to check if the move is valid
int is_valid(int n, int from, int to)
{
    if (from < 0 || from >= n || to < 0 || to >= n || from == to)
        return 0;
    else
        return 1;
}

// Function to move the disk
void move_disk(int n, int from, int to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    move_disk(n - 1, from, aux, to);
    print_tower(n, from, to, aux);
    move_disk(n - 1, aux, to, from);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n)
{
    char from = 'A', to = 'C', aux = 'B';

    printf("Tower of Hanoi - %d disks\n", n);
    move_disk(n, from, to, aux);
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
        printf("Invalid number of disks\n");
    else
        tower_of_hanoi(n);

    return 0;
}