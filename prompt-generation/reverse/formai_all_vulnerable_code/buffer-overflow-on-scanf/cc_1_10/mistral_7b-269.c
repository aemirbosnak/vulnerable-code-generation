//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    unsigned int decimal;
    unsigned int hex;
    unsigned char binary[33]; // 32 bits plus null terminator
} ConversionResult;

void DecimalToBinary(unsigned int decimal, unsigned char binary[]) {
    int i;
    for (i = 0; decimal > 0; i++) {
        binary[i] = decimal % 2 + '0';
        decimal /= 2;
    }
    for (; i < 32; i++) {
        binary[i] = '0';
    }
}

void HexToDecimal(char hex[], unsigned int* decimal) {
    unsigned int value = 0;
    int length = strlen(hex);

    for (int i = length - 1; i >= 0; i--) {
        int digit = toupper(hex[i]) - '0';
        if (digit > 9) {
            digit -= 7;
        }
        value += digit << (4 * (length - i - 1));
    }

    *decimal = value;
}

void BinaryToHex(unsigned char binary[], char hex[]) {
    int i;

    for (i = 0; i < 4; i++) {
        int nibble = (binary[i / 2] >> (4 * (i % 2))) & 0xF;
        if (nibble < 10) {
            hex[i * 2] = nibble + '0';
        } else {
            hex[i * 2] = nibble + 'A' - 10;
        }
    }
    hex[8] = '\0';
}

void Convert(char* input, ConversionResult* result) {
    bool decimal = true;
    unsigned int decimalValue;

    if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X')) {
        decimal = false;
        HexToDecimal(input + 2, &decimalValue);
    } else if (strlen(input) > 1 && isdigit(input[0])) {
        decimalValue = atoi(input);
    } else {
        printf("Invalid input\n");
        return;
    }

    DecimalToBinary(decimalValue, result->binary);
    result->decimal = decimalValue;

    if (!decimal) {
        BinaryToHex(result->binary, result->hex);
    }
}

int main() {
    ConversionResult result;
    char input[33];

    while (1) {
        printf("Enter decimal number, hexadecimal number, or binary number (type 'q' to quit): ");
        scanf("%s", input);

        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }

        Convert(input, &result);

        if (!result.decimal) {
            printf("Hexadecimal: %s\n", result.hex);
        } else {
            printf("Decimal: %u\n", result.decimal);
            printf("Binary: %s\n", result.binary);
        }
    }

    return 0;
}