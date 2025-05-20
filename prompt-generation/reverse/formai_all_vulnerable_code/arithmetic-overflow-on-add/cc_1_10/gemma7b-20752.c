//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 50

int main()
{
    int n, i, j, k, fib_num[MAX_NUM];
    time_t t;

    // Seed the random number generator
    srand(time(NULL));

    // Generate the Fibonacci sequence
    fib_num[0] = fib_num[1] = 1;
    for (i = 2; i < MAX_NUM; i++)
    {
        fib_num[i] = fib_num[i - 1] + fib_num[i - 2];
    }

    // Display the Fibonacci sequence
    printf("The Fibonacci sequence of numbers is:\n");
    for (i = 0; i < MAX_NUM; i++)
    {
        printf("%d ", fib_num[i]);
    }

    // Draw a fractal
    printf("\nDrawing a fractal...\n");
    for (k = 0; k < MAX_NUM; k++)
    {
        for (i = 0; i < MAX_NUM; i++)
        {
            for (j = 0; j < MAX_NUM; j++)
            {
                if (fib_num[i] + fib_num[j] == fib_num[k])
                {
                    printf("* ");
                }
                else
                {
                    printf(". ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}