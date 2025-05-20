//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isPrime(int n);
void generatePrimes(int start, int end);

int main()
{
    int start, end;

    printf("Enter the range to generate prime numbers: ");
    scanf("%d %d", &start, &end);

    generatePrimes(start, end);

    return 0;
}

int isPrime(int n)
{
    int i;

    if (n <= 1)
        return 0;

    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

void generatePrimes(int start, int end)
{
    int i, count = 0;
    struct tm *t;
    time_t now;

    time(&now);
    t = localtime(&now);

    printf("Prime numbers between %d and %d:\n", start, end);

    for (i = start; i <= end; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
            count++;

            if (count % 10 == 0)
            {
                printf("\n");
                t = localtime(&now);
                printf("Current date and time: %d/%d/%d %d:%d:%d\n", t->tm_mon + 1, t->tm_mday, t->tm_year + 1900, t->tm_hour, t->tm_min, t->tm_sec);
            }
        }
    }

    printf("\nTotal prime numbers found: %d\n", count);
}