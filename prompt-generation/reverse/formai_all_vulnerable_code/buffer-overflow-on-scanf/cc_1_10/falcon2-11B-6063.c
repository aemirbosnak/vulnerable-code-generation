//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal number to binary
int decimalToBinary(int num) {
    int binary[32];
    int i, j, carry;

    // Initialize the binary array
    for (i = 31; i >= 0; i--) {
        binary[i] = 0;
    }

    // Perform the division and remainder operations
    for (j = 0; num > 0; j++) {
        carry = num % 2;
        binary[j] = carry;
        num = num / 2;
    }

    // Reverse the binary array
    for (i = 0; i < 32; i++) {
        char temp = binary[i];
        binary[i] = binary[31 - i];
        binary[31 - i] = temp;
    }

    // Return the binary number
    return binary[0];
}

// Function to convert binary number to decimal
int binaryToDecimal(int num) {
    int decimal[32];
    int i, j, carry;

    // Initialize the decimal array
    for (i = 31; i >= 0; i--) {
        decimal[i] = 0;
    }

    // Perform the division and remainder operations
    for (j = 0; num > 0; j++) {
        carry = num % 10;
        decimal[j] = carry;
        num = num / 10;
    }

    // Reverse the decimal array
    for (i = 0; i < 32; i++) {
        char temp = decimal[i];
        decimal[i] = decimal[31 - i];
        decimal[31 - i] = temp;
    }

    // Return the decimal number
    return decimal[0];
}

int main() {
    int num;
    char input[32];

    printf("Enter a decimal number: ");
    scanf("%s", input);

    num = atoi(input);

    int binary = decimalToBinary(num);
    int decimal = binaryToDecimal(binary);

    printf("Binary representation of %d is: %d\n", num, binary);
    printf("Decimal representation of %d is: %d\n", binary, decimal);

    return 0;
}