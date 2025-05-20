//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: retro
#include <stdio.h>

// Function to print the steps of the Tower of Hanoi puzzle
void towerOfHanoi(int n, char from, char to, char aux)
{
    // Base case: If there is only 1 disk, move it directly from the 'from' rod to the 'to' rod
    if (n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, from, to);
        return;
    }

    // Recursive case: Move the top n-1 disks from the 'from' rod to the 'aux' rod
    towerOfHanoi(n - 1, from, aux, to);

    // Move the nth disk from the 'from' rod to the 'to' rod
    printf("Move disk %d from %c to %c\n", n, from, to);

    // Recursive case: Move the n-1 disks from the 'aux' rod to the 'to' rod
    towerOfHanoi(n - 1, aux, to, from);
}

// Function to get the number of moves required to solve the Tower of Hanoi puzzle
int numMoves(int n)
{
    // If there is only 1 disk, it requires 1 move
    if (n == 1)
    {
        return 1;
    }

    // Otherwise, it requires 2 moves to move the top disk, plus the number of moves required to move the remaining n-1 disks
    return 2 * numMoves(n - 1) + 1;
}

// Main function
int main()
{
    // Get the number of disks from the user
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Print the tower of hanoi puzzle solution
    towerOfHanoi(n, 'A', 'C', 'B');

    // Print the number of moves required to solve the puzzle
    printf("Number of moves: %d\n", numMoves(n));

    return 0;
}