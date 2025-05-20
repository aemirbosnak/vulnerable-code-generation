//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10000

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);

    // Iterate through binary string from right to left
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal, char* binary) {
    int quotient, remainder;
    quotient = decimal;
    int i = 0;

    // Iterate until quotient becomes 0
    while (quotient > 0) {
        remainder = quotient % 2;
        binary[i] = remainder + '0';
        quotient = quotient / 2;
        i++;
    }
    binary[i] = '\0';

    // Reverse binary string
    for (int j = 0; j < i / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[i - j - 1];
        binary[i - j - 1] = temp;
    }
}

int main() {
    char binary[MAX_SIZE];
    char decimal[MAX_SIZE];
    int choice, decimalValue;

    // Prompt user for input
    printf("Enter a binary number (up to %d digits): ", MAX_SIZE - 1);
    scanf("%s", binary);

    // Validate binary input
    for (int i = 0; i < strlen(binary); i++) {
        if (binary[i]!= '0' && binary[i]!= '1') {
            printf("Invalid input. Please enter a binary number.\n");
            return 0;
        }
    }

    // Prompt user for conversion type
    printf("Choose a conversion type:\n1. Binary to decimal\n2. Decimal to binary\n");
    scanf("%d", &choice);

    // Convert binary to decimal
    if (choice == 1) {
        decimalValue = binaryToDecimal(binary);
        sprintf(decimal, "%d", decimalValue);
        printf("Decimal equivalent: %s\n", decimal);
    }

    // Convert decimal to binary
    else if (choice == 2) {
        decimalToBinary(atoi(binary), decimal);
        printf("Binary equivalent: %s\n", decimal);
    }

    // Invalid choice
    else {
        printf("Invalid choice. Please choose 1 or 2.\n");
    }

    return 0;
}