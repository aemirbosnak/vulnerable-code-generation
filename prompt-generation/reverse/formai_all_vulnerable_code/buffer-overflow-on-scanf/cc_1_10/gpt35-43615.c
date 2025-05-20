//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
#include <stdio.h>

void printTower(int src[], int temp[], int dest[], int n);
void moveDisk(int src[], int dest[]);
void towerOfHanoi(int n, int src[], int temp[], int dest[]);

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    int src[n], temp[n], dest[n];

    // Initializing source tower with n disks
    for (int i = 0; i < n; i++)
        src[i] = n - i;

    // Initializing the other two towers to be empty
    for (int i = 0; i < n; i++)
        temp[i] = dest[i] = 0;

    printf("Initial Configuration:\n");
    printTower(src, temp, dest, n);

    // Calling the recursive towerOfHanoi function
    towerOfHanoi(n, src, temp, dest);

    printf("Final Configuration:\n");
    printTower(src, temp, dest, n);

    return 0;
}

// Function to print the tower configurations
void printTower(int src[], int temp[], int dest[], int n)
{
    printf("\nSource Tower: ");
    for (int i = 0; i < n; i++)
    {
        if (src[i] != 0)
            printf("%d ", src[i]);
    }

    printf("\nTemp Tower: ");
    for (int i = 0; i < n; i++)
    {
        if (temp[i] != 0)
            printf("%d ", temp[i]);
    }

    printf("\nDestination Tower: ");
    for (int i = 0; i < n; i++)
    {
        if (dest[i] != 0)
            printf("%d ", dest[i]);
    }

    printf("\n\n");
}

// Function to move the disk from source tower to destination tower
void moveDisk(int src[], int dest[])
{
    int srcDisk = src[0];
    int destDisk = dest[0];

    // Finding the topmost available position in the destination tower
    int i;
    for (i = 1; dest[i] != 0; i++)
    { }

    // Moving the disk
    dest[i] = srcDisk;
    src[0] = 0;

    // Shifting the remaining disks in the source tower
    for (i = 0; i < 9; i++)
    {
        src[i] = src[i+1];
    }
    src[9] = 0;

    printf("Move disk %d from Source Tower to Destination Tower.\n", srcDisk);
}

void towerOfHanoi(int n, int src[], int temp[], int dest[])
{
    if (n == 1)
    {
        // If only one disk is there then move directly to destination tower
        moveDisk(src, dest);
        printTower(src, temp, dest, 10);
    }
    else
    {
        towerOfHanoi(n-1, src, dest, temp);
        moveDisk(src, dest);
        printTower(src, temp, dest, 10);
        towerOfHanoi(n-1, temp, src, dest);
    }
}