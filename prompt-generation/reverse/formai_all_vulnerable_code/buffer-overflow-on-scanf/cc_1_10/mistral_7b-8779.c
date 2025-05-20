//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define HEX_TO_DEC_SIZE 16

bool isValidHex(char hex) {
    if (hex >= '0' && hex <= '9') return true;
    if (hex >= 'A' && hex <= 'F') return true;
    if (hex >= 'a' && hex <= 'f') return true;
    return false;
}

int hexToDecimal(char hex) {
    if (hex >= '0' && hex <= '9') return hex - '0';
    if (hex >= 'A' && hex <= 'F') return hex - 'A' + 10;
    return -1;
}

void hexToDecimalFunction(char *hexInput, int *decimalOutput) {
    int hexLength = strlen(hexInput);

    if (hexLength > HEX_TO_DEC_SIZE) {
        printf("Error: Hexadecimal input too long.\n");
        *decimalOutput = 0;
        return;
    }

    int decimal = 0;
    int power = 0;

    for (int i = hexLength - 1; i >= 0; i--) {
        char currentHex = hexInput[i];
        int currentDecimal = hexToDecimal(currentHex);

        if (currentDecimal == -1) {
            printf("Error: Invalid hexadecimal character '%c'.\n", currentHex);
            *decimalOutput = 0;
            return;
        }

        decimal += currentDecimal * pow(16, power++);
    }

    *decimalOutput = decimal;
}

int main() {
    char hexInput[HEX_TO_DEC_SIZE];
    int decimalOutput;

    printf("Welcome to the Futuristic Hexadecimal to Decimal Converter v1.0!\n");
    printf("Input a hexadecimal number: ");
    scanf("%s", hexInput);

    hexToDecimalFunction(hexInput, &decimalOutput);

    if (decimalOutput != 0) {
        printf("The decimal representation of '%s' is: %d\n", hexInput, decimalOutput);
    }

    return 0;
}