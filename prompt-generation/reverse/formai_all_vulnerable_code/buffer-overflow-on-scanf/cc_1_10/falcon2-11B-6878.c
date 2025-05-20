//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: futuristic
#include <stdio.h>

// Function to convert binary number to decimal
int binaryToDecimal(int binary) {
    int decimal = 0;
    int power = 0;

    while (binary > 0) {
        int remainder = binary % 10;
        decimal += remainder * pow(2, power);
        power++;
        binary /= 10;
    }

    return decimal;
}

// Function to convert decimal number to binary
int decimalToBinary(int decimal) {
    int binary = 0;
    int quotient = decimal;
    int power = 0;

    while (quotient > 0) {
        int remainder = quotient % 2;
        binary += remainder * pow(2, power);
        quotient /= 2;
        power++;
    }

    return binary;
}

int main() {
    int binary, decimal;

    // Read binary number from user
    printf("Enter binary number: ");
    scanf("%d", &binary);

    // Convert binary to decimal
    int decimalValue = binaryToDecimal(binary);
    printf("Decimal equivalent: %d\n", decimalValue);

    // Read decimal number from user
    printf("Enter decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal to binary
    int binaryValue = decimalToBinary(decimal);
    printf("Binary equivalent: %d\n", binaryValue);

    return 0;
}