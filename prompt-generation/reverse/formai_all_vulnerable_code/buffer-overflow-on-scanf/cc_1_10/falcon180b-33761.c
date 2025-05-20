//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

// Function to perform bitwise AND operation recursively
unsigned int bitwise_and_recursive(unsigned int num1, unsigned int num2) {
    if (num2 == 0) {
        return 0;
    }
    return num1 & num2 + bitwise_and_recursive(num1, num2 >> 1);
}

// Function to perform bitwise OR operation recursively
unsigned int bitwise_or_recursive(unsigned int num1, unsigned int num2) {
    if (num2 == 0) {
        return num1;
    }
    return num1 | bitwise_or_recursive(num1, num2 >> 1);
}

// Function to perform bitwise XOR operation recursively
unsigned int bitwise_xor_recursive(unsigned int num1, unsigned int num2) {
    if (num2 == 0) {
        return num1;
    }
    return num1 ^ bitwise_xor_recursive(num1, num2 >> 1);
}

// Function to perform bitwise NOT operation recursively
unsigned int bitwise_not_recursive(unsigned int num) {
    if (num == 0) {
        return ~num;
    }
    return ~bitwise_not_recursive(num >> 1) << 1;
}

int main() {
    unsigned int num1, num2;
    char operation;

    // Taking input from user
    printf("Enter the first number: ");
    scanf("%u", &num1);
    printf("Enter the second number: ");
    scanf("%u", &num2);
    printf("Enter the operation (+ for AND, * for OR, ^ for XOR, # for NOT): ");
    scanf(" %c", &operation);

    // Performing bitwise operation recursively
    switch (operation) {
        case '+':
            printf("Result of AND operation is: %u\n", bitwise_and_recursive(num1, num2));
            break;
        case '*':
            printf("Result of OR operation is: %u\n", bitwise_or_recursive(num1, num2));
            break;
        case '^':
            printf("Result of XOR operation is: %u\n", bitwise_xor_recursive(num1, num2));
            break;
        case '#':
            printf("Result of NOT operation is: %u\n", bitwise_not_recursive(num1));
            break;
        default:
            printf("Invalid operation!\n");
    }

    return 0;
}