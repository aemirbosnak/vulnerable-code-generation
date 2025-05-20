//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to print the contents of the towers
void printTowers(int n, int towers[][n])
{
    for (int i = 0; i < n; i++)
    {
        printf("Tower %d: ", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf("%d ", towers[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to move a disk from one tower to another
void moveDisk(int n, int towers[][n], int src, int dest)
{
    int temp;

    // Find the index of the top disk in the source tower
    int src_top = -1;
    for (int i = 0; i < n; i++)
    {
        if (towers[src][i] != 0)
        {
            src_top = i;
            break;
        }
    }

    // Find the index of the top disk in the destination tower
    int dest_top = -1;
    for (int i = 0; i < n; i++)
    {
        if (towers[dest][i] != 0)
        {
            dest_top = i;
            break;
        }
    }

    // Move the disk from the source tower to the destination tower
    if (towers[src][src_top] != 0)
    {
        towers[dest][dest_top + 1] = towers[src][src_top];
        towers[src][src_top] = 0;
    }
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, int towers[][n], int src, int dest, int aux)
{
    // Base case: only one disk
    if (n == 1)
    {
        moveDisk(n, towers, src, dest);
    }
    else
    {
        // Move n-1 disks from the source tower to the auxiliary tower
        towerOfHanoi(n - 1, towers, src, aux, dest);

        // Move the remaining disk from the source tower to the destination tower
        moveDisk(n, towers, src, dest);

        // Move the n-1 disks from the auxiliary tower to the destination tower
        towerOfHanoi(n - 1, towers, aux, dest, src);
    }
}

int main()
{
    int n;

    // Get the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Create a 2D array to represent the towers
    int towers[3][n];

    // Initialize the towers
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            towers[i][j] = 0;
        }
    }

    // Place the disks on the source tower
    for (int i = n - 1; i >= 0; i--)
    {
        towers[0][i] = n - i;
    }

    // Print the initial state of the towers
    printTowers(n, towers);

    // Solve the Tower of Hanoi problem
    towerOfHanoi(n, towers, 0, 2, 1);

    // Print the final state of the towers
    printTowers(n, towers);

    return 0;
}