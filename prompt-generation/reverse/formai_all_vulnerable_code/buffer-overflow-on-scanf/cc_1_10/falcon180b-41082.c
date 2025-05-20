//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_DIGITS 8
#define MAX_BIN_DIGITS 32
#define MAX_DEC_DIGITS 12

void print_hex(char* hex, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%02X ", hex[i]);
    }
    printf("\n");
}

void print_bin(char* bin, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%c", bin[i]);
    }
    printf("\n");
}

void print_dec(char* dec, int len) {
    printf("%s\n", dec);
}

int main() {
    char hex_input[MAX_HEX_DIGITS];
    char bin_output[MAX_BIN_DIGITS];
    char dec_output[MAX_DEC_DIGITS];
    int hex_len, bin_len, dec_len;
    int i;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_input);
    hex_len = strlen(hex_input);

    if (hex_len == 0) {
        printf("Invalid input.\n");
        return 1;
    }

    for (i = 0; i < hex_len; i++) {
        if (!isxdigit(hex_input[i])) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    bin_len = hex_len * 4;
    dec_len = bin_len / 3;

    for (i = 0; i < hex_len; i++) {
        bin_output[i * 4] = (hex_input[i] & 0xF) + '0';
        bin_output[i * 4 + 1] = ((hex_input[i] >> 4) & 0xF) + '0';
    }

    bin_output[bin_len - 1] = '\0';
    dec_output[dec_len - 1] = '\0';

    printf("Binary: ");
    print_bin(bin_output, bin_len);

    printf("Decimal: ");
    print_dec(dec_output, dec_len);

    return 0;
}