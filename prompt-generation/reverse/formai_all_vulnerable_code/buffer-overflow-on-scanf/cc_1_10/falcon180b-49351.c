//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hexToDec(char hex[]) {
    int dec = 0, i = 0, len = strlen(hex);
    while (i < len) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec = dec * 16 + hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec = dec * 16 + hex[i] - 'A' + 10;
        } else {
            printf("Invalid hexadecimal character %c\n", hex[i]);
            exit(1);
        }
        i++;
    }
    return dec;
}

int decToHex(int dec, char hex[]) {
    int i = 0, len = 0;
    while (dec!= 0) {
        if (dec % 16 >= 10) {
            hex[i++] = dec % 16 + 'A';
        } else {
            hex[i++] = dec % 16 + '0';
        }
        dec /= 16;
        len++;
    }
    hex[i] = '\0';
    return len;
}

int main() {
    char hex[1000], dec[1000];
    int i, len;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    len = strlen(hex);

    if (len > 0) {
        for (i = 0; i < len; i++) {
            if (!(hex[i] >= '0' && hex[i] <= '9') &&!(hex[i] >= 'A' && hex[i] <= 'F') &&!(hex[i] >= 'a' && hex[i] <= 'f')) {
                printf("Invalid hexadecimal character %c\n", hex[i]);
                exit(1);
            }
        }

        int dec_val = hexToDec(hex);
        int dec_len = decToHex(dec_val, dec);

        printf("Decimal equivalent: %s\n", dec);
        printf("Length of decimal equivalent: %d\n", dec_len);
    } else {
        printf("Invalid hexadecimal number\n");
    }

    return 0;
}