//FormAI DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include<stdlib.h>
#include<stdio.h>

/*
Program to evaluate bitwise operations recursively.
*/

void binary(int n)
{
    if (n > 1)
        binary(n/2);

    printf("%d", n % 2);
}

int bitwise_and(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    else if (a % 2 == 1 && b % 2 == 1)
        return 1 + 2 * bitwise_and(a/2, b/2);
    else
        return 2 * bitwise_and(a/2, b/2);
}

int bitwise_or(int a, int b)
{
    if (a == 0 && b == 0)
        return 0;
    else if (a % 2 == 1 || b % 2 == 1)
        return 1 + 2 * bitwise_or(a/2, b/2);
    else
        return 2 * bitwise_or(a/2, b/2);
}

int bitwise_xor(int a, int b)
{
    if (a == 0 && b == 0)
        return 0;
    else if ((a % 2 == 1 && b % 2 == 0) || (a % 2 == 0 && b % 2 == 1))
        return 1 + 2 * bitwise_xor(a/2, b/2);
    else
        return 2 * bitwise_xor(a/2, b/2);
}

int bitwise_not(int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return 1 + 2 * bitwise_not(n/2);
    else
        return 2 * bitwise_not(n/2);
}

int main()
{
    int a, b;

    printf("Enter two numbers in decimal form: ");
    scanf("%d %d", &a, &b);

    printf("The bitwise AND of %d and %d is: ", a, b);
    binary(bitwise_and(a, b));
    printf("\n");

    printf("The bitwise OR of %d and %d is: ", a, b);
    binary(bitwise_or(a, b));
    printf("\n");

    printf("The bitwise XOR of %d and %d is: ", a, b);
    binary(bitwise_xor(a, b));
    printf("\n");

    printf("The bitwise NOT of %d is: ", a);
    binary(bitwise_not(a));
    printf("\n");

    return 0;
}