//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

void move_disk(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
    }
    else
    {
        move_disk(n - 1, from_rod, aux_rod, to_rod);
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        move_disk(n - 1, aux_rod, to_rod, from_rod);
    }
}

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        move_disk(n, from_rod, to_rod, aux_rod);
    }
    else
    {
        tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
        move_disk(n, from_rod, to_rod, aux_rod);
        tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
    }
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DISKS)
    {
        printf("Invalid number of disks.\n");
        return 1;
    }

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}