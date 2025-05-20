//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complex
#include <stdio.h>

void fibonacci(int n);

int main()
{
    int n;

    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}

void fibonacci(int n)
{
    long int fib1 = 0, fib2 = 1, fib3;
    int i, j, k = 0;

    printf("\nFibonacci sequence:\n");

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++) // add spaces before each number
        {
            printf(" ");
        }

        for (j = 1; j <= i; j++) // calculate and print the numbers in the sequence
        {
            if (k == 0)
            {
                printf("%ld", fib1);
                k++;
            }
            else if (k == 1)
            {
                printf("%ld", fib2);
                k++;
            }
            else
            {
                fib3 = fib1 + fib2;
                fib1 = fib2;
                fib2 = fib3;
                printf("%ld", fib3);
            }

            printf(" ");
        }

        printf("\n");
    }
}