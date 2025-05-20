//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>

// Function prototypes
void displayBinary(int num);
void performBitwiseOperations(int a, int b);

int main() {
    int num1, num2;

    // User input for two integers
    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Enter the second integer: ");
    scanf("%d", &num2);

    // Display the binary representation of both numbers
    printf("\nBinary representation of %d: ", num1);
    displayBinary(num1);
    printf("Binary representation of %d: ", num2);
    displayBinary(num2);

    // Perform and display the results of bitwise operations
    performBitwiseOperations(num1, num2);

    return 0;
}

// Function to display the binary representation of a number
void displayBinary(int num) {
    for (int i = (sizeof(num) * 8) - 1; i >= 0; i--) {
        // Using bitwise shift and mask to determine 0 or 1
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

// Function to perform and display bitwise operations
void performBitwiseOperations(int a, int b) {
    int andResult = a & b;
    int orResult = a | b;
    int xorResult = a ^ b;
    int notA = ~a;
    int notB = ~b;

    // Results display
    printf("\nBitwise Operations Results:\n");
    printf("A (binary): ");
    displayBinary(a);
    printf("B (binary): ");
    displayBinary(b);
    
    printf("\nA AND B: \n");
    displayBinary(andResult);
    printf("Decimal result: %d\n", andResult);

    printf("\nA OR B: \n");
    displayBinary(orResult);
    printf("Decimal result: %d\n", orResult);

    printf("\nA XOR B: \n");
    displayBinary(xorResult);
    printf("Decimal result: %d\n", xorResult);

    printf("\nNOT A: \n");
    displayBinary(notA);
    printf("Decimal result: %d\n", notA);

    printf("\nNOT B: \n");
    displayBinary(notB);
    printf("Decimal result: %d\n", notB);
    
    // Display a final separation line for aesthetics
    printf("\n-----------------------------------\n");
    
    // Example of left shift and right shift
    int leftShiftA = a << 1;
    int rightShiftA = a >> 1;
    printf("\nLeft shift A (<< 1): \n");
    displayBinary(leftShiftA);
    printf("Decimal result: %d\n", leftShiftA);
    
    printf("\nRight shift A (>> 1): \n");
    displayBinary(rightShiftA);
    printf("Decimal result: %d\n", rightShiftA);
    
    // Example of left shift and right shift on B
    int leftShiftB = b << 1;
    int rightShiftB = b >> 1;
    printf("\nLeft shift B (<< 1): \n");
    displayBinary(leftShiftB);
    printf("Decimal result: %d\n", leftShiftB);
    
    printf("\nRight shift B (>> 1): \n");
    displayBinary(rightShiftB);
    printf("Decimal result: %d\n", rightShiftB);
    
    // Final separation line
    printf("-----------------------------------\n");
}