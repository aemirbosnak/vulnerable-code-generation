//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX_LEN 100

int is_hex(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}

int is_bin(char c) {
    return c == '0' || c == '1';
}

char to_hex(int val) {
    char hex = 0;
    int i = 0;
    while (val > 0) {
        int rem = val % 16;
        if (rem < 10) {
            hex = (char) (rem + '0');
        } else {
            hex = (char) (rem + 'A' - 10);
        }
        val /= 16;
        i++;
    }
    return hex;
}

char to_bin(int val) {
    char bin[MAX_HEX_LEN];
    int i = 0;
    while (val > 0) {
        int rem = val % 2;
        bin[i] = (char) (rem + '0');
        val /= 2;
        i++;
    }
    bin[i] = '\0';
    return bin;
}

int main() {
    char hex[MAX_HEX_LEN];
    char bin[MAX_HEX_LEN];
    int hex_len, bin_len;
    int i;

    printf("Enter a hexadecimal number: ");
    fgets(hex, MAX_HEX_LEN, stdin);
    hex_len = strlen(hex);

    for (i = 0; i < hex_len; i++) {
        if (!is_hex(hex[i])) {
            printf("Invalid hexadecimal number.\n");
            return 1;
        }
    }

    printf("Enter the number of bits: ");
    scanf("%d", &bin_len);

    for (i = 0; i < bin_len; i++) {
        if (!is_bin(hex[i])) {
            printf("Invalid hexadecimal number.\n");
            return 1;
        }
    }

    printf("Hexadecimal: %s\n", hex);
    printf("Binary: %s\n", to_bin(hex_len));

    return 0;
}