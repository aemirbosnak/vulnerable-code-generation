//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>

/* Function to print binary representation of unsigned integers */
void print_binary(unsigned int num)
{
    unsigned int mask = 1 << 31;
    printf("Binary representation of %u is: ", num);
    for (int i = 0; i < 32; i++) {
        if (num & mask)
            printf("1");
        else
            printf("0");
        mask >>= 1;
    }
    printf("\n");
}

/* Function to perform bitwise XOR operation */
unsigned int my_xor(unsigned int num1, unsigned int num2)
{
    unsigned int result = 0;
    for (int i = 31; i >= 0; i--) {
        if (((num1 >> i) & 1) ^ ((num2 >> i) & 1))
            result |= 1 << i;
        else
            result &= ~(1 << i);
    }
    return result;
}

/* Function to perform bitwise OR operation */
unsigned int my_or(unsigned int num1, unsigned int num2)
{
    unsigned int result = 0;
    for (int i = 31; i >= 0; i--) {
        if (((num1 >> i) & 1) | ((num2 >> i) & 1))
            result |= 1 << i;
        else
            result &= ~(1 << i);
    }
    return result;
}

/* Function to perform bitwise AND operation */
unsigned int my_and(unsigned int num1, unsigned int num2)
{
    unsigned int result = 0;
    for (int i = 31; i >= 0; i--) {
        if (((num1 >> i) & 1) & ((num2 >> i) & 1))
            result |= 1 << i;
        else
            result &= ~(1 << i);
    }
    return result;
}

int main()
{
    unsigned int a = 0b10101010;
    unsigned int b = 0b11001100;
    unsigned int c = 0b11110000;

    printf("Before bitwise XOR operation:\n");
    print_binary(a);
    print_binary(b);
    printf("\nPerforming bitwise XOR operation:\n");
    unsigned int result1 = my_xor(a, b);
    print_binary(result1);

    printf("\nBefore bitwise OR operation:\n");
    print_binary(b);
    print_binary(c);
    printf("\nPerforming bitwise OR operation:\n");
    unsigned int result2 = my_or(b, c);
    print_binary(result2);

    printf("\nBefore bitwise AND operation:\n");
    print_binary(a);
    print_binary(c);
    printf("\nPerforming bitwise AND operation:\n");
    unsigned int result3 = my_and(a, c);
    print_binary(result3);

    return 0;
}