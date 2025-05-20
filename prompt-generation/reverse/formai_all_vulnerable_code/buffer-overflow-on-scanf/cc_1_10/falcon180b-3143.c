//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LEN 100

void hex_to_dec(char *hex, int *dec) {
    int len = strlen(hex);
    int i = 0;
    int j = 0;
    int base = 0;
    int value = 0;

    for (i = 0; i < len; i++) {
        char c = hex[i];
        if (isdigit(c)) {
            value = c - '0';
        } else {
            if (isupper(c)) {
                c = tolower(c);
            }
            value = c - 'a' + 10;
        }
        base = (len - i - 1) * 16;
        dec[j++] = value + base;
    }
}

void dec_to_hex(int dec, char *hex) {
    int i = 0;
    int j = 0;
    int base = 0;

    while (dec > 0) {
        int rem = dec % 16;
        if (rem < 10) {
            hex[i++] = rem + '0';
        } else {
            hex[i++] = rem + 'a' - 10;
        }
        dec /= 16;
        base += 16;
    }

    while (i < MAX_HEX_LEN) {
        hex[i++] = '0';
    }
    hex[i] = '\0';

    for (i = 0, j = strlen(hex) - 1; i < j; i++, j--) {
        char tmp = hex[i];
        hex[i] = hex[j];
        hex[j] = tmp;
    }
}

int main() {
    char hex[MAX_HEX_LEN];
    int dec[MAX_HEX_LEN];
    int i;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    hex_to_dec(hex, dec);

    printf("Decimal representation: ");
    for (i = 0; i < strlen(hex); i++) {
        printf("%d", dec[i]);
        if (i!= strlen(hex) - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}