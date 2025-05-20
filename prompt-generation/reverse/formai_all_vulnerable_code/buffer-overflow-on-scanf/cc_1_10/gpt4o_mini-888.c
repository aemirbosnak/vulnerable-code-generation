//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>

// Function to display binary representation of a number
void displayBinary(int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) {
            printf(" "); // Formatting for better readability
        }
    }
    printf("\n");
}

// Function to perform bitwise operations
void bitwiseOperations(int a, int b) {
    int and_result = a & b;
    int or_result = a | b;
    int xor_result = a ^ b;
    int not_a = ~a;
    int not_b = ~b;
    int left_shift_a = a << 1;
    int left_shift_b = b << 1;
    int right_shift_a = a >> 1;
    int right_shift_b = b >> 1;

    printf("Bitwise Operations between:\n");
    printf("A = %d\tB = %d\n", a, b);
    printf("Binary Representation:\n");
    printf("A = ");
    displayBinary(a);
    printf("B = ");
    displayBinary(b);
    printf("AND: %d\t", and_result);
    displayBinary(and_result);
    printf("OR: %d\t", or_result);
    displayBinary(or_result);
    printf("XOR: %d\t", xor_result);
    displayBinary(xor_result);
    printf("NOT A: %d\t", not_a);
    displayBinary(not_a);
    printf("NOT B: %d\t", not_b);
    displayBinary(not_b);
    printf("Left Shift A: %d\t", left_shift_a);
    displayBinary(left_shift_a);
    printf("Left Shift B: %d\t", left_shift_b);
    displayBinary(left_shift_b);
    printf("Right Shift A: %d\t", right_shift_a);
    displayBinary(right_shift_a);
    printf("Right Shift B: %d\t", right_shift_b);
    displayBinary(right_shift_b);
    printf("\n");
}

// Function to toggle bits
int toggleBits(int num) {
    return ~num;
}

// Main function
int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Perform bitwise operations
    bitwiseOperations(a, b);

    // Toggle bits of both numbers
    int toggled_a = toggleBits(a);
    int toggled_b = toggleBits(b);

    printf("Toggled values:\n");
    printf("Toggled A: %d\t", toggled_a);
    displayBinary(toggled_a);
    printf("Toggled B: %d\t", toggled_b);
    displayBinary(toggled_b);

    // Demonstrating applications of bitwise operations
    printf("Appyling a mask of 0x0F (Only looks at the last 4 bits)\n");
    int mask = 0x0F;
    printf("A masked: %d\t", a & mask);
    displayBinary(a & mask);
    printf("B masked: %d\t", b & mask);
    displayBinary(b & mask);

    // Check if the number is even or odd using bitwise AND
    printf("Checking if A and B are even or odd:\n");
    printf("A is %s\n", (a & 1) ? "Odd" : "Even");
    printf("B is %s\n", (b & 1) ? "Odd" : "Even");

    return 0;
}