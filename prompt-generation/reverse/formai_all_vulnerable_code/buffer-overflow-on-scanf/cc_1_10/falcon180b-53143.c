//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_STR_LEN 100

void hex_to_dec(char *hex_str, char *dec_str) {
    int i = 0, j = 0;
    while (i < strlen(hex_str)) {
        if (isxdigit(hex_str[i])) {
            if (isdigit(hex_str[i])) {
                dec_str[j] = hex_str[i] - '0';
            } else {
                dec_str[j] = hex_str[i] - 'A' + 10;
            }
            j++;
        }
        i++;
    }
    dec_str[j] = '\0';
}

void dec_to_hex(int dec_num, char *hex_str) {
    int i = 0;
    char hex_digit;
    while (dec_num > 0) {
        hex_digit = dec_num % 16;
        if (hex_digit < 10) {
            hex_str[i] = hex_digit + '0';
        } else {
            hex_str[i] = hex_digit + 'A' - 10;
        }
        dec_num /= 16;
        i++;
    }
    hex_str[i] = '\0';
}

int main() {
    char hex_str[MAX_HEX_STR_LEN], dec_str[MAX_HEX_STR_LEN];
    int dec_num;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_str);

    hex_to_dec(hex_str, dec_str);

    printf("Decimal equivalent: %s\n", dec_str);

    dec_to_hex(atoi(dec_str), hex_str);

    printf("Hexadecimal equivalent: %s\n", hex_str);

    return 0;
}