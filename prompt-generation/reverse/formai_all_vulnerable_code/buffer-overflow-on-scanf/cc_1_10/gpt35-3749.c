//FormAI DATASET v1.0 Category: Binary Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int decimalNumber, char* binaryNumber) {
    int remainder, quotient, i = 0;
    char temp[50];

    quotient = decimalNumber;

    while(quotient != 0) {
        remainder = quotient % 2;
        quotient = quotient / 2;
        temp[i++] = remainder + '0';
    }

    temp[i] = '\0';

    // Reverse the string
    int j = 0, n = strlen(temp);
    for(i = n - 1; i >= 0; i--) {
        binaryNumber[j++] = temp[i];
    }

    binaryNumber[j] = '\0';
}

// Function to convert binary to decimal
int binaryToDecimal(char* binaryNumber) {
    int decimalNumber = 0, i, n = strlen(binaryNumber);

    // Iterate through each digit of binary number
    for(i = 0; i < n; i++) {
        // If the digit is 1, add the corresponding power of 2 to the decimal number
        if(binaryNumber[i] == '1') {
            decimalNumber += 1 << (n - i - 1);
        }
    }

    return decimalNumber;
}

int main() {
    int decimalNumber;
    char binaryNumber[50];

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert decimal to binary
    decimalToBinary(decimalNumber, binaryNumber);

    printf("Binary equivalent: %s\n", binaryNumber);

    char binaryInput[50];
    printf("Enter a binary number: ");
    scanf("%s", binaryInput);

    // Convert binary to decimal
    int decimalInput = binaryToDecimal(binaryInput);

    printf("Decimal equivalent: %d\n", decimalInput);

    return 0;
}