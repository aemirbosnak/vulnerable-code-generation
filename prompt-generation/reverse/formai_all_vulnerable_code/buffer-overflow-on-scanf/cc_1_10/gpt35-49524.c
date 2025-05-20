//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10

// Converts hexadecimal string to decimal value
int hexToDecimal(char *hexString) {
    int decimalValue = 0;
    int length = strlen(hexString);

    for (int i = 0; i < length; i++) {
        char currentChar = hexString[i];

        if (currentChar >= '0' && currentChar <= '9') {
            decimalValue = decimalValue * 16 + (currentChar - '0');
        } else if (currentChar >= 'A' && currentChar <= 'F') {
            decimalValue = decimalValue * 16 + (10 + currentChar - 'A');
        } else if (currentChar >= 'a' && currentChar <= 'f') {
            decimalValue = decimalValue * 16 + (10 + currentChar - 'a');
        } else {
            printf("Error: Invalid hexadecimal string.\n");
            exit(1);
        }
    }

    return decimalValue;
}

// Converts decimal value to hexadecimal string
void decimalToHex(int decimalValue, char *hexString) {
    sprintf(hexString, "%X", decimalValue);
}

int main() {
    char hexString[MAX_LENGTH];
    int decimalValue;

    printf("Enter a hexadecimal string: ");
    scanf("%s", hexString);

    decimalValue = hexToDecimal(hexString);

    printf("The decimal value is: %d\n", decimalValue);

    decimalToHex(decimalValue, hexString);

    printf("Back to hexadecimal: %s\n", hexString);

    return 0;
}