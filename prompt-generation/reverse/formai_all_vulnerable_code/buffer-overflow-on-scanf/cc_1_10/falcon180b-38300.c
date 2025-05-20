//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 100

void hex_to_decimal(char hex[], int hex_len, int *decimal) {
    int i = 0;
    int decimal_value = 0;
    int hex_digit;

    for (i = 0; i < hex_len; i++) {
        hex_digit = toupper(hex[i]) - '0';

        if (hex_digit >= 10) {
            hex_digit = toupper(hex[i]) - 'A' + 10;
        }

        decimal_value = decimal_value * 16 + hex_digit;
    }

    *decimal = decimal_value;
}

void decimal_to_hex(int decimal, char hex[]) {
    int i = 0;

    while (decimal > 0) {
        if (decimal % 16 < 10) {
            hex[i] = decimal % 16 + '0';
        } else {
            hex[i] = decimal % 16 + 'A';
        }

        decimal /= 16;
        i++;
    }

    hex[i] = '\0';
}

int main() {
    char hex[MAX_HEX_LENGTH];
    int decimal;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    hex_to_decimal(hex, strlen(hex), &decimal);

    printf("Decimal equivalent: %d\n", decimal);

    decimal_to_hex(decimal, hex);

    printf("Hexadecimal equivalent: %s\n", hex);

    return 0;
}