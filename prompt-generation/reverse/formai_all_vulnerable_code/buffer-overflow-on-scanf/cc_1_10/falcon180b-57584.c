//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LEN 100
#define MAX_DEC_LEN 100

void hex_to_dec(char *hex, int hex_len, char *dec) {
    int i = 0, j = 0, dec_val = 0;
    while (i < hex_len) {
        if (isdigit(hex[i])) {
            dec_val = dec_val * 16 + hex[i] - '0';
        } else if (isupper(hex[i])) {
            dec_val = dec_val * 16 + hex[i] - 'A' + 10;
        } else {
            dec_val = dec_val * 16 + hex[i] - 'a' + 10;
        }
        i++;
        if (i == hex_len || hex[i] == '\0') {
            dec[j++] = dec_val + '0';
            dec_val = 0;
        }
    }
    dec[j] = '\0';
}

void dec_to_hex(char *dec, int dec_len, char *hex) {
    int i = 0, j = 0;
    while (i < dec_len) {
        if (isdigit(dec[i])) {
            hex[j++] = dec[i];
        } else {
            hex[j++] = 'A' + dec[i] - 10;
        }
        i++;
        if (i == dec_len || dec[i] == '\0') {
            hex[j++] = '\0';
            break;
        }
    }
}

int main() {
    char hex[MAX_HEX_LEN], dec[MAX_DEC_LEN];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    printf("Enter a decimal number: ");
    scanf("%s", dec);
    hex_to_dec(hex, strlen(hex), dec);
    printf("Decimal equivalent of %s is %s\n", hex, dec);
    dec_to_hex(dec, strlen(dec), hex);
    printf("Hexadecimal equivalent of %s is %s\n", dec, hex);
    return 0;
}