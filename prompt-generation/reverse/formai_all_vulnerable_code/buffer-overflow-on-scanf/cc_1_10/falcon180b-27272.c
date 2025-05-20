//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert binary to decimal
int binaryToDecimal(char *binary) {
    int decimal = 0;
    int power = 0;
    int i = strlen(binary) - 1;

    while (i >= 0) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
        i--;
    }

    return decimal;
}

// Function to convert decimal to binary
char *decimalToBinary(int decimal) {
    char *binary = (char *) malloc(33 * sizeof(char)); // Allocate memory for binary string
    int i = 0;
    while (decimal > 0) {
        if (decimal % 2 == 1) {
            binary[i] = '1';
        } else {
            binary[i] = '0';
        }
        decimal /= 2;
        i++;
    }
    binary[i] = '\0'; // Add null terminator to end of binary string
    return binary;
}

int main() {
    char *binary;
    int decimal;

    // Prompt user to enter a binary number
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Convert binary to decimal
    decimal = binaryToDecimal(binary);

    // Print the decimal equivalent
    printf("The decimal equivalent of %s is %d\n", binary, decimal);

    // Prompt user to enter a decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal to binary
    binary = decimalToBinary(decimal);

    // Print the binary equivalent
    printf("The binary equivalent of %d is %s\n", decimal, binary);

    free(binary); // Free memory allocated for binary string
    return 0;
}