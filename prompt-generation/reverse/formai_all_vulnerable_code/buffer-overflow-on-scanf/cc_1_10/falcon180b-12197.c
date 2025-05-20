//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to convert binary to decimal
long long int binaryToDecimal(char* binary) {
    int length = strlen(binary);
    long long int decimal = 0;

    // Iterate through the binary string and add each digit to the decimal value
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, length - i - 1);
        }
    }

    return decimal;
}

// Recursive function to convert decimal to binary
void decimalToBinary(int decimal, char* binary, int index) {
    if (decimal == 0) {
        binary[index] = '\0';
        printf("%s\n", binary);
        return;
    }

    // Find the remainder of the division by 2 and add it to the binary string
    int rem = decimal % 2;
    binary[index] = rem + '0';

    // Recursively call the function with updated parameters
    decimalToBinary(decimal / 2, binary, index + 1);
}

int main() {
    char binary[MAX_LENGTH];
    char decimal[MAX_LENGTH];

    // Prompt the user to enter a binary number
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Convert binary to decimal and display the result
    long long int decimalValue = binaryToDecimal(binary);
    printf("Decimal value of %s is: %lld\n", binary, decimalValue);

    // Convert decimal to binary and display the result
    decimalToBinary(decimalValue, decimal, 0);

    return 0;
}