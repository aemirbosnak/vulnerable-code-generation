//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

// Function to display binary representation of a number
void displayBinary(unsigned int num) {
    // Create an array to hold the binary representation
    char binary[33];
    binary[32] = '\0'; // Null-terminate the string
    for (int i = 31; i >= 0; i--) {
        binary[i] = (num & 1) ? '1' : '0';
        num >>= 1; // Shift right by 1 to process the next bit
    }
    printf("Binary: %s\n", binary);
}

int main() {
    unsigned int num1, num2;

    printf("Enter the first number (between 0 and 255): ");
    scanf("%u", &num1);
    printf("Enter the second number (between 0 and 255): ");
    scanf("%u", &num2);

    // Display the original numbers
    printf("\nOriginal Numbers:\n");
    printf("Number 1: %u\n", num1);
    printf("Number 2: %u\n", num2);

    // Display their binary representations
    printf("\nBinary Representations:\n");
    displayBinary(num1);
    displayBinary(num2);

    // Perform bitwise AND
    unsigned int andResult = num1 & num2;
    printf("\nBitwise AND of %u and %u: %u\n", num1, num2, andResult);
    displayBinary(andResult);

    // Perform bitwise OR
    unsigned int orResult = num1 | num2;
    printf("\nBitwise OR of %u and %u: %u\n", num1, num2, orResult);
    displayBinary(orResult);

    // Perform bitwise XOR
    unsigned int xorResult = num1 ^ num2;
    printf("\nBitwise XOR of %u and %u: %u\n", num1, num2, xorResult);
    displayBinary(xorResult);

    // Perform bitwise NOT on the first number
    unsigned int notResult = ~num1;
    printf("\nBitwise NOT of %u: %u\n", num1, notResult);
    displayBinary(notResult);

    // Shift left by 1 (equivalent to multiplying by 2)
    unsigned int leftShiftResult = num1 << 1;
    printf("\nLeft Shift of %u by 1: %u\n", num1, leftShiftResult);
    displayBinary(leftShiftResult);

    // Shift right by 1 (equivalent to dividing by 2)
    unsigned int rightShiftResult = num1 >> 1;
    printf("\nRight Shift of %u by 1: %u\n", num1, rightShiftResult);
    displayBinary(rightShiftResult);

    // Combine results in a summary
    printf("\nSummary of Results:\n");
    printf("AND: %u\nOR: %u\nXOR: %u\nNOT: %u\nLeft Shift: %u\nRight Shift: %u\n",
           andResult, orResult, xorResult, notResult, leftShiftResult, rightShiftResult);

    return 0;
}