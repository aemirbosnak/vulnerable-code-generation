//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to print the current state of the towers
void printTowers(int numDisks, char fromTower, char toTower, char auxTower)
{
    // Print the current state of each tower
    printf("Tower %c: ", fromTower);
    for (int i = numDisks; i > 0; i--)
    {
        printf("%d ", i);
    }
    printf("\n");
    printf("Tower %c: ", toTower);
    for (int i = numDisks; i > 0; i--)
    {
        printf("  ");
    }
    printf("\n");
    printf("Tower %c: ", auxTower);
    for (int i = numDisks; i > 0; i--)
    {
        printf("  ");
    }
    printf("\n\n");
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int numDisks, char fromTower, char toTower, char auxTower)
{
    // Base case: If there is only one disk, move it from the fromTower to the toTower
    if (numDisks == 1)
    {
        printf("Move disk 1 from tower %c to tower %c\n", fromTower, toTower);
        printTowers(numDisks, fromTower, toTower, auxTower);
        return;
    }

    // Recursive case:
    // 1. Move the top n-1 disks from the fromTower to the auxTower
    towerOfHanoi(numDisks - 1, fromTower, auxTower, toTower);
    // 2. Move the nth disk from the fromTower to the toTower
    printf("Move disk %d from tower %c to tower %c\n", numDisks, fromTower, toTower);
    printTowers(numDisks, fromTower, toTower, auxTower);
    // 3. Move the n-1 disks from the auxTower to the toTower
    towerOfHanoi(numDisks - 1, auxTower, toTower, fromTower);
}

int main()
{
    // Get the number of disks from the user
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Solve the Tower of Hanoi problem
    towerOfHanoi(numDisks, 'A', 'C', 'B');

    return 0;
}