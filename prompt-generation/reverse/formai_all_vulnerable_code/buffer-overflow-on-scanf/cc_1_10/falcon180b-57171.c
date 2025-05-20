//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 10
#define MAX_ASCII_LENGTH 50

void convert_hex_to_ascii(char* hex, char* ascii) {
    int i, j;
    for (i = 0, j = 0; i < strlen(hex); i += 2, j++) {
        char hex_char = hex[i];
        if (hex_char >= '0' && hex_char <= '9') {
            ascii[j] = hex_char - '0';
        }
        else if (hex_char >= 'A' && hex_char <= 'F') {
            ascii[j] = hex_char - 'A' + 10;
        }
        else if (hex_char >= 'a' && hex_char <= 'f') {
            ascii[j] = hex_char - 'a' + 10;
        }
        else {
            printf("Invalid hex character: %c\n", hex_char);
            exit(1);
        }
    }
    ascii[j] = '\0';
}

void convert_ascii_to_hex(char* ascii, char* hex) {
    int i, j;
    for (i = 0, j = 0; i < strlen(ascii); i++) {
        char ascii_char = ascii[i];
        if (ascii_char >= '0' && ascii_char <= '9') {
            sprintf(hex + j, "%c", ascii_char);
            j += 1;
        }
        else if (ascii_char >= 'A' && ascii_char <= 'F') {
            sprintf(hex + j, "%c", ascii_char);
            j += 1;
        }
        else if (ascii_char >= 'a' && ascii_char <= 'f') {
            sprintf(hex + j, "%c", ascii_char);
            j += 1;
        }
        else {
            printf("Invalid ASCII character: %c\n", ascii_char);
            exit(1);
        }
    }
    hex[j] = '\0';
}

int main() {
    char hex[MAX_HEX_LENGTH];
    char ascii[MAX_ASCII_LENGTH];
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex);
    printf("Enter an ASCII string: ");
    scanf("%s", ascii);
    convert_hex_to_ascii(hex, ascii);
    printf("ASCII representation of hexadecimal string: %s\n", ascii);
    convert_ascii_to_hex(ascii, hex);
    printf("Hexadecimal representation of ASCII string: %s\n", hex);
    return 0;
}