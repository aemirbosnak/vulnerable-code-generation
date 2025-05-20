//FormAI DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

// Recursive function to get the binary representation of a decimal number
void binary(int n)
{
    if (n == 0)
        return;
    binary(n / 2);
    printf("%d", n % 2);
}

// Recursive function to count the number of set bits in a decimal number
int count_set_bits(int n)
{
    if (n == 0)
        return 0;
    else
        return (n & 1) + count_set_bits(n >> 1);
}

// Recursive function to perform the AND operation on two decimal numbers
int bitwise_and(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    else
        return (a & b) | bitwise_and(a >> 1, b >> 1);
}

// Recursive function to perform the OR operation on two decimal numbers
int bitwise_or(int a, int b)
{
    if (a == 0 && b == 0)
        return 0;
    else
        return (a | b) & (~((~a) & (~b))) | bitwise_or(a >> 1, b >> 1);
}

// Recursive function to perform the XOR operation on two decimal numbers
int bitwise_xor(int a, int b)
{
    if (a == 0 && b == 0)
        return 0;
    else
        return (a ^ b) | bitwise_xor(a >> 1, b >> 1);
}

int main()
{
    int decimal1, decimal2;
    printf("Enter two decimal numbers: ");
    scanf("%d %d", &decimal1, &decimal2);

    printf("Binary representation of %d: ", decimal1);
    binary(decimal1);
    printf("\nBinary representation of %d: ", decimal2);
    binary(decimal2);

    printf("\nNumber of set bits in %d: %d", decimal1, count_set_bits(decimal1));
    printf("\nNumber of set bits in %d: %d", decimal2, count_set_bits(decimal2));

    printf("\nAND operation of %d and %d: %d", decimal1, decimal2, bitwise_and(decimal1, decimal2));
    printf("\nOR operation of %d and %d: %d", decimal1, decimal2, bitwise_or(decimal1, decimal2));
    printf("\nXOR operation of %d and %d: %d", decimal1, decimal2, bitwise_xor(decimal1, decimal2));

    return 0;
}