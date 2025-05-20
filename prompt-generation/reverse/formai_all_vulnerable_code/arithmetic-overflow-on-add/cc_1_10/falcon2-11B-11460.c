//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function to convert a binary number to a decimal number
int binaryToDecimal(char *binary) {
    int decimal = 0;
    int len = strlen(binary);
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, len - i - 1);
        }
    }
    return decimal;
}

// Define a function to convert a decimal number to a binary number
char* decimalToBinary(int decimal) {
    int len = 0;
    int decimalNum = decimal;
    char* binary = (char*)malloc(sizeof(char) * (decimal + 1));
    while (decimalNum > 0) {
        binary[len] = decimalNum % 2 + '0';
        decimalNum /= 2;
        len++;
    }
    binary[len] = '\0';
    return binary;
}

// Define a function to read a binary number from the user
char* readBinaryNumber() {
    int len;
    char* binary = (char*)malloc(sizeof(char) * (len + 1));
    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
        scanf("%c", &binary[i]);
    }
    binary[len] = '\0';
    return binary;
}

// Define a function to write a binary number to the user
void writeBinaryNumber(int decimal) {
    char* binary = decimalToBinary(decimal);
    printf("%s\n", binary);
    free(binary);
}

// Main function
int main() {
    char* binary = readBinaryNumber();
    int decimal = binaryToDecimal(binary);
    writeBinaryNumber(decimal);
    return 0;
}