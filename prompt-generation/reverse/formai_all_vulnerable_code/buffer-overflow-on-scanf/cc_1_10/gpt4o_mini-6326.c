//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

void printBinary(int n);
void bitwiseOperations(int a, int b);

int main() {
    int num1, num2;

    printf("Welcome to the Bitwise Operations Demonstration!\n");
    printf("Please enter two integers:\n");
    
    printf("Enter first integer (num1): ");
    scanf("%d", &num1);
    
    printf("Enter second integer (num2): ");
    scanf("%d", &num2);

    printf("\nYou entered:\nnum1 = %d\nnum2 = %d\n", num1, num2);
    
    printf("\nBinary representations:\n");
    printf("num1 in binary: ");
    printBinary(num1);
    printf("num2 in binary: ");
    printBinary(num2);
    
    // Call to the bitwise operations function
    bitwiseOperations(num1, num2);
    
    return 0;
}

// Function to print binary representation of a number
void printBinary(int n) {
    if (n == 0) {
        printf("0\n");
        return;
    }

    int mask = 1 << (sizeof(n) * 8 - 1); // Start mask at the leftmost bit
    int started = 0; // Flag to skip leading zeros

    for (int i = 0; i < sizeof(n) * 8; i++) {
        if (n & mask) {
            printf("1");
            started = 1; // We have started printing the bits
        } else if (started) {
            printf("0");
        }
        mask >>= 1; // Shift the mask to the right
    }
    
    if (!started) {
        printf("0"); // If the number is 0, print 0
    }
    printf("\n");
}

// Function to perform and display various bitwise operations
void bitwiseOperations(int a, int b) {
    printf("\nPerforming bitwise operations:\n");

    // Bitwise AND
    int andResult = a & b;
    printf("Bitwise AND (a & b): %d\n", andResult);
    printf("Binary representation of result: ");
    printBinary(andResult);

    // Bitwise OR
    int orResult = a | b;
    printf("Bitwise OR (a | b): %d\n", orResult);
    printf("Binary representation of result: ");
    printBinary(orResult);

    // Bitwise XOR
    int xorResult = a ^ b;
    printf("Bitwise XOR (a ^ b): %d\n", xorResult);
    printf("Binary representation of result: ");
    printBinary(xorResult);
    
    // Bitwise NOT
    int notA = ~a;
    int notB = ~b;
    printf("Bitwise NOT (~a): %d\n", notA);
    printf("Binary representation of NOT a: ");
    printBinary(notA);
    
    printf("Bitwise NOT (~b): %d\n", notB);
    printf("Binary representation of NOT b: ");
    printBinary(notB);
    
    // Left Shift
    int leftShiftA = a << 1;
    int leftShiftB = b << 1;
    printf("Left Shift (a << 1): %d\n", leftShiftA);
    printf("Binary representation of left shift of a: ");
    printBinary(leftShiftA);
    
    printf("Left Shift (b << 1): %d\n", leftShiftB);
    printf("Binary representation of left shift of b: ");
    printBinary(leftShiftB);
    
    // Right Shift
    int rightShiftA = a >> 1;
    int rightShiftB = b >> 1;
    printf("Right Shift (a >> 1): %d\n", rightShiftA);
    printf("Binary representation of right shift of a: ");
    printBinary(rightShiftA);
    
    printf("Right Shift (b >> 1): %d\n", rightShiftB);
    printf("Binary representation of right shift of b: ");
    printBinary(rightShiftB);
    
    printf("\nThanks for using the Bitwise Operations Demonstration!\n");
}