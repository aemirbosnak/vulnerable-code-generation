//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to perform bitwise AND operation recursively
unsigned int bitwise_and(unsigned int a, unsigned int b) {
    if (b == 0) {
        return 0;
    }
    else {
        return (a & b) + (bitwise_and(a, b - 1));
    }
}

// Function to perform bitwise OR operation recursively
unsigned int bitwise_or(unsigned int a, unsigned int b) {
    if (b == 0) {
        return a;
    }
    else {
        return (a | b) + (bitwise_or(a, b - 1));
    }
}

// Function to perform bitwise XOR operation recursively
unsigned int bitwise_xor(unsigned int a, unsigned int b) {
    if (b == 0) {
        return a;
    }
    else {
        return (a ^ b) + (bitwise_xor(a, b - 1));
    }
}

// Function to perform bitwise NOT operation recursively
unsigned int bitwise_not(unsigned int a) {
    if (a == 0) {
        return 1;
    }
    else {
        return (1 << (sizeof(unsigned int) * 8 - 1)) + (bitwise_not(a - 1));
    }
}

// Function to perform bitwise left shift operation recursively
unsigned int bitwise_left_shift(unsigned int a, unsigned int b) {
    if (b == 0) {
        return a;
    }
    else {
        return (a << 1) + (bitwise_left_shift(a, b - 1));
    }
}

// Function to perform bitwise right shift operation recursively
unsigned int bitwise_right_shift(unsigned int a, unsigned int b) {
    if (b == 0) {
        return a;
    }
    else {
        return (a >> 1) + (bitwise_right_shift(a, b - 1));
    }
}

int main() {
    unsigned int num1, num2, result;
    int choice;

    printf("Enter two numbers: ");
    scanf("%u %u", &num1, &num2);

    printf("Enter the operation you want to perform:\n1. Bitwise AND\n2. Bitwise OR\n3. Bitwise XOR\n4. Bitwise NOT\n5. Bitwise left shift\n6. Bitwise right shift\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = bitwise_and(num1, num2);
            printf("Result: %u\n", result);
            break;
        case 2:
            result = bitwise_or(num1, num2);
            printf("Result: %u\n", result);
            break;
        case 3:
            result = bitwise_xor(num1, num2);
            printf("Result: %u\n", result);
            break;
        case 4:
            result = bitwise_not(num1);
            printf("Result: %u\n", result);
            break;
        case 5:
            result = bitwise_left_shift(num1, num2);
            printf("Result: %u\n", result);
            break;
        case 6:
            result = bitwise_right_shift(num1, num2);
            printf("Result: %u\n", result);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}