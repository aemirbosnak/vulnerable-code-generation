//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HEX_DIGITS "0123456789abcdef"

int is_hex_digit(char c) {
    return (strchr(HEX_DIGITS, tolower(c))!= NULL);
}

int is_valid_hex(const char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; ++i) {
        if (!is_hex_digit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int hex_to_dec(const char *hex, int *dec) {
    int i, j;
    for (i = 0, j = 0; hex[i]!= '\0'; ++i) {
        if (is_hex_digit(hex[i])) {
            if (hex[i] >= 'a') {
                *dec = *dec * 16 + (hex[i] - 'a' + 10);
            } else {
                *dec = *dec * 16 + (hex[i] - '0');
            }
        } else {
            return 0;
        }
    }
    return 1;
}

int dec_to_hex(int dec, char *hex) {
    int i, j;
    char *p = hex;
    for (i = 0; dec!= 0; ++i, dec /= 16) {
        if (dec % 16 < 10) {
            *p++ = dec % 16 + '0';
        } else {
            *p++ = dec % 16 + 'a' - 10;
        }
    }
    *p = '\0';
    return 1;
}

int main() {
    char hex[1000], dec[1000];
    int i, j;
    printf("Enter a hexadecimal number: ");
    fgets(hex, sizeof(hex), stdin);
    if (is_valid_hex(hex)) {
        int dec_value = 0;
        hex_to_dec(hex, &dec_value);
        printf("Decimal equivalent: %d\n", dec_value);
    } else {
        printf("Invalid hexadecimal number\n");
    }
    printf("Enter a decimal number: ");
    scanf("%s", dec);
    if (strlen(dec) > 0) {
        int hex_value = 0;
        dec_to_hex(atoi(dec), &hex_value);
        printf("Hexadecimal equivalent: %s\n", hex_value);
    } else {
        printf("No input provided\n");
    }
    return 0;
}