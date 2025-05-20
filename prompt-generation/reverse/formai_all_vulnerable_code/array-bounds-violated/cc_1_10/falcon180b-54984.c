//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 8

void hex_to_dec(char *hex, int *dec) {
    int i = 0;
    int j = strlen(hex) - 1;
    int decimal = 0;

    for (i = 0; i <= j; i++) {
        if (isdigit(hex[i])) {
            decimal += hex[i] - '0';
        } else {
            decimal += hex[i] - 'A' + 10;
        }
        decimal *= 16;
    }

    *dec = decimal;
}

void dec_to_hex(int dec, char *hex) {
    int i = 0, j = 0;
    char hex_digit[16] = "0123456789ABCDEF";

    while (dec!= 0) {
        hex[i++] = hex_digit[dec % 16];
        dec /= 16;
    }

    for (j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

int main() {
    char hex[MAX_HEX_LENGTH];
    int dec;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    hex_to_dec(hex, &dec);
    printf("Decimal equivalent: %d\n", dec);

    printf("Enter a decimal number: ");
    scanf("%d", &dec);

    dec_to_hex(dec, hex);
    printf("Hexadecimal equivalent: %s\n", hex);

    return 0;
}