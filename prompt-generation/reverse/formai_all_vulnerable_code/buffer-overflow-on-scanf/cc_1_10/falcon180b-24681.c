//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function to calculate the factorial of a number
unsigned long long factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

//Recursive function to generate Fibonacci numbers
void fibonacci(int n, int *a, int *b)
{
    if(n == 0)
    {
        *a = 0;
        *b = 1;
    }
    else
    {
        int c;
        fibonacci(n-1, a, b);
        c = *a + *b;
        *a = *b;
        *b = c;
    }
}

//Main function to call the recursive functions
int main()
{
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int a, b;
    a = 0, b = 1;

    printf("Fibonacci Series:\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", a);
        fibonacci(i, &a, &b);
    }

    printf("\nFactorial:\n");
    for(i=0; i<n; i++)
    {
        printf("%d! = %llu\n", i, factorial(i));
    }

    return 0;
}