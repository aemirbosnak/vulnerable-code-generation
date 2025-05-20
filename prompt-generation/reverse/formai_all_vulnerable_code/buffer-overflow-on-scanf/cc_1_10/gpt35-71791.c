//FormAI DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

// Function to perform bitwise AND operation
int bitwise_AND(int num1, int num2) {
    if (num1 == 0 || num2 == 0) {
        return 0;
    }
    else {
        return ((num1 & 1) & (num2 & 1)) + (bitwise_AND(num1 >> 1, num2 >> 1) << 1);
    }
}

// Function to perform bitwise OR operation
int bitwise_OR(int num1, int num2) {
    if (num1 == 0 && num2 == 0) {
        return 0;
    }
    else {
        return ((num1 & 1) | (num2 & 1)) + (bitwise_OR(num1 >> 1, num2 >> 1) << 1);
    }
}

// Function to perform bitwise XOR operation
int bitwise_XOR(int num1, int num2) {
    if (num1 == 0 && num2 == 0) {
        return 0;
    }
    else {
        return ((num1 & 1) ^ (num2 & 1)) + (bitwise_XOR(num1 >> 1, num2 >> 1) << 1);
    }
}

// Function to perform bitwise NOT operation
int bitwise_NOT(int num) {
    return (~num);
}

int main() {
    int num1, num2;

    // Input two integer numbers
    printf("Enter two integer numbers: ");
    scanf("%d %d", &num1, &num2);

    // Bitwise AND operation
    printf("\nBitwise AND: %d & %d = %d\n", num1, num2, bitwise_AND(num1, num2));

    // Bitwise OR operation
    printf("\nBitwise OR: %d | %d = %d\n", num1, num2, bitwise_OR(num1, num2));

    // Bitwise XOR operation
    printf("\nBitwise XOR: %d ^ %d = %d\n", num1, num2, bitwise_XOR(num1, num2));

    // Bitwise NOT operation
    printf("\nBitwise NOT: ~%d = %d\n", num1, bitwise_NOT(num1));
    
    return 0;
}