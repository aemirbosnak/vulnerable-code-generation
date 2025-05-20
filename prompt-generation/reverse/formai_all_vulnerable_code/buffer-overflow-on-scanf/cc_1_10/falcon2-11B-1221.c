//Falcon2-11B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main()
{
    int i, j, n;
    int fib[100];
    int sum = 0;
    int start, end, diff;
    char shape[1000];
    int size;
    int count = 0;

    srand(time(NULL));

    printf("Enter the number of elements in the Fibonacci sequence: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        fib[i] = 1;
    }

    for (i = 1; i < n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    for (i = 0; i < n; i++)
    {
        sum += fib[i];
    }

    start = 1;
    end = n;

    printf("Fibonacci Sequence: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", fib[i]);
    }

    printf("\n");

    while (start <= end)
    {
        if (count == 0)
        {
            size = (rand() % (end - start + 1) + start);
            count++;
        }

        if (size <= end)
        {
            for (j = 0; j < size; j++)
            {
                printf("*");
            }

            printf("\n");

            start += 1;
            end -= 1;

            diff = (end - start);

            if (diff < 5)
            {
                start += 5;
                end -= 5;
            }
        }
        else
        {
            start += size;
            end -= size;
        }
    }

    return 0;
}