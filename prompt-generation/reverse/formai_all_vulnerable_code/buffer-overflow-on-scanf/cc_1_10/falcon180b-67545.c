//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISK 100

void hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }

    hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISK)
    {
        printf("Invalid number of disks\n");
        return 1;
    }

    srand(time(NULL));
    char from_rod = 'A' + rand() % 3;
    char to_rod = 'A' + rand() % 3;
    char aux_rod = 'A' + rand() % 3;

    while (from_rod == to_rod || from_rod == aux_rod || to_rod == aux_rod)
    {
        from_rod = 'A' + rand() % 3;
        to_rod = 'A' + rand() % 3;
        aux_rod = 'A' + rand() % 3;
    }

    printf("The initial state of the rods:\n");
    printf("From rod: %c\n", from_rod);
    printf("To rod: %c\n", to_rod);
    printf("Auxiliary rod: %c\n", aux_rod);

    printf("\n");

    hanoi(n, from_rod, to_rod, aux_rod);

    return 0;
}