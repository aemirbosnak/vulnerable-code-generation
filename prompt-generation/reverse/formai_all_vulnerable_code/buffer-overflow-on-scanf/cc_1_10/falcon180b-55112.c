//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0, power = 0;

    // Iterate over the binary string in reverse order
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal, char* binary, int size) {
    int rem, j = 0;

    // Iterate until the quotient becomes 0
    while (decimal!= 0) {
        rem = decimal % 2;
        binary[j++] = rem + '0';
        decimal /= 2;
    }

    // Reverse the binary string
    for (int i = 0; i < j / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[j - i - 1];
        binary[j - i - 1] = temp;
    }

    // Add leading zeros to the binary string
    while (j < size) {
        binary[j++] = '0';
    }
}

int main() {
    char binary[100], decimal[100];
    int choice, size;

    // Prompt the user to enter the size of the binary number
    printf("Enter the size of the binary number (up to 100): ");
    scanf("%d", &size);

    // Prompt the user to enter the binary number
    printf("Enter the binary number: ");
    scanf("%s", binary);

    // Convert binary to decimal
    int decimalNumber = binaryToDecimal(binary);

    // Prompt the user to choose the conversion type
    printf("\nChoose the conversion type:\n1. Binary to Decimal\n2. Decimal to Binary\n");
    scanf("%d", &choice);

    // Convert binary to decimal
    if (choice == 1) {
        printf("Decimal equivalent of %s is %d\n", binary, decimalNumber);
    }
    // Convert decimal to binary
    else if (choice == 2) {
        printf("Binary equivalent of %d is: ", decimalNumber);
        decimalToBinary(decimalNumber, decimal, size);
        printf("%s\n", decimal);
    }

    return 0;
}