//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 64
#define MAX_DEC_LENGTH 64

typedef struct {
    char hex[MAX_HEX_LENGTH];
    char dec[MAX_DEC_LENGTH];
} HexDec;

void hex_to_dec(char *hex, char *dec);
void dec_to_hex(char *dec, char *hex);

int main(int argc, char **argv) {
    char hex[MAX_HEX_LENGTH];
    char dec[MAX_DEC_LENGTH];
    char choice;
    HexDec hd;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    printf("Enter your choice:\n");
    printf("1. Convert hexadecimal to decimal\n");
    printf("2. Convert decimal to hexadecimal\n");
    scanf("%c", &choice);

    switch (choice) {
        case '1':
            hex_to_dec(hex, dec);
            printf("\nDecimal equivalent: %s\n", dec);
            break;
        case '2':
            dec_to_hex(dec, hd.dec);
            printf("\nHexadecimal equivalent: %s\n", hd.hex);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

void hex_to_dec(char *hex, char *dec) {
    int i, j, len;

    len = strlen(hex);

    for (i = 0, j = 0; i < len; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec[j++] = hex[i];
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec[j++] = hex[i] - 55;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec[j++] = hex[i] - 87;
        } else {
            printf("Invalid hexadecimal character!\n");
            exit(0);
        }
    }

    dec[j] = '\0';
}

void dec_to_hex(char *dec, char *hex) {
    int i, len;

    len = strlen(dec);

    for (i = 0; i < len; i++) {
        if (dec[i] >= '0' && dec[i] <= '9') {
            hex[i] = dec[i];
        } else if (dec[i] >= 'A' && dec[i] <= 'F') {
            hex[i] = dec[i] + 55;
        } else if (dec[i] >= 'a' && dec[i] <= 'f') {
            hex[i] = dec[i] + 87;
        } else {
            printf("Invalid decimal character!\n");
            exit(0);
        }
    }

    hex[len] = '\0';
}