//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define HEX_CHARS "0123456789ABCDEF"

// Function to check if a string is a valid hexadecimal number
int is_hex(char* str) {
    int len = strlen(str);
    if (len == 0) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isxdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a hexadecimal number to decimal
int hex_to_dec(char* str) {
    int len = strlen(str);
    int dec = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            dec += str[i] - '0';
        } else {
            dec += toupper(str[i]) - 'A' + 10;
        }
    }
    return dec;
}

int main() {
    char line[MAX_LINE_LENGTH];
    char hex_str[MAX_LINE_LENGTH];
    char dec_str[MAX_LINE_LENGTH];
    int hex_len;
    int dec_len;

    printf("Enter a hexadecimal number:\n");
    fgets(line, MAX_LINE_LENGTH, stdin);
    hex_len = strlen(line);

    // Remove any leading/trailing whitespace
    while (isspace(line[0])) {
        memmove(line, line + 1, hex_len - 1);
        hex_len--;
    }
    while (isspace(line[hex_len - 1])) {
        line[hex_len - 1] = '\0';
        hex_len--;
    }

    // Check if input is a valid hexadecimal number
    if (is_hex(line)) {
        // Convert to uppercase
        for (int i = 0; i < hex_len; i++) {
            hex_str[i] = toupper(line[i]);
        }

        // Convert to decimal
        dec_len = sprintf(dec_str, "%d", hex_to_dec(hex_str));

        // Print result
        printf("Hexadecimal: %s\n", line);
        printf("Decimal: %s\n", dec_str);
    } else {
        printf("Invalid hexadecimal number\n");
    }

    return 0;
}