//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// This is the Tower of Hanoi problem, an ancient puzzle that involves moving disks from one rod to another.
// The goal is to move the entire stack to another rod, obeying the following simple rules:
//     1. Only one disk may be moved at a time.
//     2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.
//     3. No disk may be placed on top of a smaller disk.

void solve_tower_of_hanoi(int n, char fromRod, char toRod, char auxRod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }

    // Move n-1 disks from 'A' to 'B' using 'C' as auxiliary
    solve_tower_of_hanoi(n - 1, fromRod, auxRod, toRod);

    // Move remaining disk from 'A' to 'C'
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);

    // Move n-1 disks from 'B' to 'C' using 'A' as auxiliary
    solve_tower_of_hanoi(n - 1, auxRod, toRod, fromRod);
}

int main()
{
    printf("Welcome to the Tower of Hanoi!\n\n");

    int n;

    // Prompt user for input
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Validate input
    if (n <= 0)
    {
        printf("Invalid input! Number of disks must be greater than zero.\n");
        return 1;
    }

    printf("\nHere are the steps to solve the problem with %d disks:\n\n", n);

    // Solve problem using recursion
    solve_tower_of_hanoi(n, 'A', 'C', 'B');

    printf("\nCongratulations! You have solved the Tower of Hanoi problem.\n");

    return 0;
}