//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n);

int main()
{
    int limit;
    int i;

    printf("How many prime numbers do you want to generate? ");
    scanf("%d", &limit);

    if (limit <= 0)
    {
        printf("Please enter a positive integer.\n");
        return 0;
    }

    printf("The first %d prime numbers are: \n", limit);
  
    int count = 0;
    int number = 2;

    while (count < limit)
    {
        if (is_prime(number))
        {
            printf("%d ", number);
            count++;
        }
      
        number++;
    }
  
    return 0;
}

int is_prime(int n)
{
    int i;
  
    if (n <= 1)
    {
        return 0;
    }

    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
  
    return 1;
}