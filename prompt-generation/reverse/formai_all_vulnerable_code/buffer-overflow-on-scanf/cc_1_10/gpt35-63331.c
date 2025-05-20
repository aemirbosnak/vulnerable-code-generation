//FormAI DATASET v1.0 Category: Educational ; Style: accurate
#include<stdio.h>
#include<math.h>

// Function to check if a number is prime or not
int isPrime(int n)
{
    int i, flag = 1;
    
    // Special cases
    if(n == 0 || n == 1)
        return 0;
    
    // Check if n is divisible by any number less than or equal to its square root
    for(i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    
    if(flag)
        return 1;
    else
        return 0;
}

// Function to find nth term of Fibonacci sequence
int fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n, i, j, flag, sum = 0, count = 0;
    
    // Input from user
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    // Find all prime numbers less than or equal to n and print them
    printf("\nPrime numbers less than or equal to %d: ", n);
    for(i = 2; i <= n; i++)
    {
        flag = 1;
        for(j = 2; j <= sqrt(i); j++)
        {
            if(i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        
        if(flag)
            printf("%d ", i);
    }
    
    // Find sum of first n odd numbers and print it
    printf("\n\nSum of first %d odd numbers: ", n);
    for(i = 1; count < n; i += 2)
    {
        sum += i;
        count++;
    }
    printf("%d", sum);
    
    // Find nth term of Fibonacci sequence and print it
    printf("\n\n%dth term of Fibonacci sequence: %d\n", n, fibonacci(n));
    
    return 0;
}