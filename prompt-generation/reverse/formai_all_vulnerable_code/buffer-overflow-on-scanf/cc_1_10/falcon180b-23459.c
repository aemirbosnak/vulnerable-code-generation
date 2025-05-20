//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
char* decimalToBinary(int decimal) {
    char* binary = (char*) malloc(33 * sizeof(char)); // Allocate memory for binary representation (32 bits + null terminator)
    memset(binary, '0', 32); // Initialize binary representation with 32 zeros
    binary[32] = '\0'; // Add null terminator

    int i = 0;
    while (decimal > 0) {
        binary[31 - i] = (decimal % 2) + '0'; // Convert decimal to binary and store in binary representation
        decimal /= 2;
        i++;
    }

    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
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

int main() {
    char* binary;
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    binary = decimalToBinary(decimal);
    printf("Binary representation: %s\n", binary);

    int binaryDecimal = binaryToDecimal(binary);
    printf("Decimal representation: %d\n", binaryDecimal);

    free(binary); // Free memory allocated for binary representation
    return 0;
}