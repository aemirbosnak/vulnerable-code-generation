//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX_SIZE 100
#define MAX_DEC_SIZE 100

void hex_to_dec(char* hex, int* dec) {
    int i = 0, j = 0;
    int len = strlen(hex);
    int dec_val = 0;

    *dec = 0;

    for (i = 0; i < len; i++) {
        if (isxdigit(hex[i])) {
            if (isdigit(hex[i])) {
                dec_val = dec_val * 16 + (hex[i] - '0');
            } else {
                dec_val = dec_val * 16 + (hex[i] - 'A' + 10);
            }
        } else {
            printf("Invalid hexadecimal character '%c' at position %d.\n", hex[i], i);
            exit(1);
        }
    }

    *dec = dec_val;
}

void dec_to_hex(int dec, char* hex) {
    int i = 0, j = 0;
    char hex_val[MAX_HEX_SIZE];

    if (dec == 0) {
        strcpy(hex, "0");
        return;
    }

    sprintf(hex_val, "%X", dec);

    for (i = strlen(hex_val) - 1, j = 0; i >= 0; i--, j++) {
        hex[j] = hex_val[i];
    }

    hex[j] = '\0';
}

int main() {
    char hex[MAX_HEX_SIZE];
    int dec;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    hex_to_dec(hex, &dec);

    printf("Decimal representation of %s is %d.\n", hex, dec);

    dec_to_hex(dec, hex);

    printf("Hexadecimal representation of %d is %s.\n", dec, hex);

    return 0;
}