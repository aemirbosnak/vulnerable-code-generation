//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX_LENGTH 100

// Function to check if a string is a valid hexadecimal number
int is_hex(char *hex) {
    int len = strlen(hex);
    if (len == 0) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isxdigit(hex[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert decimal to hexadecimal
void dec_to_hex(int dec, char *hex) {
    char hex_str[MAX_HEX_LENGTH];
    sprintf(hex_str, "%X", dec);
    strcpy(hex, hex_str);
}

// Function to convert hexadecimal to decimal
int hex_to_dec(char *hex) {
    int dec = 0;
    int len = strlen(hex);
    for (int i = 0; i < len; i++) {
        char c = hex[i];
        if (isdigit(c)) {
            dec = dec * 16 + c - '0';
        } else {
            dec = dec * 16 + toupper(c) - 'A' + 10;
        }
    }
    return dec;
}

int main() {
    char hex[MAX_HEX_LENGTH];
    char input[MAX_HEX_LENGTH];
    int dec;

    // Prompt user for input
    printf("Enter a decimal number: ");
    scanf("%s", input);

    // Convert decimal to hexadecimal
    dec_to_hex(atoi(input), hex);

    // Display the hexadecimal number
    printf("Hexadecimal: %s\n", hex);

    // Prompt user for input
    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Convert hexadecimal to decimal
    if (is_hex(input)) {
        dec = hex_to_dec(input);
        printf("Decimal: %d\n", dec);
    } else {
        printf("Invalid hexadecimal number\n");
    }

    return 0;
}