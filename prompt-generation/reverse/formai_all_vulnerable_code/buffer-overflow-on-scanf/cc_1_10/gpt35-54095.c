//FormAI DATASET v1.0 Category: Recursive ; Style: mathematical
#include <stdio.h>

// Function to calculate factorial of a given number
int factorial(int num)
{
    if (num == 0)
        return 1;
    else 
        return num * factorial(num-1);
}

// Fibonnaci Series Recursive Function
int fibonacci(int num)
{
    if (num <= 1)
        return num;
    else
        return fibonacci(num-1) + fibonacci(num-2);
}

// GCD Recursive Function
int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return a + b;
    else
        return gcd(b, a%b);
}

// Power Recursive Function
int power(int num, int expo)
{
    if (expo == 0)
        return 1;
    else if (expo > 0)
        return num * power(num, expo-1);
    else
        return 1/num * power(num, expo+1);
}

int main()
{
    int num;

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d\n", num, factorial(num));

    printf("Enter a number to calculate Fibonacci series: ");
    scanf("%d", &num);
    printf("Fibonacci series upto %d = ", num);
    for (int i = 0; i < num; i++)
        printf("%d ", fibonacci(i));

    int a, b;
    printf("\nEnter two numbers to calculate GCD: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d = %d\n", a, b, gcd(a, b));

    int base, exp;
    printf("Enter base and exponent to calculate power: ");
    scanf("%d %d", &base, &exp);
    printf("%d to the power of %d = %d\n", base, exp, power(base, exp));

    return 0;
}