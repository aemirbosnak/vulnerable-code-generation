//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

// Structure to hold the binary number with its length
typedef struct {
    unsigned int bits[MAX_BITS];
    int length;
} BinaryNumber;

// Function prototypes
BinaryNumber createBinaryNumber(unsigned int value);
void displayBinaryNumber(BinaryNumber bin);
BinaryNumber bitwiseAnd(BinaryNumber a, BinaryNumber b);
BinaryNumber bitwiseOr(BinaryNumber a, BinaryNumber b);
BinaryNumber bitwiseXor(BinaryNumber a, BinaryNumber b);
BinaryNumber leftShift(BinaryNumber a, int positions);
BinaryNumber rightShift(BinaryNumber a, int positions);
unsigned int binaryToDecimal(BinaryNumber bin);

int main() {
    unsigned int value1 = 29; // Example value 1: 29 in decimal
    unsigned int value2 = 15; // Example value 2: 15 in decimal

    BinaryNumber bin1 = createBinaryNumber(value1);
    BinaryNumber bin2 = createBinaryNumber(value2);

    printf("Binary Representation of %u: ", value1);
    displayBinaryNumber(bin1);
    
    printf("Binary Representation of %u: ", value2);
    displayBinaryNumber(bin2);

    BinaryNumber andResult = bitwiseAnd(bin1, bin2);
    printf("\nBitwise AND Result: ");
    displayBinaryNumber(andResult);

    BinaryNumber orResult = bitwiseOr(bin1, bin2);
    printf("\nBitwise OR Result: ");
    displayBinaryNumber(orResult);

    BinaryNumber xorResult = bitwiseXor(bin1, bin2);
    printf("\nBitwise XOR Result: ");
    displayBinaryNumber(xorResult);

    int shiftAmount = 2;
    BinaryNumber leftShiftResult = leftShift(bin1, shiftAmount);
    printf("\nLeft Shift (by %d) Result: ", shiftAmount);
    displayBinaryNumber(leftShiftResult);

    BinaryNumber rightShiftResult = rightShift(bin1, shiftAmount);
    printf("\nRight Shift (by %d) Result: ", shiftAmount);
    displayBinaryNumber(rightShiftResult);

    printf("\nDecimal value of AND Result: %u", binaryToDecimal(andResult));
    printf("\nDecimal value of OR Result: %u", binaryToDecimal(orResult));
    printf("\nDecimal value of XOR Result: %u", binaryToDecimal(xorResult));
    printf("\nDecimal value of Left Shift Result: %u", binaryToDecimal(leftShiftResult));
    printf("\nDecimal value of Right Shift Result: %u\n", binaryToDecimal(rightShiftResult));

    return 0;
}

// Create a BinaryNumber from an unsigned integer value
BinaryNumber createBinaryNumber(unsigned int value) {
    BinaryNumber bin;
    bin.length = 0;

    for (int i = 0; i < MAX_BITS; i++) {
        bin.bits[i] = (value >> (MAX_BITS - 1 - i)) & 1; // Store binary bits
        if (bin.bits[i] == 1) {
            bin.length = i + 1; // Update length if a bit is set
        }
    }

    return bin;
}

// Display the binary number
void displayBinaryNumber(BinaryNumber bin) {
    for (int i = 0; i < bin.length; i++) {
        printf("%u", bin.bits[i]);
    }
    printf(" (Length: %d)\n", bin.length);
}

// Bitwise AND operation
BinaryNumber bitwiseAnd(BinaryNumber a, BinaryNumber b) {
    BinaryNumber result;
    result.length = a.length > b.length ? a.length : b.length;

    for (int i = 0; i < result.length; i++) {
        result.bits[i] = (a.bits[i] & b.bits[i]) ? 1 : 0;
    }

    return result;
}

// Bitwise OR operation
BinaryNumber bitwiseOr(BinaryNumber a, BinaryNumber b) {
    BinaryNumber result;
    result.length = a.length > b.length ? a.length : b.length;

    for (int i = 0; i < result.length; i++) {
        result.bits[i] = (a.bits[i] | b.bits[i]) ? 1 : 0;
    }

    return result;
}

// Bitwise XOR operation
BinaryNumber bitwiseXor(BinaryNumber a, BinaryNumber b) {
    BinaryNumber result;
    result.length = a.length > b.length ? a.length : b.length;

    for (int i = 0; i < result.length; i++) {
        result.bits[i] = (a.bits[i] ^ b.bits[i]) ? 1 : 0;
    }

    return result;
}

// Left shift operation
BinaryNumber leftShift(BinaryNumber a, int positions) {
    BinaryNumber result;
    result.length = a.length + positions;

    for (int i = 0; i < result.length; i++) {
        result.bits[i] = (i < positions) ? 0 : a.bits[i - positions];
    }

    return result;
}

// Right shift operation
BinaryNumber rightShift(BinaryNumber a, int positions) {
    BinaryNumber result;
    result.length = a.length > positions ? a.length - positions : 0;

    for (int i = 0; i < result.length; i++) {
        result.bits[i] = a.bits[i + positions];
    }

    return result;
}

// Convert BinaryNumber to decimal value
unsigned int binaryToDecimal(BinaryNumber bin) {
    unsigned int decimalValue = 0;
    for (int i = 0; i < bin.length; i++) {
        decimalValue = (decimalValue << 1) | bin.bits[i];
    }
    return decimalValue;
}