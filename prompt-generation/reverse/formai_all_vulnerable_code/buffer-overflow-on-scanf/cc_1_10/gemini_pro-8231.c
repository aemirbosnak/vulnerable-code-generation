//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert a decimal number to binary
char *decimalToBinary(int decimalNumber) {
    // Allocate memory for the binary representation
    char *binaryRepresentation = malloc(33 * sizeof(char));

    // Initialize the binary representation to 0
    for (int i = 0; i < 33; i++) {
        binaryRepresentation[i] = '0';
    }

    // Convert the decimal number to binary
    int index = 32;
    while (decimalNumber > 0) {
        if (decimalNumber % 2 == 1) {
            binaryRepresentation[index] = '1';
        }
        decimalNumber /= 2;
        index--;
    }

    // Return the binary representation
    return binaryRepresentation;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char *binaryNumber) {
    // Initialize the decimal representation to 0
    int decimalRepresentation = 0;

    // Convert the binary number to decimal
    int length = strlen(binaryNumber);
    for (int i = 0; i < length; i++) {
        if (binaryNumber[i] == '1') {
            decimalRepresentation += pow(2, length - i - 1);
        }
    }

    // Return the decimal representation
    return decimalRepresentation;
}

// Function to print the binary representation of a number
void printBinaryRepresentation(char *binaryRepresentation) {
    // Print the binary representation
    for (int i = 0; i < 33; i++) {
        printf("%c", binaryRepresentation[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Get the decimal number from the user
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert the decimal number to binary
    char *binaryRepresentation = decimalToBinary(decimalNumber);

    // Print the binary representation
    printf("The binary representation of %d is: ", decimalNumber);
    printBinaryRepresentation(binaryRepresentation);

    // Convert the binary number to decimal
    int decimalRepresentation = binaryToDecimal(binaryRepresentation);

    // Print the decimal representation
    printf("The decimal representation of %s is: %d\n", binaryRepresentation, decimalRepresentation);

    // Free the allocated memory
    free(binaryRepresentation);

    return 0;
}