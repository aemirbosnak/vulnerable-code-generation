//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define SIZE 10
#define DELAY 100000

void hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Tower of Hanoi problem for %d disks:\n", n);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        char from = 'A' + rand() % 3;
        char to = 'A' + rand() % 3;
        char aux = 'A' + rand() % 3;
        while (from == to || from == aux)
        {
            from = 'A' + rand() % 3;
            to = 'A' + rand() % 3;
            aux = 'A' + rand() % 3;
        }
        printf("Tower %d: ", i + 1);
        for (int j = SIZE - 1; j >= 0; j--)
        {
            if (j < n)
            {
                printf(" %d ", n - j);
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
        hanoi(n, from, to, aux);
        printf("\n");
    }
    return 0;
}