//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define MAX_MOVES 100

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux)
{
    int i;
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf("%c: ", 'A' + i);
    }
    printf("\n");
    printf("%c -> %c -> %c\n", from, to, aux);
}

// Function to check if a move is valid or not
int is_valid_move(int n, char from, char to, char aux)
{
    if(from == to)
        return 0;
    else if(from == aux)
        return 0;
    else if(to == aux)
        return 0;
    else if(n == 1)
        return 1;
    else
        return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, char from, char to, char aux)
{
    printf("%c -> %c\n", from, to);
    if(n > 1)
    {
        move_disk(n-1, aux, from, to);
    }
}

// Function to solve the Tower of Hanoi problem recursively
void hanoi(int n, char from, char to, char aux)
{
    int i;
    if(n == 1)
    {
        printf("%c -> %c\n", from, to);
        move_disk(1, from, to, aux);
    }
    else
    {
        for(i=0; i<n-1; i++)
        {
            hanoi(n-1, from, aux, to);
            move_disk(n, from, to, aux);
        }
        hanoi(n-1, aux, to, from);
    }
}

int main()
{
    int n, i;
    char from, to, aux;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    srand(time(NULL));
    from = 'A' + rand() % 3;
    to = 'C' - from + 1;
    aux = 'B' - from + 1;
    printf("Tower of Hanoi with %d disks\n", n);
    hanoi(n, from, to, aux);
    return 0;
}