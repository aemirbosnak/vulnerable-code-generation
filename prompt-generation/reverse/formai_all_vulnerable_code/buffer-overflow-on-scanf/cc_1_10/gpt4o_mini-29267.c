//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: portable
#include <stdio.h>

// Function to print the binary representation of a number
void printBinary(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// Function to perform bitwise operations and show the results
void bitwiseOperationsDemo(unsigned int a, unsigned int b) {
    printf("Bitwise Operations between %u and %u:\n", a, b);
    
    printf("A: ");
    printBinary(a);
    
    printf("B: ");
    printBinary(b);

    printf("A AND B: ");
    unsigned int andResult = a & b;
    printBinary(andResult);

    printf("A OR B: ");
    unsigned int orResult = a | b;
    printBinary(orResult);
    
    printf("A XOR B: ");
    unsigned int xorResult = a ^ b;
    printBinary(xorResult);

    printf("NOT A: ");
    unsigned int notA = ~a;
    printBinary(notA);
    
    printf("NOT B: ");
    unsigned int notB = ~b;
    printBinary(notB);
    
    printf("A LEFT SHIFT 1: ");
    unsigned int leftShiftA = a << 1;
    printBinary(leftShiftA);
    
    printf("B LEFT SHIFT 1: ");
    unsigned int leftShiftB = b << 1;
    printBinary(leftShiftB);
    
    printf("A RIGHT SHIFT 1: ");
    unsigned int rightShiftA = a >> 1;
    printBinary(rightShiftA);
    
    printf("B RIGHT SHIFT 1: ");
    unsigned int rightShiftB = b >> 1;
    printBinary(rightShiftB);
    
    printf("\n");
}

int main() {
    unsigned int num1, num2;

    printf("Bitwise Operations Demonstration\n");
    
    // Input two numbers
    printf("Enter first number (0 to 4294967295): ");
    scanf("%u", &num1);
    
    printf("Enter second number (0 to 4294967295): ");
    scanf("%u", &num2);

    // Performing bitwise operations demo
    bitwiseOperationsDemo(num1, num2);

    return 0;
}