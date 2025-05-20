//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Function to print the current state of the towers
void printTowers(int n, int tow1[], int tow2[], int tow3[])
{
    printf("\nCurrent state of the towers:\n");
    for (int i = n; i >= 1; i--)
    {
        printf("Tower 1: ");
        for (int j = 0; j < i; j++)
        {
            if (tow1[j] == 0)
            {
                printf("  ");
            }
            else
            {
                printf("%d ", tow1[j]);
            }
        }
        printf("\n");

        printf("Tower 2: ");
        for (int j = 0; j < i; j++)
        {
            if (tow2[j] == 0)
            {
                printf("  ");
            }
            else
            {
                printf("%d ", tow2[j]);
            }
        }
        printf("\n");

        printf("Tower 3: ");
        for (int j = 0; j < i; j++)
        {
            if (tow3[j] == 0)
            {
                printf("  ");
            }
            else
            {
                printf("%d ", tow3[j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to move a disk from one tower to another
void moveDisk(int n, int fromTower[], int toTower[])
{
    // Find the index of the top disk on the 'fromTower'
    int i;
    for (i = 0; i < n; i++)
    {
        if (fromTower[i] != 0)
        {
            break;
        }
    }
    // Move the top disk from the 'fromTower' to the 'toTower'
    toTower[n - i] = fromTower[i];
    fromTower[i] = 0;
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, int tow1[], int tow2[], int tow3[])
{
    // Print the initial state of the towers
    printTowers(n, tow1, tow2, tow3);

    // Base case: When there is only one disk
    if (n == 1)
    {
        moveDisk(n, tow1, tow3);
        printTowers(n, tow1, tow2, tow3);
        return;
    }

    // Recursive case: When there are more than one disk
    towerOfHanoi(n - 1, tow1, tow3, tow2);
    moveDisk(n, tow1, tow3);
    towerOfHanoi(n - 1, tow2, tow1, tow3);
}

int main()
{
    // Get the number of disks from the user
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Create three towers to store the disks
    int tow1[n], tow2[n], tow3[n];

    // Initialize the towers
    for (int i = 0; i < n; i++)
    {
        tow1[i] = n - i;
        tow2[i] = 0;
        tow3[i] = 0;
    }

    // Solve the Tower of Hanoi problem
    towerOfHanoi(n, tow1, tow2, tow3);

    return 0;
}