//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void print_solution(int disks, char from, char to, char aux)
{
    printf("Move disk %d from %c to %c using %c\n", disks, from, to, aux);
}

void tower_of_hanoi(int disks, char from, char to, char aux)
{
    if (disks == 1)
    {
        print_solution(disks, from, to, aux);
    }
    else
    {
        tower_of_hanoi(disks - 1, from, aux, to);
        print_solution(disks, from, to, aux);
        tower_of_hanoi(disks - 1, aux, to, from);
    }
}

int main()
{
    int disks;
    char from = 'A', to = 'C', aux = 'B';

    printf("Enter the number of disks: ");
    scanf("%d", &disks);

    if (disks < 1 || disks > MAX_DISKS)
    {
        printf("Invalid number of disks\n");
        return 1;
    }

    srand(time(NULL));
    int random_disks = rand() % MAX_DISKS + 1;

    if (random_disks == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
    }
    else
    {
        printf("Move %d disks from %c to %c\n", random_disks, from, to);
        tower_of_hanoi(random_disks, from, to, aux);
    }

    return 0;
}