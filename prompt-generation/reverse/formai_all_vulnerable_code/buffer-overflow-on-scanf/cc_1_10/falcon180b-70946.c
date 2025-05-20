//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int is_valid_hex_digit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else if (c >= 'A' && c <= 'F') {
        return 1;
    } else if (c >= 'a' && c <= 'f') {
        return 1;
    } else {
        return 0;
    }
}

int hex_to_dec(char *hex) {
    int dec = 0, i = 0, j = strlen(hex) - 1;
    while (i <= j) {
        char c = hex[i];
        if (is_valid_hex_digit(c)) {
            dec += (c - '0');
        } else if (c >= 'A' && c <= 'F') {
            dec += (c - 'A' + 10);
        } else if (c >= 'a' && c <= 'f') {
            dec += (c - 'a' + 10);
        }
        i++;
    }
    return dec;
}

char *dec_to_hex(int dec) {
    char *hex = malloc(MAX_SIZE * sizeof(char));
    int i = 0, j = 0;
    while (dec > 0) {
        int digit = dec % 16;
        if (digit < 10) {
            hex[i++] = digit + '0';
        } else {
            hex[i++] = digit + 'A' - 10;
        }
        dec /= 16;
    }
    while (i < MAX_SIZE) {
        hex[i++] = '0';
    }
    return hex;
}

int main() {
    char input[MAX_SIZE];
    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    if (is_valid_hex_digit(input[0]) && strlen(input) <= 8) {
        int dec = hex_to_dec(input);
        char *hex = dec_to_hex(dec);
        printf("The decimal representation of %s is %s.\n", input, hex);
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}