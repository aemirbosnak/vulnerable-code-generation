//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 1000
#define MAX_DEC_LENGTH 1000

// Function to check if a character is a hexadecimal digit
int is_hexadecimal(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else if (c >= 'A' && c <= 'F') {
        return 1;
    } else if (c >= 'a' && c <= 'f') {
        return 1;
    } else {
        return 0;
    }
}

// Function to convert hexadecimal to decimal
int hex_to_dec(char* hex, char* dec) {
    int hex_len = strlen(hex);
    int dec_len = 0;
    int i = 0;
    while (i < hex_len) {
        if (is_hexadecimal(hex[i])) {
            dec[dec_len++] = hex[i];
        } else {
            printf("Error: Invalid hexadecimal character '%c'\n", hex[i]);
            return 0;
        }
        i++;
    }
    dec[dec_len] = '\0';
    return 1;
}

// Function to convert decimal to hexadecimal
int dec_to_hex(int dec, char* hex) {
    int hex_len = 0;
    while (dec > 0) {
        int remainder = dec % 16;
        if (remainder < 10) {
            hex[hex_len++] = remainder + '0';
        } else {
            hex[hex_len++] = remainder + 'A' - 10;
        }
        dec /= 16;
    }
    hex[hex_len] = '\0';
    return 1;
}

int main() {
    char hex[MAX_HEX_LENGTH];
    char dec[MAX_DEC_LENGTH];

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    int hex_len = strlen(hex);
    if (hex_len == 0) {
        printf("Error: Empty hexadecimal number\n");
        return 1;
    }

    int dec_len = strlen(hex) / 2;
    hex_to_dec(hex, dec);

    printf("Decimal equivalent: %s\n", dec);

    int dec_num;
    sscanf(dec, "%d", &dec_num);

    char hex_num[MAX_HEX_LENGTH];
    dec_to_hex(dec_num, hex_num);

    printf("Hexadecimal equivalent: %s\n", hex_num);

    return 0;
}