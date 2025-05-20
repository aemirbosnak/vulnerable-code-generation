//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: scalable
#include <stdio.h>

// Function prototypes
void printBinary(unsigned int num);
unsigned int bitwiseAND(unsigned int a, unsigned int b);
unsigned int bitwiseOR(unsigned int a, unsigned int b);
unsigned int bitwiseXOR(unsigned int a, unsigned int b);
unsigned int bitwiseNOT(unsigned int a);
unsigned int leftShift(unsigned int a, int positions);
unsigned int rightShift(unsigned int a, int positions);

// Function to print binary representation of an unsigned integer
void printBinary(unsigned int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

// Function to perform bitwise AND
unsigned int bitwiseAND(unsigned int a, unsigned int b) {
    return a & b;
}

// Function to perform bitwise OR
unsigned int bitwiseOR(unsigned int a, unsigned int b) {
    return a | b;
}

// Function to perform bitwise XOR
unsigned int bitwiseXOR(unsigned int a, unsigned int b) {
    return a ^ b;
}

// Function to perform bitwise NOT
unsigned int bitwiseNOT(unsigned int a) {
    return ~a;
}

// Function to perform left shift
unsigned int leftShift(unsigned int a, int positions) {
    return a << positions;
}

// Function to perform right shift
unsigned int rightShift(unsigned int a, int positions) {
    return a >> positions;
}

// Main function
int main() {
    unsigned int a, b;
    int shiftPositions;

    // Take user input for two numbers
    printf("Enter two unsigned integers:\n");
    printf("Enter first number (a): ");
    scanf("%u", &a);
    printf("Enter second number (b): ");
    scanf("%u", &b);

    printf("\nBitwise operations on %u and %u:\n", a, b);
    printf("=============================================\n");

    // Display binary representations
    printf("Binary representation of a: ");
    printBinary(a);
    printf("Binary representation of b: ");
    printBinary(b);
    printf("\n");

    // Perform and display results for each operation
    unsigned int result;

    // AND
    result = bitwiseAND(a, b);
    printf("Bitwise AND (a & b): %u\nBinary: ", result);
    printBinary(result);

    // OR
    result = bitwiseOR(a, b);
    printf("Bitwise OR (a | b): %u\nBinary: ", result);
    printBinary(result);

    // XOR
    result = bitwiseXOR(a, b);
    printf("Bitwise XOR (a ^ b): %u\nBinary: ", result);
    printBinary(result);

    // NOT for 'a'
    result = bitwiseNOT(a);
    printf("Bitwise NOT (~a): %u\nBinary: ", result);
    printBinary(result);

    // NOT for 'b'
    result = bitwiseNOT(b);
    printf("Bitwise NOT (~b): %u\nBinary: ", result);
    printBinary(result);

    // Left Shift
    printf("\nEnter number of positions to left shift: ");
    scanf("%d", &shiftPositions);
    result = leftShift(a, shiftPositions);
    printf("Left shift of a by %d positions: %u\nBinary: ", shiftPositions, result);
    printBinary(result);

    // Right Shift
    printf("\nEnter number of positions to right shift: ");
    scanf("%d", &shiftPositions);
    result = rightShift(b, shiftPositions);
    printf("Right shift of b by %d positions: %u\nBinary: ", shiftPositions, result);
    printBinary(result);

    printf("\n=============================================\n");
    printf("End of Bitwise Operations Demo\n");

    return 0;
}