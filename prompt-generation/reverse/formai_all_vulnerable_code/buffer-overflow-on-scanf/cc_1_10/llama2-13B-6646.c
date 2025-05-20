//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUMBER_OF_BITS 32
#define MAX_NUMBER_OF_BYTES 10

// Function to convert a binary number to its decimal representation
int binaryToDecimal(char binary[]) {
    int decimal = 0;
    int i = 0;

    while (binary[i] != '\0') {
        decimal = (decimal * 2) + (binary[i] - '0');
        i++;
    }

    return decimal;
}

// Function to convert a decimal number to its binary representation
int decimalToBinary(int decimal) {
    int binary[MAX_NUMBER_OF_BYTES];
    int i = 0;

    while (decimal != 0) {
        binary[i] = decimal % 2 == 0 ? '0' : '1';
        decimal /= 2;
        i++;
    }

    return binary;
}

int main() {
    char binary[MAX_NUMBER_OF_BYTES];
    int decimal;

    // Prompt user for binary number
    printf("Enter a binary number: ");
    fgets(binary, MAX_NUMBER_OF_BYTES, stdin);

    // Convert binary number to decimal
    decimal = binaryToDecimal(binary);

    // Prompt user for decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal number to binary
    char *binary_rep = decimalToBinary(decimal);

    // Print binary representation of decimal number
    printf("Binary representation of %d is: %s\n", decimal, binary_rep);

    return 0;
}