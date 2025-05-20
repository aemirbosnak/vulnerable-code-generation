//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
#include <stdio.h>

// check if a number is prime
int isPrime(int n) 
{
    if (n <= 1) 
        return 0;
    
    for (int i = 2; i < n; i++) 
    {
        if (n % i == 0)
            return 0;
    }
    
    return 1;
}

// generate prime sequence up to a given limit
void generatePrimes(int limit) 
{
    int count = 0;
    
    for (int i = 2; i <= limit; i++) 
    {
        if (isPrime(i)) 
        {
            printf("%d ", i);
            count++;
        }
    }
    
    if (count == 0) 
    {
        printf("No primes found up to %d\n", limit);
    }
    
    printf("\n");
}

int main()
{
    int limit;
    
    printf("Enter limit to generate prime numbers: ");
    scanf("%d", &limit);
    
    generatePrimes(limit);
    
    return 0;
}