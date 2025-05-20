//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

void moveTower(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    moveTower(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    moveTower(n - 1, aux, to, from);
}

int main()
{
    int n;
    char from, to, aux;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Check if the number of disks is valid
    if (n <= 0 || n > MAX_DISKS)
    {
        printf("Invalid number of disks\n");
        return 1;
    }

    // Get the starting and ending poles from the user
    printf("Enter the starting pole (A/B/C): ");
    scanf("%c", &from);
    printf("Enter the ending pole (A/B/C): ");
    scanf("%c", &to);

    // Get the auxiliary pole from the user
    if (from == 'A')
        aux = 'B';
    else if (from == 'B')
        aux = 'C';
    else
        aux = 'A';

    // Move the disks
    srand(time(NULL));
    moveTower(n, from, to, aux);

    return 0;
}