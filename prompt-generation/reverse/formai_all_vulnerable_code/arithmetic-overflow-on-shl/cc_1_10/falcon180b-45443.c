//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// define a structure to hold the bitwise operations results
typedef struct {
    int and_result;
    int or_result;
    int xor_result;
    int shift_result;
} BitwiseOperationsResults;

// function to perform bitwise AND operation
void bitwise_and(int num1, int num2, BitwiseOperationsResults* result) {
    result->and_result = num1 & num2;
}

// function to perform bitwise OR operation
void bitwise_or(int num1, int num2, BitwiseOperationsResults* result) {
    result->or_result = num1 | num2;
}

// function to perform bitwise XOR operation
void bitwise_xor(int num1, int num2, BitwiseOperationsResults* result) {
    result->xor_result = num1 ^ num2;
}

// function to perform bitwise shift operation
void bitwise_shift(int num, int shift, BitwiseOperationsResults* result) {
    result->shift_result = num << shift;
}

// main function
int main() {
    int num1;
    int num2;
    BitwiseOperationsResults results;

    // get user input for the numbers to perform bitwise operations on
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // perform bitwise AND operation
    printf("\nBitwise AND operation:\n");
    bitwise_and(num1, num2, &results);
    printf("Result: %d\n", results.and_result);

    // perform bitwise OR operation
    printf("\nBitwise OR operation:\n");
    bitwise_or(num1, num2, &results);
    printf("Result: %d\n", results.or_result);

    // perform bitwise XOR operation
    printf("\nBitwise XOR operation:\n");
    bitwise_xor(num1, num2, &results);
    printf("Result: %d\n", results.xor_result);

    // perform bitwise shift operation
    printf("\nBitwise shift operation:\n");
    bitwise_shift(num1, 2, &results);
    printf("Result: %d\n", results.shift_result);

    return 0;
}