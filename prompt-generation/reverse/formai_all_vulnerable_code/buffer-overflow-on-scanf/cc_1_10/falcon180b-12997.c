//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void moveTower(int n, char from, char to, char aux);
void printTower(int n, char from, char to, char aux);

int main()
{
    int n;
    char from, to, aux;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Enter the starting rod: ");
    scanf("%c", &from);
    printf("Enter the ending rod: ");
    scanf("%c", &to);
    printf("Enter the auxiliary rod: ");
    scanf("%c", &aux);

    // Initialize the towers
    char tower1[n];
    char tower2[n];
    char tower3[n];

    // Build the initial tower
    for (int i = n; i >= 1; i--)
    {
        tower1[i-1] = 'A' + i;
    }

    // Print the initial tower
    printf("\nInitial tower:\n");
    printTower(n, 'A', 'C', 'B');

    // Move the disks
    moveTower(n, 'A', 'C', 'B');

    // Print the final tower
    printf("\n\nFinal tower:\n");
    printTower(n, 'C', 'A', 'B');

    return 0;
}

void moveTower(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from rod %c to rod %c\n", from, to);
        return;
    }

    moveTower(n-1, from, aux, to);
    printf("\nMove disk %d from rod %c to rod %c\n", n, from, to);
    moveTower(n-1, aux, to, from);
}

void printTower(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("\nRod %c has 1 disk\n", from);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (i!= n)
        {
            printf("\nRod %c has %d disks\n", from, i);
        }
        else
        {
            printf("\nRod %c has %d disks\n", to, i);
        }
    }

    printf("\n");
}