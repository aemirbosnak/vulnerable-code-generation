//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 1000
#define MAX_DEC_LENGTH 1000

void hex_to_dec(char *hex, char *dec) {
    int i, j, len, decimal = 0;
    char hex_digit;

    len = strlen(hex);
    for (i = 0, j = 0; i < len; i++) {
        hex_digit = hex[i];
        if (hex_digit >= '0' && hex_digit <= '9') {
            decimal = (decimal * 16) + (hex_digit - '0');
        } else if (hex_digit >= 'A' && hex_digit <= 'F') {
            decimal = (decimal * 16) + (hex_digit - 'A' + 10);
        } else if (hex_digit >= 'a' && hex_digit <= 'f') {
            decimal = (decimal * 16) + (hex_digit - 'a' + 10);
        } else {
            printf("Invalid hexadecimal character: %c\n", hex_digit);
            exit(1);
        }
        dec[j++] = hex_digit;
    }
    dec[j] = '\0';
}

void dec_to_hex(char *dec, char *hex) {
    int i, j, len, remainder;
    char hex_digit;

    len = strlen(dec);
    for (i = 0, j = 0; i < len; i++) {
        remainder = dec[i] % 16;
        if (remainder < 10) {
            hex_digit = remainder + '0';
        } else {
            hex_digit = remainder - 10 + 'A';
        }
        hex[j++] = hex_digit;
    }
    hex[j] = '\0';
}

int main() {
    char hex[MAX_HEX_LENGTH], dec[MAX_DEC_LENGTH];

    printf("Enter a hexadecimal number: ");
    fgets(hex, MAX_HEX_LENGTH, stdin);
    hex[strcspn(hex, "\n")] = '\0';

    hex_to_dec(hex, dec);
    printf("Decimal equivalent: %s\n", dec);

    dec_to_hex(dec, hex);
    printf("Hexadecimal equivalent: %s\n", hex);

    return 0;
}