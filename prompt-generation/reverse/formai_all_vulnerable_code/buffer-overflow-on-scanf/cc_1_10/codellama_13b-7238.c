//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_DIGITS 2

void hex_to_dec(char *hex_str, int *dec_num) {
    *dec_num = 0;
    int i, n;
    for (i = 0; i < strlen(hex_str); i++) {
        if (hex_str[i] >= '0' && hex_str[i] <= '9') {
            n = hex_str[i] - '0';
        } else if (hex_str[i] >= 'A' && hex_str[i] <= 'F') {
            n = hex_str[i] - 'A' + 10;
        } else if (hex_str[i] >= 'a' && hex_str[i] <= 'f') {
            n = hex_str[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal digit: %c\n", hex_str[i]);
            return;
        }
        *dec_num = *dec_num * 16 + n;
    }
}

void dec_to_hex(int dec_num, char *hex_str) {
    int i, n;
    for (i = 0; i < MAX_HEX_DIGITS; i++) {
        n = dec_num % 16;
        if (n < 10) {
            hex_str[i] = n + '0';
        } else {
            hex_str[i] = n - 10 + 'A';
        }
        dec_num /= 16;
    }
    hex_str[MAX_HEX_DIGITS] = '\0';
}

int main() {
    int dec_num, i;
    char hex_str[MAX_HEX_DIGITS + 1];

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_str);
    hex_to_dec(hex_str, &dec_num);
    printf("Decimal equivalent: %d\n", dec_num);

    dec_to_hex(dec_num, hex_str);
    printf("Hexadecimal equivalent: ");
    for (i = 0; i < MAX_HEX_DIGITS; i++) {
        printf("%c", hex_str[i]);
    }
    printf("\n");

    return 0;
}