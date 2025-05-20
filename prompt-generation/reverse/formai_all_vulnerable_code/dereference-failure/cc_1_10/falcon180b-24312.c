//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LEN 20
#define MAX_DEC_LEN 10

int main(int argc, char *argv[]) {
    char hex[MAX_HEX_LEN], dec[MAX_DEC_LEN];
    int hex_len, dec_len;

    // check if the number of arguments is correct
    if (argc!= 3) {
        printf("usage: %s hex_number\n", argv[0]);
        return 1;
    }

    // convert hexadecimal to uppercase
    strcpy(hex, argv[1]);
    for (int i = 0; i < strlen(hex); i++) {
        if (isxdigit(hex[i])) {
            hex[i] = toupper(hex[i]);
        }
    }

    // check if the hexadecimal number is valid
    for (int i = 0; i < strlen(hex); i++) {
        if (!isxdigit(hex[i])) {
            printf("invalid hexadecimal number\n");
            return 1;
        }
    }

    // convert hexadecimal to decimal
    hex_len = strlen(hex);
    dec_len = (hex_len / 2) + (hex_len % 2);
    for (int i = 0; i < hex_len; i++) {
        if (i % 2 == 0) {
            dec[i / 2] = hex[i] - '0';
        } else {
            dec[i / 2] = hex[i] - 'A' + 10;
        }
    }
    dec[dec_len] = '\0';

    // print the decimal equivalent
    printf("decimal equivalent: %s\n", dec);

    return 0;
}