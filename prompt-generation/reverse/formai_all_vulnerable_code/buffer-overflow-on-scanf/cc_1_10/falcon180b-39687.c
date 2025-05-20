//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Function to check if a string is a valid binary number
bool isBinary(char* str) {
    for (int i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i]) && str[i]!= '0' && str[i]!= '1') {
            return false;
        }
    }
    return true;
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

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    char binary[33]; // Maximum 32 bits + 1 for null terminator
    int index = 0;
    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[index] = '\0';
    printf("%s\n", binary);
}

int main() {
    char input[33];
    printf("Enter a binary number: ");
    scanf("%s", input);
    if (isBinary(input)) {
        int decimal = binaryToDecimal(input);
        printf("Decimal: %d\n", decimal);
        decimalToBinary(decimal);
    } else {
        printf("Invalid binary number\n");
    }
    return 0;
}