//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int get_fibonacci_number(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return get_fibonacci_number(n-1) + get_fibonacci_number(n-2);
    }
}

void print_fibonacci_sequence(int n)
{
    printf("Welcome to Fibonacci Sequence Visualizer!\n");

    printf("Generating the Fibonacci sequence up to the %dth term...\n", n);

    printf("1\n1 ");

    int i;
    for (i = 3; i <= n; i++)
    {
        int fibonacci_number = get_fibonacci_number(i);
        if (i % 10 == 0)
        {
            printf("%d\n", fibonacci_number);
        }
        else
        {
            printf("%d ", fibonacci_number);
        }
    }
}

int main()
{
    int n;

    printf("Please input the number of terms in the Fibonacci sequence you would like to visualize: ");
    scanf("%d", &n);

    if (n >= 1)
    {
        print_fibonacci_sequence(n);
    }
    else
    {
        printf("Invalid input! Please input a positive integer greater than or equal to 1.\n");
    }

    printf("Thank you for using Fibonacci Sequence Visualizer!\n");

    return 0;
}