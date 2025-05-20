//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TERM 100

bool is_valid_input(int n)
{
    return (n > 0 && n <= MAX_TERM);
}

unsigned long long fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }

    unsigned long long a = 1, b = 1;
    unsigned long long c;

    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main()
{
    int n;

    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);

    if (!is_valid_input(n))
    {
        printf("Invalid input, please enter a value between 1 and %d\n", MAX_TERM);
        return 1;
    }

    // Generate Fibonacci sequence and display it visually using asterisks
    printf("Fibonacci sequence up to %d terms:\n\n", n);

    for (int i = 1; i <= n; i++)
    {
        unsigned long long term_value = fibonacci(i);

        printf("%llu: ", term_value);

        for (int j = 0; j < term_value; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}