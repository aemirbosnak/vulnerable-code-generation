//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert binary to decimal
int binaryToDecimal(char *binary) {
    int decimal = 0, i = 0;
    while (binary[i]!= '\0') {
        if (binary[i] == '1') {
            decimal += pow(2, strlen(binary) - i - 1);
        }
        i++;
    }
    return decimal;
}

// Function to print binary number
void printBinary(int decimal) {
    char binary[33];
    int i = 0;
    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    printf("%s\n", binary);
}

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    char binary[33];
    int i = 0;
    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    printf("%s\n", binary);
}

// Function to convert hexadecimal to binary
void hexToBinary(char *hex) {
    int decimal = 0;
    char binary[33];
    int i = 0;
    while (hex[i]!= '\0') {
        if (isdigit(hex[i])) {
            decimal = decimal * 16 + hex[i] - '0';
        } else {
            decimal = decimal * 16 + hex[i] - 'A' + 10;
        }
        i++;
    }
    printBinary(decimal);
}

// Function to convert binary to hexadecimal
void binaryToHex(char *binary) {
    int decimal = binaryToDecimal(binary);
    char hex[7];
    int i = 0;
    while (decimal > 0) {
        hex[i++] = (decimal % 16) + (decimal % 16 > 9? 'A' : '0');
        decimal /= 16;
    }
    printf("%s\n", hex);
}

// Main function to take user input and call appropriate conversion function
int main() {
    char input[33];
    printf("Enter a number (binary, decimal, or hexadecimal): ");
    scanf("%s", input);
    if (isdigit(input[0])) {
        decimalToBinary(atoi(input));
    } else if (input[0] == '0' && input[1] == 'x') {
        hexToBinary(input + 2);
    } else {
        binaryToDecimal(input);
    }
    return 0;
}