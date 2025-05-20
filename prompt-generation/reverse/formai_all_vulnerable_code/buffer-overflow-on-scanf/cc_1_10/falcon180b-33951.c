//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000 // Maximum length of input string

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0, i = 0;
    while (binary[i]) {
        decimal += (binary[i] - '0');
        decimal *= 2;
        i++;
    }
    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal, char* binary) {
    int i = 0;
    while (decimal > 0) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
        i++;
    }
    binary[i] = '\0'; // Add null terminator
}

// Function to convert hexadecimal to binary
void hexToBinary(char* hex, char* binary) {
    int i = 0;
    while (hex[i]) {
        if (isdigit(hex[i])) {
            binary[i] = hex[i];
        } else {
            binary[i] = (hex[i] - 'A' + 10);
        }
        i++;
    }
    binary[i] = '\0'; // Add null terminator
}

int main() {
    char binary[MAX_LENGTH], decimal[MAX_LENGTH], hex[MAX_LENGTH];
    int length, choice;

    printf("Enter a binary number (up to %d characters): ", MAX_LENGTH);
    if (fgets(binary, MAX_LENGTH, stdin) == NULL) {
        printf("Error: Input too long.\n");
        return 1;
    }
    length = strlen(binary);

    printf("Enter the conversion type:\n1. Binary to decimal\n2. Decimal to binary\n3. Hexadecimal to binary\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Decimal equivalent: %d\n", binaryToDecimal(binary));
            break;
        case 2:
            printf("Binary equivalent: ");
            decimalToBinary(binaryToDecimal(binary), decimal);
            printf("%s\n", decimal);
            break;
        case 3:
            printf("Binary equivalent: ");
            hexToBinary(binary, decimal);
            printf("%s\n", decimal);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}