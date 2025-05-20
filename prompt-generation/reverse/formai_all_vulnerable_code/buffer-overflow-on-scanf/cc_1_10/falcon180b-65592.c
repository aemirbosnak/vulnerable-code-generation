//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0, power = 0;
    int length = strlen(binary);

    // Make sure the binary number is valid
    for (int i = 0; i < length; i++) {
        if (binary[i]!= '0' && binary[i]!= '1') {
            printf("Invalid binary number!\n");
            exit(0);
        }
    }

    // Convert binary to decimal
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal, char* binary) {
    int quotient, remainder;
    quotient = decimal;
    int length = 0;

    // Convert decimal to binary
    while (quotient!= 0) {
        remainder = quotient % 2;
        binary[length++] = remainder + '0';
        quotient /= 2;
    }

    // Reverse the binary number
    for (int i = 0; i < length / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[length - i - 1];
        binary[length - i - 1] = temp;
    }
}

int main() {
    char binary[MAX_LENGTH];
    int decimal;

    // Prompt user to enter binary number
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Convert binary to decimal
    decimal = binaryToDecimal(binary);

    // Convert decimal to binary
    char result[MAX_LENGTH];
    decimalToBinary(decimal, result);

    // Display the result
    printf("Binary to decimal: %d\n", decimal);
    printf("Decimal to binary: %s\n", result);

    return 0;
}