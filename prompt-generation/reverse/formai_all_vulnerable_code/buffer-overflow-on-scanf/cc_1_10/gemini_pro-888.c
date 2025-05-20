//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
int decimalToBinary(int decimalNumber) {
    int binaryNumber = 0;
    int remainder, i = 1;

    while (decimalNumber!=0) {
        remainder = decimalNumber%2;
        decimalNumber /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}

// Function to convert a binary number to decimal
int binaryToDecimal(int binaryNumber) {
    int decimalNumber = 0, i = 0, remainder;

    while (binaryNumber!=0) {
        remainder = binaryNumber%10;
        binaryNumber /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

int main() {
    int decimalNumber, binaryNumber;

    // Get the decimal number from the user
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert the decimal number to binary
    binaryNumber = decimalToBinary(decimalNumber);

    // Print the binary number
    printf("The binary representation of %d is %d\n", decimalNumber, binaryNumber);

    // Get the binary number from the user
    printf("Enter a binary number: ");
    scanf("%d", &binaryNumber);

    // Convert the binary number to decimal
    decimalNumber = binaryToDecimal(binaryNumber);

    // Print the decimal number
    printf("The decimal representation of %d is %d\n", binaryNumber, decimalNumber);

    return 0;
}