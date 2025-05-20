//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BITS 8

// Function to print a binary number
void print_binary(unsigned int num) {
    char binary[NUM_BITS + 1];
    binary[NUM_BITS] = '\0';
    int i;
    for (i = NUM_BITS - 1; i >= 0; i--) {
        binary[i] = (num >> i) & 1? '1' : '0';
    }
    printf("%s\n", binary);
}

// Function to perform bitwise operations
void bitwise_operations(int num1, int num2) {
    unsigned int result = 0;

    printf("AND:\t");
    result = num1 & num2;
    print_binary(result);

    printf("OR:\t");
    result = num1 | num2;
    print_binary(result);

    printf("XOR:\t");
    result = num1 ^ num2;
    print_binary(result);

    printf("NOT:\t");
    result = ~num1;
    print_binary(result);

    printf("LEFT SHIFT:\t");
    result = num1 << 2;
    print_binary(result);

    printf("RIGHT SHIFT:\t");
    result = num1 >> 2;
    print_binary(result);
}

int main() {
    int num1, num2;

    printf("Enter first number:\t");
    scanf("%d", &num1);

    printf("Enter second number:\t");
    scanf("%d", &num2);

    bitwise_operations(num1, num2);

    return 0;
}