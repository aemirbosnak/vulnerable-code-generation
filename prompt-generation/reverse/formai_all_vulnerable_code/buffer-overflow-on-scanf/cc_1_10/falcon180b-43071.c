//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    char binary[33]; // Maximum 32 bits + null terminator
    int i = 0;
    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[i] = '\0';
    printf("Binary: %s\n", binary);
}

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary) - 1;
    while (length >= 0) {
        if (binary[length] == '1') {
            decimal += pow(2, power);
        }
        power++;
        length--;
    }
    return decimal;
}

// Function to convert hexadecimal to binary
void hexadecimalToBinary(char* hex) {
    char binary[9]; // Maximum 8 bits + null terminator
    int i = 0;
    while (*hex) {
        if (*hex >= '0' && *hex <= '9') {
            binary[i++] = *hex;
        } else if (*hex >= 'A' && *hex <= 'F') {
            binary[i++] = (*hex - 'A') + 10;
        } else if (*hex >= 'a' && *hex <= 'f') {
            binary[i++] = (*hex - 'a') + 10;
        }
        hex++;
    }
    binary[i] = '\0';
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", binary[j]);
    }
    printf("\n");
}

// Function to convert binary to hexadecimal
void binaryToHexadecimal(char* binary) {
    char hex[9]; // Maximum 8 bits + null terminator
    int i = 0;
    while (*binary) {
        if (*binary >= '0' && *binary <= '9') {
            hex[i++] = *binary;
        } else {
            hex[i++] = (*binary - '0' + 10) % 16 + 'A';
        }
        binary++;
    }
    hex[i] = '\0';
    printf("Hexadecimal: %s\n", hex);
}

int main() {
    char input[33];
    printf("Enter a number in decimal, binary or hexadecimal format: ");
    scanf("%s", input);
    int decimal = 0;
    if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X')) {
        hexadecimalToBinary(input);
        binaryToDecimal(input);
        decimalToBinary(decimal);
    } else if (input[0] == '0' && input[1] == 'b') {
        binaryToDecimal(input);
        decimalToBinary(decimal);
        hexadecimalToBinary(input);
    } else {
        binaryToDecimal(input);
        decimalToBinary(decimal);
        hexadecimalToBinary(input);
    }
    return 0;
}