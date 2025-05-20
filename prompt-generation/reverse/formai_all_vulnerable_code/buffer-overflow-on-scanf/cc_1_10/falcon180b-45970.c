//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to print binary representation of a number
void print_binary(unsigned int num)
{
    char binary[33]; // Maximum 32 bits + null terminator
    int i = 0;
    while (num > 0) {
        binary[i++] = (num & 1) + '0';
        num >>= 1;
    }
    binary[i] = '\0';
    printf("%s\n", binary);
}

// Function to perform bitwise operations
void bitwise_operations(unsigned int num1, unsigned int num2)
{
    unsigned int result;

    // Bitwise AND
    result = num1 & num2;
    printf("Bitwise AND: ");
    print_binary(result);

    // Bitwise OR
    result = num1 | num2;
    printf("Bitwise OR: ");
    print_binary(result);

    // Bitwise XOR
    result = num1 ^ num2;
    printf("Bitwise XOR: ");
    print_binary(result);

    // Bitwise NOT
    result = ~num1;
    printf("Bitwise NOT: ");
    print_binary(result);

    // Left shift
    result = num1 << 5;
    printf("Left shift by 5: ");
    print_binary(result);

    // Right shift
    result = num1 >> 3;
    printf("Right shift by 3: ");
    print_binary(result);
}

int main()
{
    unsigned int num1, num2;
    printf("Enter two unsigned integers:\n");
    scanf("%u %u", &num1, &num2);

    bitwise_operations(num1, num2);

    return 0;
}