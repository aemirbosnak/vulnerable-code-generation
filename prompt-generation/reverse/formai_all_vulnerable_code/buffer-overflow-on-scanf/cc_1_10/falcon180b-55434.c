//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_NUMBERS 1000
#define MAX_BITS 32

// Function to generate random number with specified number of bits
unsigned int rand_bits(int num_bits)
{
    unsigned int num = 0;
    unsigned int max_num = (1 << num_bits) - 1;
    srand(time(NULL));

    for (int i = 0; i < num_bits; i++)
    {
        num = (num << 1) | (rand() % 2);
    }

    return num;
}

// Function to print binary representation of a number
void print_binary(unsigned int num, int num_bits)
{
    for (int i = num_bits - 1; i >= 0; i--)
    {
        printf("%u", (num >> i) & 1);
    }
}

// Function to perform bitwise AND operation on two numbers
unsigned int bitwise_and(unsigned int num1, unsigned int num2)
{
    return num1 & num2;
}

// Function to perform bitwise OR operation on two numbers
unsigned int bitwise_or(unsigned int num1, unsigned int num2)
{
    return num1 | num2;
}

// Function to perform bitwise XOR operation on two numbers
unsigned int bitwise_xor(unsigned int num1, unsigned int num2)
{
    return num1 ^ num2;
}

// Function to perform bitwise NOT operation on a number
unsigned int bitwise_not(unsigned int num)
{
    return ~num;
}

// Function to perform bitwise left shift operation on a number
unsigned int bitwise_left_shift(unsigned int num, int shift_bits)
{
    return num << shift_bits;
}

// Function to perform bitwise right shift operation on a number
unsigned int bitwise_right_shift(unsigned int num, int shift_bits)
{
    return num >> shift_bits;
}

// Function to test all bitwise operations
int main()
{
    unsigned int num1, num2;
    int choice, num_bits;

    printf("Enter the number of bits for the test numbers: ");
    scanf("%d", &num_bits);

    printf("Enter two numbers to test bitwise operations:\n");
    scanf("%u %u", &num1, &num2);

    printf("\nBitwise AND: ");
    print_binary(bitwise_and(num1, num2), num_bits);
    printf("\nBitwise OR: ");
    print_binary(bitwise_or(num1, num2), num_bits);
    printf("\nBitwise XOR: ");
    print_binary(bitwise_xor(num1, num2), num_bits);
    printf("\nBitwise NOT: ");
    print_binary(bitwise_not(num1), num_bits);

    printf("\nEnter the number of bits to shift: ");
    scanf("%d", &num_bits);

    printf("\nBitwise left shift by %d bits: ", num_bits);
    print_binary(bitwise_left_shift(num1, num_bits), num_bits);
    printf("\nBitwise right shift by %d bits: ", num_bits);
    print_binary(bitwise_right_shift(num1, num_bits), num_bits);

    return 0;
}