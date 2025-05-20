//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 32
#define MAX_DEC_LENGTH 10

void convert_hex_to_dec(char *hex, char *dec);
void convert_dec_to_hex(char *dec, char *hex);

int main() {
    char hex[MAX_HEX_LENGTH];
    char dec[MAX_DEC_LENGTH];

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    convert_hex_to_dec(hex, dec);

    printf("Hexadecimal: %s\n", hex);
    printf("Decimal: %s\n", dec);

    return 0;
}

void convert_hex_to_dec(char *hex, char *dec) {
    int len = strlen(hex);
    int i = 0;
    int j = 0;
    int value = 0;
    char digit;

    while (i < len) {
        if (isxdigit(hex[i])) {
            digit = tolower(hex[i]);
            if (digit >= '0' && digit <= '9') {
                value += digit - '0';
            } else {
                value += digit - 'a' + 10;
            }
            i++;
        } else {
            break;
        }
    }

    sprintf(dec, "%d", value);
}

void convert_dec_to_hex(char *dec, char *hex) {
    int len = strlen(dec);
    int i = 0;
    int j = 0;
    int value = 0;
    char digit;

    while (i < len) {
        digit = dec[i];
        if (digit >= '0' && digit <= '9') {
            value = value * 16 + digit - '0';
        } else if (digit >= 'A' && digit <= 'F') {
            value = value * 16 + digit - 'A' + 10;
        } else {
            break;
        }
        i++;
    }

    sprintf(hex, "%X", value);
}