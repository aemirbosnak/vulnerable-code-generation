//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000

// Function to check if input string is a valid binary number
int is_binary(char* input) {
    for (int i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i]) && input[i]!= '0' && input[i]!= '1') {
            return 0;
        }
    }
    return 1;
}

// Function to convert binary to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0;
    int power = 0;
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

// Function to convert decimal to binary
void decimal_to_binary(int decimal) {
    char binary[33];
    int i = 0;
    while (decimal > 0) {
        if (decimal % 2 == 0) {
            binary[i] = '0';
        } else {
            binary[i] = '1';
        }
        i++;
        decimal /= 2;
    }
    binary[i] = '\0';
    printf("%s\n", binary);
}

// Main function
int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter a binary number: ");
    scanf("%s", input);

    // Check if input is a valid binary number
    if (!is_binary(input)) {
        printf("Invalid binary number.\n");
        return 1;
    }

    // Convert binary to decimal
    int decimal = binary_to_decimal(input);

    // Convert decimal to binary
    printf("Decimal equivalent: ");
    decimal_to_binary(decimal);

    return 0;
}