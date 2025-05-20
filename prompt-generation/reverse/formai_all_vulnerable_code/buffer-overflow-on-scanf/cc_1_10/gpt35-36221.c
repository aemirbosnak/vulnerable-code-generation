//FormAI DATASET v1.0 Category: Educational ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i;
    printf("Enter a number:\n");
    scanf("%d", &num);
    printf("The factors of %d are: ", num);

    for (i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            printf("%d ", i);
        }
    }

    printf("\n\nThe sum of the factors of %d is: ", num);

    int sum = 0;

    for (i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }

    printf("%d\n\n", sum);

    printf("The prime factors of %d are: ", num);

    int j, isPrime;

    for (i = 2; i <= num; i++)
    {
        if (num % i == 0) 
        {
            isPrime = 1;
            for (j = 2; j <= i / 2; j++)
            {
                if (i % j == 0)
                {
                    isPrime = 0;
                    break;
                }
            }

            if (isPrime == 1)
            {
                printf("%d ", i);
            }
        }
    }

    printf("\n");

    return 0;
}