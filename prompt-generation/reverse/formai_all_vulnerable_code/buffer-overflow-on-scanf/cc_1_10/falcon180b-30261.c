//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to perform bitwise AND operation
unsigned int bitwise_and(unsigned int num1, unsigned int num2)
{
    return num1 & num2;
}

// Function to perform bitwise OR operation
unsigned int bitwise_or(unsigned int num1, unsigned int num2)
{
    return num1 | num2;
}

// Function to perform bitwise XOR operation
unsigned int bitwise_xor(unsigned int num1, unsigned int num2)
{
    return num1 ^ num2;
}

// Function to perform bitwise NOT operation
unsigned int bitwise_not(unsigned int num)
{
    return ~num;
}

// Function to perform bitwise left shift operation
unsigned int bitwise_left_shift(unsigned int num, int shift)
{
    return num << shift;
}

// Function to perform bitwise right shift operation
unsigned int bitwise_right_shift(unsigned int num, int shift)
{
    return num >> shift;
}

int main()
{
    unsigned int num1, num2, result;

    // Prompt user to enter two numbers
    printf("Enter two numbers:\n");
    scanf("%u %u", &num1, &num2);

    // Perform bitwise AND operation
    result = bitwise_and(num1, num2);
    printf("Bitwise AND operation result: %u\n", result);

    // Perform bitwise OR operation
    result = bitwise_or(num1, num2);
    printf("Bitwise OR operation result: %u\n", result);

    // Perform bitwise XOR operation
    result = bitwise_xor(num1, num2);
    printf("Bitwise XOR operation result: %u\n", result);

    // Perform bitwise NOT operation
    result = bitwise_not(num1);
    printf("Bitwise NOT operation result: %u\n", result);

    // Perform bitwise left shift operation
    result = bitwise_left_shift(num1, 2);
    printf("Bitwise left shift operation result: %u\n", result);

    // Perform bitwise right shift operation
    result = bitwise_right_shift(num1, 2);
    printf("Bitwise right shift operation result: %u\n", result);

    return 0;
}