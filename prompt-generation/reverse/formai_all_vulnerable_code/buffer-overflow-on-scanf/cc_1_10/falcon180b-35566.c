//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: romantic
#include <stdio.h>

#define N 3

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    printf("\nMove disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int i, choice;

    printf("\n\n\t\t\tTOWER OF HANOI PROBLEM\n\n");

    printf("\nEnter the number of disks: ");
    scanf("%d", &i);

    if (i < 1 || i > 10)
    {
        printf("\n\nInvalid number of disks. Please enter a number between 1 and 10.\n\n");
        return 0;
    }

    printf("\n\nInitial position of the tower:\n");

    for (int j = i; j >= 1; j--)
    {
        printf("Disk %d is on rod A\n", j);
    }

    printf("\n\nDo you want to see the solution? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        printf("\n\nThe solution is:\n");
        towerOfHanoi(i, 'A', 'C', 'B');
    }

    return 0;
}