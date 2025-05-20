//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// function to check if input is a valid hexadecimal number
int is_hex(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isxdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// function to convert decimal to hexadecimal
char *dec_to_hex(int dec) {
    char hex_str[9];
    sprintf(hex_str, "%X", dec);
    return strdup(hex_str);
}

// function to convert hexadecimal to decimal
int hex_to_dec(char *hex) {
    int dec = 0;
    int len = strlen(hex);
    for (int i = 0; i < len; i++) {
        int c = hex[i];
        if (isdigit(c)) {
            dec = dec * 16 + c - '0';
        } else {
            dec = dec * 16 + c - 'A' + 10;
        }
    }
    return dec;
}

int main() {
    char input[1000];
    printf("Enter a hexadecimal number: ");
    fgets(input, 1000, stdin);
    int len = strlen(input);
    if (len == 0) {
        printf("Input is empty.\n");
        return 1;
    }
    input[len - 1] = '\0'; // remove newline character
    if (!is_hex(input)) {
        printf("Input is not a valid hexadecimal number.\n");
        return 1;
    }
    int dec = hex_to_dec(input);
    char *hex_str = dec_to_hex(dec);
    printf("Decimal equivalent: %s\n", hex_str);
    return 0;
}