//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    int i;
    if (n == 1)
    {
        printf("\nMove disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("\nMove disk %d from rod %c to rod %c", n, from_rod, to_rod);
    for (i = 1; i < n; i++)
        printf("\nMove disk %d from rod %c to rod %c", i, to_rod, aux_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    printf("\nEnter the number of disks: ");
    scanf("%d", &n);

    srand(time(NULL));
    int choice = rand() % 3;
    char from_rod, to_rod, aux_rod;

    if (choice == 0)
    {
        from_rod = 'A';
        to_rod = 'C';
        aux_rod = 'B';
    }
    else if (choice == 1)
    {
        from_rod = 'A';
        to_rod = 'B';
        aux_rod = 'C';
    }
    else
    {
        from_rod = 'B';
        to_rod = 'A';
        aux_rod = 'C';
    }

    printf("\nThe initial position of the disks is as follows:\n");
    printf("From rod %c to rod %c\n\n", from_rod, to_rod);

    towerOfHanoi(n, from_rod, to_rod, aux_rod);

    return 0;
}