//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: automated
#include <stdio.h>

// Function to demonstrate various bitwise operations
void bitwiseOperationsDemo(int a, int b) {
    printf("Bitwise operations between %d and %d:\n", a, b);

    // Bitwise AND
    int andResult = a & b;
    printf("AND: %d & %d = %d (Binary: %08b & %08b = %08b)\n", a, b, andResult, a, b, andResult);

    // Bitwise OR
    int orResult = a | b;
    printf("OR: %d | %d = %d (Binary: %08b | %08b = %08b)\n", a, b, orResult, a, b, orResult);

    // Bitwise XOR
    int xorResult = a ^ b;
    printf("XOR: %d ^ %d = %d (Binary: %08b ^ %08b = %08b)\n", a, b, xorResult, a, b, xorResult);

    // Bitwise NOT
    int notA = ~a;
    int notB = ~b;
    printf("NOT: ~%d = %d (Binary: ~%08b = %08b)\n", a, notA, a, notA);
    printf("NOT: ~%d = %d (Binary: ~%08b = %08b)\n", b, notB, b, notB);

    // Left Shift
    int leftShiftA = a << 1;
    printf("Left Shift: %d << 1 = %d (Binary: %08b << 1 = %08b)\n", a, leftShiftA, a, leftShiftA);

    // Right Shift
    int rightShiftA = a >> 1;
    printf("Right Shift: %d >> 1 = %d (Binary: %08b >> 1 = %08b)\n", a, rightShiftA, a, rightShiftA);
}

// Function to calculate the number of bits required to represent a number
int bitsRequired(int number) {
    if (number == 0) {
        return 1;
    }
    
    int bits = 0;
    while (number > 0) {
        bits++;
        number >>= 1;
    }
    return bits;
}

// Function to demonstrate how to use bitwise flags
void flagDemo() {
    int flags = 0; // No flags set
    int FLAG_A = 1 << 0; // 0001
    int FLAG_B = 1 << 1; // 0010
    int FLAG_C = 1 << 2; // 0100
    int FLAG_D = 1 << 3; // 1000

    // Set FLAG_A and FLAG_B
    flags |= FLAG_A;
    flags |= FLAG_B;
    printf("Flags set: %d (Binary: %04b)\n", flags, flags);

    // Check if FLAG_C is set
    if (flags & FLAG_C) {
        printf("FLAG_C is set\n");
    } else {
        printf("FLAG_C is not set\n");
    }

    // Set FLAG_C
    flags |= FLAG_C;
    printf("Flags after setting FLAG_C: %d (Binary: %04b)\n", flags, flags);

    // Unset FLAG_A
    flags &= ~FLAG_A;
    printf("Flags after unsetting FLAG_A: %d (Binary: %04b)\n", flags, flags);
}

// Main function
int main() {
    int num1, num2;

    printf("Enter two integers (e.g. 5 3): ");
    scanf("%d %d", &num1, &num2);

    bitwiseOperationsDemo(num1, num2);
    
    // Bits required to represent a number
    printf("\nBits required to represent %d: %d bits\n", num1, bitsRequired(num1));
    printf("Bits required to represent %d: %d bits\n", num2, bitsRequired(num2));

    // Demonstrate flag usage
    flagDemo();

    return 0;
}