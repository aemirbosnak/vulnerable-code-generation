//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 64
#define MAX_DEC_LENGTH 16

int main(int argc, char *argv[]) {
    char hex[MAX_HEX_LENGTH] = {0};
    char dec[MAX_DEC_LENGTH] = {0};
    int hex_len, dec_len;

    // Check if user provided hexadecimal string as input
    if (argc!= 2) {
        printf("Usage: %s [hexadecimal string]\n", argv[0]);
        return 1;
    }

    // Convert hexadecimal string to uppercase
    strcpy(hex, argv[1]);
    for (int i = 0; i < strlen(hex); i++) {
        hex[i] = toupper(hex[i]);
    }

    // Convert hexadecimal to decimal
    hex_len = strlen(hex);
    dec_len = hex_len / 2;
    for (int i = 0; i < hex_len; i += 2) {
        char hex_digit = hex[i];
        char hex_digit2 = hex[i + 1];
        int decimal;
        if (hex_digit >= 'A' && hex_digit <= 'F') {
            decimal = hex_digit - 'A' + 10;
        } else if (hex_digit >= 'a' && hex_digit <= 'f') {
            decimal = hex_digit - 'a' + 10;
        } else {
            decimal = hex_digit - '0';
        }
        if (hex_digit2 >= 'A' && hex_digit2 <= 'F') {
            decimal = decimal * 16 + hex_digit2 - 'A' + 10;
        } else if (hex_digit2 >= 'a' && hex_digit2 <= 'f') {
            decimal = decimal * 16 + hex_digit2 - 'a' + 10;
        } else {
            decimal = decimal * 16 + hex_digit2 - '0';
        }
        sprintf(&dec[i / 2], "%02X", decimal);
    }

    // Print output
    printf("Hexadecimal: %s\n", hex);
    printf("Decimal:     %s\n", dec);

    return 0;
}