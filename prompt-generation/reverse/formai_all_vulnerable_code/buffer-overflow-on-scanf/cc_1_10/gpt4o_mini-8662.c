//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Function to print the binary representation of a number
void printBinary(unsigned int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        putchar((num & (1 << i)) ? '1' : '0');
        if (i % 4 == 0) putchar(' '); // Add spacing for readability
    }
    putchar('\n');
}

// Function to demonstrate various bitwise operations
void bitwiseOperationsDemo(unsigned int x, unsigned int y) {
    unsigned int andResult = x & y;
    unsigned int orResult = x | y;
    unsigned int xorResult = x ^ y;
    unsigned int notResultX = ~x;
    unsigned int notResultY = ~y;
    unsigned int leftShiftX = x << 1;  // Left shift x by 1
    unsigned int rightShiftX = x >> 1; // Right shift x by 1

    // Display results
    printf("Decimal Representation:\n");
    printf("x = %u, y = %u\n", x, y);
    
    printf("\nBitwise Operations:\n");
    printf("AND (x & y):         %u\n", andResult);
    printf("OR (x | y):          %u\n", orResult);
    printf("XOR (x ^ y):         %u\n", xorResult);
    printf("NOT (~x):            %u\n", notResultX);
    printf("NOT (~y):            %u\n", notResultY);
    printf("Left Shift (x << 1): %u\n", leftShiftX);
    printf("Right Shift (x >> 1): %u\n", rightShiftX);

    printf("\nBinary Representation:\n");
    printf("x:               ");
    printBinary(x);
    printf("y:               ");
    printBinary(y);
    printf("AND (x & y):     ");
    printBinary(andResult);
    printf("OR (x | y):      ");
    printBinary(orResult);
    printf("XOR (x ^ y):     ");
    printBinary(xorResult);
    printf("NOT (~x):        ");
    printBinary(notResultX);
    printf("NOT (~y):        ");
    printBinary(notResultY);
    printf("Left Shift (x << 1): ");
    printBinary(leftShiftX);
    printf("Right Shift (x >> 1): ");
    printBinary(rightShiftX);
}

// Function to toggle specific bits within a number
unsigned int toggleBits(unsigned int num, unsigned int positions) {
    return num ^ positions;
}

int main() {
    unsigned int x, y, positions;

    // User inputs
    printf("Enter the first number (x): ");
    scanf("%u", &x);
    printf("Enter the second number (y): ");
    scanf("%u", &y);
    
    bitwiseOperationsDemo(x, y);

    // Toggle bits based on user input
    printf("\nEnter the positions to toggle (in binary): ");
    scanf("%u", &positions);
    unsigned int toggledResult = toggleBits(x, positions);
    
    printf("\nToggling bits of x (0x%X) with positions (0x%X):\n", x, positions);
    printf("Result of toggle: 0x%X\n", toggledResult);
    printf("Toggled binary representation: ");
    printBinary(toggledResult);

    return 0;
}