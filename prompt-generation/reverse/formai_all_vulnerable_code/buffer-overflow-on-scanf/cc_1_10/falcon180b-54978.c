//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//Function to print the tower
void print_tower(int n, char from, char to, char aux)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%c ", 'A'+i);
    }
    printf("\n");

    int gap = (n-1-i);
    int j;
    for(j=0; j<gap; j++)
    {
        printf(" ");
    }
    printf("%c ", from);

    for(j=0; j<gap; j++)
    {
        printf(" ");
    }
    printf("%c\n", to);
}

//Function to check if move is valid or not
int is_valid_move(int n, char from, char to)
{
    if(from == 'A' && to == 'C')
    {
        return 1;
    }
    else if(from == 'A' && to == 'B')
    {
        return 1;
    }
    else if(from == 'B' && to == 'C')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Function to move disk from one rod to another
void move_disk(int n, char from, char to, char aux)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    move_disk(n-1, from, aux, to);

    printf("Move disk %d from %c to %c\n", n, from, to);

    move_disk(n-1, aux, to, from);
}

//Function to solve the tower of hanoi problem
void tower_of_hanoi(int n, char from, char to, char aux)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    tower_of_hanoi(n-1, from, aux, to);

    printf("Move disk %d from %c to %c\n", n, from, to);

    tower_of_hanoi(n-1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if(n < 1 || n > MAX)
    {
        printf("Invalid number of disks\n");
        return 0;
    }

    char from = 'A';
    char to = 'C';
    char aux = 'B';

    printf("Initial position:\n");
    print_tower(n, from, to, aux);

    printf("Solving the problem...\n");
    tower_of_hanoi(n, from, to, aux);

    printf("Final position:\n");
    print_tower(n, from, to, aux);

    return 0;
}