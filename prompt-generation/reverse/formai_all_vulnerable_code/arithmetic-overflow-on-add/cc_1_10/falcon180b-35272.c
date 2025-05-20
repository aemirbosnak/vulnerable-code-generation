//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 16
#define MAX_DEC_LENGTH 11

void hex_to_dec(char hex[], int hex_len, int* dec, int* dec_len) {
    int i, j;
    int dec_val = 0;

    for (i = 0, j = *dec_len - 1; i < hex_len; i++, j--) {
        if (isdigit(hex[i])) {
            dec_val += (hex[i] - '0') * pow(16, (hex_len - 1 - i));
        } else if (isalpha(hex[i])) {
            if (isupper(hex[i])) {
                dec_val += (hex[i] - 'A' + 10) * pow(16, (hex_len - 1 - i));
            } else {
                dec_val += (hex[i] - 'a' + 10) * pow(16, (hex_len - 1 - i));
            }
        }
    }

    *dec = dec_val;
    *dec_len = j + 1;
}

void dec_to_hex(int dec, char hex[], int hex_len) {
    char* hex_str = "0123456789ABCDEF";
    int i, j;

    for (i = 0, j = hex_len - 1; i < (int)log(dec + 1) / log(16); i++, j--) {
        int rem = dec % 16;

        if (rem < 10) {
            hex[j] = rem + '0';
        } else {
            hex[j] = hex_str[rem - 10];
        }

        dec /= 16;
    }

    hex[j + 1] = '\0';
}

int main() {
    char hex_str[MAX_HEX_LENGTH];
    int hex_len, dec_len;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_str);

    hex_len = strlen(hex_str);

    if (hex_len > MAX_HEX_LENGTH) {
        printf("Error: Hexadecimal number too long.\n");
        return 1;
    }

    int dec_val;
    hex_to_dec(hex_str, hex_len, &dec_val, &dec_len);

    char dec_str[MAX_DEC_LENGTH];
    dec_to_hex(dec_val, dec_str, dec_len);

    printf("Decimal equivalent: %s\n", dec_str);

    return 0;
}