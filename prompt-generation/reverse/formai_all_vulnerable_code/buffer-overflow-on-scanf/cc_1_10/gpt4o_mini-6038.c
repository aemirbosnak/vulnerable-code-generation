//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: irregular
#include <stdio.h>

void printBits(unsigned n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        putchar((n & (1U << i)) ? '1' : '0');
    }
    putchar('\n');
}

unsigned magicBox(unsigned num1, unsigned num2) {
    unsigned result = 0;

    // Performing a series of bitwise operations
    result |= (num1 & num2);         // AND operation
    result ^= (num1 | num2);         // XOR operation
    result = ~result;                 // NOT operation
    result = (result << 1) | (result >> (sizeof(result) * 8 - 1)); // Circular shift
    return result;
}

int main() {
    unsigned input1, input2;
    printf("Welcome to the Magic Box of Bitwise Wonders!\n");
    
    printf("Enter the first integer (decimal): ");
    scanf("%u", &input1);
    
    printf("Enter the second integer (decimal): ");
    scanf("%u", &input2);
    
    printf("\nYou have chosen:\n");
    printf("First Integer: %u\n", input1);
    printf("Second Integer: %u\n", input2);
    
    printf("\nIn binary form:\n");
    printf("First Integer in binary: ");
    printBits(input1);
    printf("Second Integer in binary: ");
    printBits(input2);
    
    unsigned result = magicBox(input1, input2);
    
    printf("\nThe magical result of your inputs in binary form:\n");
    printBits(result);
    
    printf("In decimal form, the result is: %u\n", result);
    
    // Demonstrating various bitwise operations:
    unsigned shiftedLeft = input1 << 2;
    unsigned shiftedRight = input1 >> 2;
    unsigned bitAnd = input1 & input2;
    unsigned bitOr = input1 | input2;
    unsigned bitXor = input1 ^ input2;
    unsigned bitNot = ~input1;

    printf("\nLet's play with some more bitwise tricks!\n");
    printf("Left shift first integer by 2: %u (Binary: ", shiftedLeft);
    printBits(shiftedLeft);

    printf("Right shift first integer by 2: %u (Binary: ", shiftedRight);
    printBits(shiftedRight);

    printf("AND operation with the two integers: %u (Binary: ", bitAnd);
    printBits(bitAnd);

    printf("OR operation with the two integers: %u (Binary: ", bitOr);
    printBits(bitOr);

    printf("XOR operation with the two integers: %u (Binary: ", bitXor);
    printBits(bitXor);

    printf("NOT operation on the first integer: %u (Binary: ", bitNot);
    printBits(bitNot);
    
    printf("\nThanks for using the Magic Box of Bitwise Wonders!\n");
    return 0;
}