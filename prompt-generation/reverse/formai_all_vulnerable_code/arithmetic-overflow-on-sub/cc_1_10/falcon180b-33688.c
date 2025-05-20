//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10

void move(int n, int from, int to, int aux)
{
    int i;
    for (i = 0; i < n - 1; i++)
        printf("Move disk %d from %d to %d\n", i + 1, from, to);
    printf("Move disk %d from %d to %d\n", n, from, to);
}

void hanoi(int n, int from, int to, int aux)
{
    if (n == 1)
    {
        move(n, from, to, aux);
        return;
    }

    hanoi(n - 1, from, aux, to);
    move(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

int main()
{
    int n, i;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    srand(time(0));
    int from = rand() % 3;
    int to = rand() % 3;
    int aux = rand() % 3;

    printf("Initial position: ");
    while (from == to)
        from = rand() % 3;
    while (from == aux)
        aux = rand() % 3;

    printf("From: %d\nTo: %d\nAux: %d\n", from, to, aux);

    hanoi(n, from, to, aux);

    return 0;
}