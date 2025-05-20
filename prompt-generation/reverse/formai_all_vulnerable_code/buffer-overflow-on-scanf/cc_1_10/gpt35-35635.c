//FormAI DATASET v1.0 Category: Educational ; Style: immersive
#include <stdio.h>

int main()
{
    int n = 0;
    printf("Welcome to the immersive world of C Programming!\n");
    printf("Please enter a positive integer number: ");
    scanf("%d", &n); // Accepting input from user
    
    // Checking whether number is even or odd
    if(n % 2 == 0)
    {
        printf("\n%d is an even number!\n", n);
    }
    else
    {
        printf("\n%d is an odd number!\n", n);
    }
    
    // Printing multiplication table of the entered number
    printf("\nMultiplication table of %d:\n", n);
    for(int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", n, i, n*i);
    }
    
    // Printing Fibonacci series upto the entered number
    printf("\nFibonacci series upto %d:\n", n);
    int n1 = 0, n2 = 1, sum = 0;
    printf("%d ", n1);
    while(sum <= n)
    {
        printf("%d ", sum);
        n1 = n2;
        n2 = sum;
        sum = n1 + n2;
    }
    
    // Checking whether entered number is a prime number or not
    int i, flag = 0;
    for(i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if(n == 1)
    {
        printf("\n\n%d is neither prime nor composite!", n);
    }
    else
    {
        if(flag == 0)
            printf("\n\n%d is a prime number!", n);
        else
            printf("\n\n%d is not a prime number!", n);
    }
    
    printf("\n\nThank you for experiencing the magic of C Programming!");
    return 0;
}