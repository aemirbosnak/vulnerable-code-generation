//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to convert binary to decimal
int binary_to_decimal(char* binary_str) {
    int decimal = 0;
    int length = strlen(binary_str);

    // Iterate through the binary string and calculate the decimal value
    for (int i = 0; i < length; i++) {
        if (binary_str[i] == '1') {
            decimal += pow(2, length - i - 1);
        }
    }

    return decimal;
}

// Function to convert decimal to binary
void decimal_to_binary(int decimal, char* binary_str) {
    int length = 0;

    // Iterate until the decimal value becomes 0
    while (decimal > 0) {
        if (decimal % 2 == 1) {
            binary_str[length++] = '1';
        } else {
            binary_str[length++] = '0';
        }
        decimal /= 2;
    }

    // Add leading zeros if necessary
    for (int i = length; i < MAX_LENGTH; i++) {
        binary_str[i] = '0';
    }

    // Reverse the binary string
    for (int i = 0; i < length / 2; i++) {
        char temp = binary_str[i];
        binary_str[i] = binary_str[length - i - 1];
        binary_str[length - i - 1] = temp;
    }
}

int main() {
    char binary_str[MAX_LENGTH];
    char decimal_str[MAX_LENGTH];

    // Get binary input from user
    printf("Enter a binary number: ");
    scanf("%s", binary_str);

    // Convert binary to decimal
    int decimal = binary_to_decimal(binary_str);

    // Convert decimal to binary
    decimal_to_binary(decimal, decimal_str);

    // Print the results
    printf("Binary: %s\n", binary_str);
    printf("Decimal: %s\n", decimal_str);

    return 0;
}