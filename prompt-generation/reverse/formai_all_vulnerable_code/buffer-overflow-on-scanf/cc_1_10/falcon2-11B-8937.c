//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Function to move disk from one peg to another
void moveDisk(int from_peg, int to_peg, int n)
{
    if (n == 1)
    {
        printf("Move disk 1 from peg %d to peg %d\n", from_peg, to_peg);
        return;
    }
    
    moveDisk(from_peg, (from_peg - 1) % 3, n - 1);
    printf("Move disk %d from peg %d to peg %d\n", n, from_peg, to_peg);
    moveDisk((to_peg + 1) % 3, to_peg, n - 1);
}

// Function to solve the Tower of Hanoi problem
void solveHanoi(int n)
{
    int from_peg = 0;
    int to_peg = 1;
    int aux_peg = 2;

    printf("Tower of Hanoi problem with %d disks\n", n);
    printf("Starting position:\n");
    for (int i = 1; i <= n; i++)
        printf("Peg %d: Disk %d\n", i, i);

    moveDisk(from_peg, aux_peg, n);
    moveDisk(from_peg, to_peg, n - 1);
    moveDisk(aux_peg, to_peg, n - 1);

    printf("Final position:\n");
    for (int i = 1; i <= n; i++)
        printf("Peg %d: Disk %d\n", i, i);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input. Number of disks must be greater than 0.\n");
        return 1;
    }

    solveHanoi(n);
    return 0;
}