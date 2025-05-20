//Gemma-7B DATASET v1.0 Category: Browser Plugin ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the factorial of a number
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}

// Function to find the prime factors of a number
void findPrimes(int n)
{
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
        }
        i++;
    }
    printf("\n");
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    // Calculate the factorial of the number
    int factorial_result = factorial(number);

    // Find the prime factors of the number
    findPrimes(number);

    // Print the results
    printf("The factorial of %d is %d.\n", number, factorial_result);
    printf("The prime factors of %d are: ", number);

    return 0;
}