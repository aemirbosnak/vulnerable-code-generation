//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

// Function to perform bitwise AND operation
void bitwise_and(unsigned int num1, unsigned int num2) {
    unsigned int result = num1 & num2;
    printf("Bitwise AND result: %u\n", result);
}

// Function to perform bitwise OR operation
void bitwise_or(unsigned int num1, unsigned int num2) {
    unsigned int result = num1 | num2;
    printf("Bitwise OR result: %u\n", result);
}

// Function to perform bitwise XOR operation
void bitwise_xor(unsigned int num1, unsigned int num2) {
    unsigned int result = num1 ^ num2;
    printf("Bitwise XOR result: %u\n", result);
}

// Function to perform bitwise NOT operation
void bitwise_not(unsigned int num) {
    unsigned int result = ~num;
    printf("Bitwise NOT result: %u\n", result);
}

// Function to perform bitwise left shift operation
void bitwise_left_shift(unsigned int num, int shift) {
    unsigned int result = num << shift;
    printf("Bitwise left shift result: %u\n", result);
}

// Function to perform bitwise right shift operation
void bitwise_right_shift(unsigned int num, int shift) {
    unsigned int result = num >> shift;
    printf("Bitwise right shift result: %u\n", result);
}

int main() {
    unsigned int num1, num2, shift;

    // Taking input from user
    printf("Enter two numbers: ");
    scanf("%u %u", &num1, &num2);

    // Performing bitwise AND operation
    bitwise_and(num1, num2);

    // Performing bitwise OR operation
    bitwise_or(num1, num2);

    // Performing bitwise XOR operation
    bitwise_xor(num1, num2);

    // Performing bitwise NOT operation
    bitwise_not(num1);

    // Performing bitwise left shift operation
    printf("Enter shift value: ");
    scanf("%d", &shift);
    bitwise_left_shift(num1, shift);

    // Performing bitwise right shift operation
    printf("Enter shift value: ");
    scanf("%d", &shift);
    bitwise_right_shift(num1, shift);

    return 0;
}