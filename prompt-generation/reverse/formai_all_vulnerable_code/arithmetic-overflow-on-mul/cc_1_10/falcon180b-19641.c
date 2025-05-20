//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isHex(char c) {
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'A' && c <= 'F')
        return 1;
    if (c >= 'a' && c <= 'f')
        return 1;
    return 0;
}

int isBin(char c) {
    if (c == '0' || c == '1')
        return 1;
    return 0;
}

int toDecimal(char hex) {
    if (hex >= '0' && hex <= '9')
        return hex - '0';
    if (hex >= 'A' && hex <= 'F')
        return hex - 'A' + 10;
    if (hex >= 'a' && hex <= 'f')
        return hex - 'a' + 10;
    return -1;
}

int toHex(int dec) {
    if (dec >= 0 && dec <= 9)
        return dec + '0';
    if (dec >= 10 && dec <= 15)
        return dec - 10 + 'A';
    return -1;
}

int toBin(int dec) {
    if (dec == 0)
        return '0';
    if (dec == 1)
        return '1';
    int bin = 0;
    while (dec > 0) {
        bin = bin * 2 + dec % 2;
        dec /= 2;
    }
    return bin;
}

int main() {
    char input[1000];
    int len;
    printf("Enter hexadecimal number: ");
    fgets(input, 1000, stdin);
    len = strlen(input);
    if (len == 0) {
        printf("Empty input!\n");
        return 0;
    }
    if (input[len - 1] == '\n')
        input[len - 1] = '\0';
    int decimal = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (!isHex(input[i])) {
            printf("Invalid hexadecimal input!\n");
            return 0;
        }
        decimal = decimal * 16 + toDecimal(input[i]);
    }
    printf("Decimal: %d\n", decimal);
    printf("Binary: ");
    for (i = 31; i >= 0; i--) {
        if (decimal % 2 == 1)
            printf("%d", 1);
        else
            printf("%d", 0);
        decimal /= 2;
    }
    printf("\n");
    return 0;
}