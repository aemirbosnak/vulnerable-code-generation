//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void print_hex(unsigned char hex) {
    if (hex > 9)
        putchar('A' + (hex - 10));
    else
        putchar(hex + '0');
}

void print_hex_word(unsigned int hex) {
    print_hex(hex >> 4);
    print_hex(hex & 0xF);
}

void convert_hex_to_decimal(char *hex, int *decimal) {
    *decimal = 0;
    unsigned int base = 1;

    for (int i = strlen(hex) - 1; i >= 0; i--) {
        switch (hex[i]) {
            case 'A':
                *decimal += 10 * base;
                break;
            case 'B':
                *decimal += 11 * base;
                break;
            case 'C':
                *decimal += 12 * base;
                break;
            case 'D':
                *decimal += 13 * base;
                break;
            case 'E':
                *decimal += 14 * base;
                break;
            case 'F':
                *decimal += 15 * base;
                break;
            default:
                *decimal += (isdigit(hex[i]) ? (hex[i] - '0') : hex[i]);
                break;
        }

        base *= 16;
    }
}

int main() {
    char hex_input[10];
    unsigned int decimal;

    printf("Enter a hexadecimal number: ");
    fgets(hex_input, sizeof(hex_input), stdin);

    hex_input[strlen(hex_input) - 1] = '\0';

    if (strlen(hex_input) > 9) {
        printf("Error: Input too long\n");
        return 1;
    }

    convert_hex_to_decimal(hex_input, &decimal);

    print_hex_word(decimal);
    printf(" is equal to the decimal number: ");
    printf("%u\n", decimal);

    return 0;
}