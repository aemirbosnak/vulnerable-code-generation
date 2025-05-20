//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a hexadecimal string to decimal
int hex_to_dec(char* str) {
    int len = strlen(str);
    int dec = 0;
    for (int i = 0; i < len; i++) {
        char c = tolower(str[i]);
        if (c >= '0' && c <= '9') {
            dec = dec * 16 + c - '0';
        } else if (c >= 'a' && c <= 'f') {
            dec = dec * 16 + c - 'a' + 10;
        } else {
            printf("Invalid hexadecimal character: %c\n", c);
            return 0;
        }
    }
    return dec;
}

// Function to convert a decimal integer to binary
void dec_to_bin(int dec) {
    char bin[33];
    int i = 0;
    while (dec > 0) {
        bin[i++] = dec % 2 + '0';
        dec /= 2;
    }
    bin[i] = '\0';
    printf("Binary: %s\n", bin);
}

// Function to convert a decimal integer to octal
void dec_to_oct(int dec) {
    char oct[11];
    int i = 0;
    while (dec > 0) {
        oct[i++] = dec % 8 + '0';
        dec /= 8;
    }
    oct[i] = '\0';
    printf("Octal: %s\n", oct);
}

// Function to convert a decimal integer to hexadecimal
void dec_to_hex(int dec) {
    char hex[9];
    int i = 0;
    while (dec > 0) {
        char c = dec % 16 + (dec % 16 < 10? '0' : 'a' - 10);
        hex[i++] = c;
        dec /= 16;
    }
    hex[i] = '\0';
    printf("Hexadecimal: %s\n", hex);
}

int main() {
    char input[100];
    printf("Enter a number in hexadecimal format: ");
    scanf("%s", input);
    int dec = hex_to_dec(input);
    if (dec == 0) {
        return 0;
    }
    printf("Decimal: %d\n", dec);
    dec_to_bin(dec);
    dec_to_oct(dec);
    dec_to_hex(dec);
    return 0;
}