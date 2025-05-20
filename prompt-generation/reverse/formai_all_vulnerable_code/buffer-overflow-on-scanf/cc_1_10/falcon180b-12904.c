//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);

    // Iterate through each character in the binary string
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            // If the character is '1', add 2 to the power of 2 to decimal
            decimal += pow(2, power);
        }
        power++;
    }

    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal, char* binary) {
    int power = 0;
    int remainder;

    // Iterate through each power of 2 until the decimal is 0
    while (decimal > 0) {
        remainder = decimal % 2;
        // Add the remainder to the beginning of the binary string
        strcat(binary, remainder == 0? "0" : "1");
        // Divide the decimal by 2 and update the power
        decimal /= 2;
        power++;
    }

    // Reverse the binary string
    for (int i = 0; i < strlen(binary) / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[strlen(binary) - i - 1];
        binary[strlen(binary) - i - 1] = temp;
    }
}

int main() {
    char binary[MAX_INPUT_LENGTH];
    char decimal[MAX_INPUT_LENGTH];
    int choice;

    // Prompt the user for input
    printf("Enter a binary number (up to %d digits): ", MAX_INPUT_LENGTH - 1);
    scanf("%s", binary);

    // Convert binary to decimal
    int decimalValue = binaryToDecimal(binary);

    // Prompt the user for the output format
    printf("Enter 1 to convert binary to decimal, or 2 to convert decimal to binary: ");
    scanf("%d", &choice);

    // Convert binary to decimal
    if (choice == 1) {
        sprintf(decimal, "%d", decimalValue);
        printf("Decimal: %s\n", decimal);
    }
    // Convert decimal to binary
    else if (choice == 2) {
        decimalToBinary(decimalValue, binary);
        printf("Binary: %s\n", binary);
    }
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}