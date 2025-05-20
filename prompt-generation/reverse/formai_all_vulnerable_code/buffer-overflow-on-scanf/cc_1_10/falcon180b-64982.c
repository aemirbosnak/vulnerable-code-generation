//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void print_pattern(int num)
{
    int i, j, k;
    for (i = 0; i < num; i++)
    {
        for (j = num - 1; j >= i; j--)
        {
            printf("  ");
        }
        for (k = 0; k <= 2 * i - 1; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

int main()
{
    int num, i;
    printf("Enter the number of lines: ");
    scanf("%d", &num);

    if (num <= 0 || num > MAX)
    {
        printf("Invalid input. Enter a number between 1 and %d.\n", MAX);
        exit(1);
    }

    srand(time(NULL));
    int pattern[num][num];

    for (i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            pattern[i][j] = rand() % 2;
        }
    }

    for (i = 0; i < num; i++)
    {
        if (pattern[i][0] == 1)
        {
            printf(" ");
        }
        else
        {
            printf("*");
        }
    }

    printf("\n");
    for (i = 0; i < num; i++)
    {
        print_pattern(i + 1);
    }

    return 0;
}