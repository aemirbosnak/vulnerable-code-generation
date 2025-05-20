//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to solve the Tower of Hanoi problem
void solveTower(int n, char source, char aux, char dest);

// Function to display the moves needed to complete the task
void displayMoves(int n, char source, char aux, char dest);

int main()
{
    // Ask user for number of disks
    printf("Enter the number of disks: ");
    int n;
    scanf("%d", &n);
    
    // Call function to solve the Tower of Hanoi problem
    solveTower(n, 'A', 'B', 'C');
    
    // Call function to display the moves
    displayMoves(n, 'A', 'B', 'C');
    
    return 0;
}

// Function to solve the Tower of Hanoi problem
void solveTower(int n, char source, char aux, char dest)
{
    // Base case: if there is only one disk, move it to the destination peg
    if (n == 1)
    {
        printf("Move disk 1 from peg %c to peg %c\n", source, dest);
        return;
    }
    
    // Recursive case: move n-1 disks from source to aux and move the remaining disk to destination
    solveTower(n - 1, source, dest, aux);
    printf("Move disk %d from peg %c to peg %c\n", n, source, dest);
    solveTower(n - 1, aux, source, dest);
}

// Function to display the moves needed to complete the task
void displayMoves(int n, char source, char aux, char dest)
{
    if (n == 1)
    {
        printf("Move disk 1 from peg %c to peg %c\n", source, dest);
        return;
    }
    
    // Recursive case: display the moves needed to move n-1 disks from source to aux and move the remaining disk to destination
    displayMoves(n - 1, source, dest, aux);
    printf("Move disk %d from peg %c to peg %c\n", n, source, dest);
    displayMoves(n - 1, aux, source, dest);
}