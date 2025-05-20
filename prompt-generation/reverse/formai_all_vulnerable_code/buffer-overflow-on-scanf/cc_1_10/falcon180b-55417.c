//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1000 // Maximum length of binary string
#define MAX_DIGITS 9 // Maximum number of digits in decimal representation of binary

// Function to convert binary to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0;
    int length = strlen(binary);
    int power = 0;

    // Iterate through each digit in the binary string
    for (int i = length - 1; i >= 0; i--) {
        // Calculate the value of the current digit
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    return decimal;
}

// Function to convert decimal to binary
void decimal_to_binary(int decimal, char* binary) {
    int length = 0;
    int remainder;

    // Iterate until decimal becomes 0
    while (decimal > 0) {
        remainder = decimal % 2;
        binary[length++] = remainder + '0';
        decimal /= 2;
    }

    // Reverse the binary string
    for (int i = 0; i < length / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[length - i - 1];
        binary[length - i - 1] = temp;
    }

    // Add leading zeros if necessary
    while (length < MAX_LENGTH) {
        binary[length++] = '0';
    }
    binary[length] = '\0';
}

int main() {
    char binary[MAX_LENGTH];
    char decimal[MAX_DIGITS];

    // Prompt user for binary string
    printf("Enter a binary string: ");
    scanf("%s", binary);

    // Convert binary to decimal
    int decimal_value = binary_to_decimal(binary);

    // Convert decimal to binary
    decimal_to_binary(decimal_value, decimal);

    // Print the results
    printf("Decimal: %s\n", decimal);

    return 0;
}