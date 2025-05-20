//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 100
#define MAX_DEC_LENGTH 33

void hexToDec(char *hex, int hexLen, char *dec) {
    int i, j, carry = 0;
    for (i = 0, j = hexLen - 1; i < hexLen; i++, j--) {
        int hexDigit = hex[i] - '0';
        if (hexDigit > 9) {
            hexDigit -= 7;
            if (hexDigit > 9) {
                hexDigit -= 6;
            }
        }
        int decDigit = hexDigit * 16 + carry;
        carry = decDigit / 10;
        dec[j] = decDigit % 10 + '0';
    }
    dec[hexLen - 1] = '\0';
}

void decToHex(char *dec, int decLen, char *hex) {
    int i, j, carry = 0;
    for (i = decLen - 1, j = 0; i >= 0; i--, j++) {
        int decDigit = dec[i] - '0';
        int hexDigit = decDigit % 16;
        if (hexDigit > 9) {
            hexDigit += 7;
        }
        if (carry > 0 || hexDigit > 0) {
            hex[j] = hexDigit + '0';
        }
        carry = decDigit / 16;
    }
    hex[j] = '\0';
}

int main() {
    char hex[MAX_HEX_LENGTH];
    char dec[MAX_DEC_LENGTH];
    int hexLen, decLen;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    hexLen = strlen(hex);
    if (hexLen == 0 || hex[0] == '\0') {
        printf("Invalid hexadecimal number.\n");
        return 1;
    }
    decLen = strlen(hex) * 2;
    if (decLen > MAX_DEC_LENGTH) {
        printf("Hexadecimal number too large.\n");
        return 1;
    }
    decToHex(hex, hexLen, dec);
    printf("Decimal equivalent: %s\n", dec);
    hexToDec(hex, hexLen, dec);
    printf("Hexadecimal equivalent: %s\n", dec);
    return 0;
}