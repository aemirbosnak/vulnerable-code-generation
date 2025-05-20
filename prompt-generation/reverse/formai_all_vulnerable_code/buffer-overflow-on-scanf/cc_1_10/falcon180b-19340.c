//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Function to check if a string is a valid hexadecimal number
bool isValidHex(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = tolower(str[i]);
        if (!isxdigit(c)) {
            return false;
        }
    }
    return true;
}

// Function to convert a hexadecimal string to a decimal number
long long int hexToDec(char *str) {
    int len = strlen(str);
    long long int dec = 0;
    for (int i = 0; i < len; i++) {
        char c = tolower(str[i]);
        if (c >= '0' && c <= '9') {
            dec = dec * 16 + (c - '0');
        } else if (c >= 'a' && c <= 'f') {
            dec = dec * 16 + (c - 'a' + 10);
        } else {
            printf("Invalid hexadecimal character: %c\n", c);
            exit(1);
        }
    }
    return dec;
}

// Function to convert a decimal number to a hexadecimal string
void decToHex(long long int dec, char *hex, int size) {
    char hexChars[] = "0123456789abcdef";
    int len = 0;
    while (dec > 0) {
        hex[len++] = hexChars[dec % 16];
        dec /= 16;
    }
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n");
}

int main() {
    char hexStr[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hexStr);
    if (!isValidHex(hexStr)) {
        printf("Invalid hexadecimal number.\n");
        exit(1);
    }
    long long int dec = hexToDec(hexStr);
    char decStr[20];
    decToHex(dec, decStr, sizeof(decStr));
    printf("Decimal equivalent: %s\n", decStr);
    return 0;
}