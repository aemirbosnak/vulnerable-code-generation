//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to represent integer in binary format
void printBinary(unsigned int num) {
    for(int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        putchar((num & (1 << i)) ? '1' : '0');
    }
    putchar('\n');
}

// Function to demonstrate bitwise operations
void bitwiseOperationsDemo(unsigned int a, unsigned int b) {
    printf("Bitwise Operations between %u (", a);
    printBinary(a);
    printf(") and %u (", b);
    printBinary(b);
    printf("):\n");

    printf("AND operation: %u (", a & b);
    printBinary(a & b);
    
    printf("OR operation: %u (", a | b);
    printBinary(a | b);

    printf("XOR operation: %u (", a ^ b);
    printBinary(a ^ b);

    printf("NOT operation on %u: %u (", a, ~a);
    printBinary(~a);

    printf("Left Shift %u by 2: %u (", a, a << 2);
    printBinary(a << 2);
    
    printf("Right Shift %u by 2: %u (", a, a >> 2);
    printBinary(a >> 2);
}

int main() {
    unsigned int input1, input2;

    printf("Enter first non-negative integer: ");
    if (scanf("%u", &input1) != 1) {
        fprintf(stderr, "Invalid input. Please provide a non-negative integer.\n");
        return EXIT_FAILURE;
    }

    printf("Enter second non-negative integer: ");
    if (scanf("%u", &input2) != 1) {
        fprintf(stderr, "Invalid input. Please provide a non-negative integer.\n");
        return EXIT_FAILURE;
    }

    // Check inputs for non-negativity
    if (input1 < 0 || input2 < 0) {
        fprintf(stderr, "Please enter non-negative integers only.\n");
        return EXIT_FAILURE;
    }

    // Demonstrate bitwise operations
    bitwiseOperationsDemo(input1, input2);
    
    // Additional manipulation example
    unsigned int number;
    printf("Enter an integer to demonstrate toggling bits: ");
    if (scanf("%u", &number) != 1) {
        fprintf(stderr, "Invalid input. Please provide a non-negative integer.\n");
        return EXIT_FAILURE;
    }

    printf("Initial number: %u (", number);
    printBinary(number);

    unsigned int mask = 0b00000000000000000000000000000101; // Mask to toggle the last two bits
    number ^= mask;

    printf("Number after toggling with mask %u (", mask);
    printBinary(mask);
    printf(": %u (", number);
    printBinary(number);
    
    // Final confirmation of bitwise operation results
    printf("Bitwise operations have concluded successfully!\n");
    return EXIT_SUCCESS;
}