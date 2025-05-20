//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 32
#define HEX_CHARS "0123456789ABCDEF"

int main() {
    char hex[MAX_HEX_LENGTH];
    char bin[MAX_HEX_LENGTH / 4 + 1];
    int hex_len, bin_len;
    int i, j;

    printf("Enter a hexadecimal number: ");
    fgets(hex, MAX_HEX_LENGTH, stdin);
    hex_len = strlen(hex);

    if (hex_len == 0) {
        printf("Invalid input\n");
        return 1;
    }

    hex_len = hex_len - 1;
    bin_len = hex_len / 4;

    for (i = 0, j = 0; i < hex_len; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            bin[j++] = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            bin[j++] = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            bin[j++] = hex[i] - 'a' + 10;
        } else {
            printf("Invalid input\n");
            return 1;
        }
    }

    printf("Binary equivalent: ");
    for (i = 0; i < bin_len; i++) {
        if (bin[i] == 0) {
            printf("0000");
        } else if (bin[i] == 1) {
            printf("0001");
        } else if (bin[i] == 2) {
            printf("0010");
        } else if (bin[i] == 3) {
            printf("0011");
        } else if (bin[i] == 4) {
            printf("0100");
        } else if (bin[i] == 5) {
            printf("0101");
        } else if (bin[i] == 6) {
            printf("0110");
        } else if (bin[i] == 7) {
            printf("0111");
        } else if (bin[i] == 8) {
            printf("1000");
        } else if (bin[i] == 9) {
            printf("1001");
        } else if (bin[i] == 10) {
            printf("1010");
        } else if (bin[i] == 11) {
            printf("1011");
        } else if (bin[i] == 12) {
            printf("1100");
        } else if (bin[i] == 13) {
            printf("1101");
        } else if (bin[i] == 14) {
            printf("1110");
        } else if (bin[i] == 15) {
            printf("1111");
        }
    }

    return 0;
}