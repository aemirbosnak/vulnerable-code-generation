//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function to convert a binary number to its decimal equivalent
int binaryToDecimal(int binaryNumber) {
    int decimalNumber = 0, i = 0, remainder;

    while (binaryNumber != 0) {
        remainder = binaryNumber % 10;
        decimalNumber = decimalNumber + remainder * pow(2, i);
        i++;
        binaryNumber /= 10;
    }

    return decimalNumber;
}

// Function to convert a decimal number to its binary equivalent
int decimalToBinary(int decimalNumber) {
    int binaryNumber = 0, i = 0, remainder;

    while (decimalNumber != 0) {
        remainder = decimalNumber % 2;
        binaryNumber = binaryNumber + remainder * pow(10, i);
        i++;
        decimalNumber /= 2;
    }

    return binaryNumber;
}

// Function to print the binary representation of a number
void printBinary(int number) {
    int binaryNumber = decimalToBinary(number);

    printf("Binary representation of %d: %d\n", number, binaryNumber);
}

// Function to print the decimal representation of a number
void printDecimal(int number) {
    int decimalNumber = binaryToDecimal(number);

    printf("Decimal representation of %d: %d\n", number, decimalNumber);
}

// Main function
int main() {
    int number;

    // Get the number from the user
    printf("Enter a number: ");
    scanf("%d", &number);

    // Print the binary representation of the number
    printBinary(number);

    // Print the decimal representation of the number
    printDecimal(number);

    return 0;
}