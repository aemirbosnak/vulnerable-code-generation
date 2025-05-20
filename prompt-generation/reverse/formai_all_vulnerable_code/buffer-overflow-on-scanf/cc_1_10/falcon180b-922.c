//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Function to perform bitwise AND operation
unsigned int bitwise_and(unsigned int a, unsigned int b) {
    if (a == 0) {
        return 0;
    }
    return a & b;
}

// Function to perform bitwise OR operation
unsigned int bitwise_or(unsigned int a, unsigned int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    return a | b;
}

// Function to perform bitwise XOR operation
unsigned int bitwise_xor(unsigned int a, unsigned int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    return a ^ b;
}

// Function to perform bitwise NOT operation
unsigned int bitwise_not(unsigned int a) {
    return ~a;
}

// Recursive function to perform bitwise left shift operation
unsigned int bitwise_left_shift(unsigned int a, unsigned int n) {
    if (n == 0) {
        return a;
    }
    return bitwise_left_shift(a, n - 1) << 1;
}

// Recursive function to perform bitwise right shift operation
unsigned int bitwise_right_shift(unsigned int a, unsigned int n) {
    if (n == 0) {
        return a;
    }
    return bitwise_right_shift(a, n - 1) >> 1;
}

int main() {
    unsigned int num1, num2, result;
    char operation;

    // Get user input for two numbers and bitwise operation
    printf("Enter two numbers and the bitwise operation to perform:\n");
    scanf("%u %u %c", &num1, &num2, &operation);

    // Perform bitwise operation recursively
    switch(operation) {
        case '&':
            result = bitwise_and(num1, num2);
            break;
        case '|':
            result = bitwise_or(num1, num2);
            break;
        case '^':
            result = bitwise_xor(num1, num2);
            break;
        case '~':
            result = bitwise_not(num1);
            break;
        case '<<':
            result = bitwise_left_shift(num1, num2);
            break;
        case '>>':
            result = bitwise_right_shift(num1, num2);
            break;
        default:
            printf("Invalid operation!\n");
            return 0;
    }

    // Print the result
    printf("Result: %u\n", result);

    return 0;
}