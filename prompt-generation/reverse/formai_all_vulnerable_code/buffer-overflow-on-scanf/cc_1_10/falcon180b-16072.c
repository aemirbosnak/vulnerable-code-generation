//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void hex_to_dec(char hex[], int hex_len, char dec[], int *dec_len) {
    int i, j, k;
    for (i = 0, j = 0; i < hex_len; i++) {
        if (isdigit(hex[i])) {
            dec[j++] = hex[i];
        } else {
            k = toupper(hex[i]) - 'A' + 10;
            if (k > 15) {
                printf("Error: Invalid hexadecimal character '%c' at position %d.\n", hex[i], i + 1);
                exit(1);
            }
            dec[j++] = k;
        }
    }
    *dec_len = j;
}

void dec_to_hex(char dec[], int dec_len, char hex[], int *hex_len) {
    int i;
    for (i = 0; i < dec_len; i++) {
        sprintf(hex + 2 * i, "%02X", dec[i]);
    }
    *hex_len = 2 * dec_len;
}

int main() {
    char hex[MAX_LENGTH], dec[MAX_LENGTH];
    int hex_len, dec_len;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    hex_len = strlen(hex);

    if (hex_len == 0 || hex_len > MAX_LENGTH) {
        printf("Error: Invalid hexadecimal number.\n");
        exit(1);
    }

    hex_to_dec(hex, hex_len, dec, &dec_len);

    printf("Decimal equivalent: ");
    for (int i = dec_len - 1; i >= 0; i--) {
        printf("%c", dec[i]);
    }
    printf("\n");

    dec_to_hex(dec, dec_len, hex, &hex_len);

    printf("Hexadecimal equivalent: ");
    for (int i = hex_len - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n");

    return 0;
}