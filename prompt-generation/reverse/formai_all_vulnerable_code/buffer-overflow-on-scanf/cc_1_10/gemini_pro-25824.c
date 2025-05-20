//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
char* decimalToBinary(int decimal) {
    char *binary = malloc(sizeof(char) * 33);
    int i = 0;
    while (decimal > 0) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
        i++;
    }
    binary[i] = '\0';
    return binary;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char *binary) {
    int decimal = 0;
    int i = 0;
    while (binary[i] != '\0') {
        decimal *= 2;
        decimal += binary[i] - '0';
        i++;
    }
    return decimal;
}

int main() {
    // Get the decimal number from the user
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert the decimal number to binary
    char *binary = decimalToBinary(decimal);

    // Print the binary number
    printf("The binary representation of %d is %s\n", decimal, binary);

    // Convert the binary number to decimal
    int decimal2 = binaryToDecimal(binary);

    // Print the decimal number
    printf("The decimal representation of %s is %d\n", binary, decimal2);

    // Free the memory allocated for the binary string
    free(binary);

    return 0;
}