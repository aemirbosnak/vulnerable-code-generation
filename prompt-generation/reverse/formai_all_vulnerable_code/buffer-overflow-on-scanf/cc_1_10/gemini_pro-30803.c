//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int is_prime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Function to print the prime numbers in a given range
void print_primes(int start, int end)
{
    printf("Prime numbers in the range %d to %d:\n", start, end);
    for (int i = start; i <= end; ++i)
    {
        if (is_prime(i))
        {
            if (i % 10 == 0){
                printf("%d\n", i);
            }
            else{
                printf("%d  ", i);
            }
        }
    }
    printf("\n");
}

int main()
{
    int start, end;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    // Check if the starting number is less than the ending number
    if (start > end)
    {
        printf("Invalid range: The starting number must be less than or equal to the ending number.\n");
        return 1;
    }

    // Print the prime numbers in the given range
    print_primes(start, end);

    return 0;
}