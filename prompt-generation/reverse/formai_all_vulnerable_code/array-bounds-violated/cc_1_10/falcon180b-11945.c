//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LEN 1000000 // Maximum length of hex string
#define MAX_DEC_LEN 1000000 // Maximum length of decimal string

int main(int argc, char *argv[]) {
    char hex_str[MAX_HEX_LEN]; // Hexadecimal string
    char dec_str[MAX_DEC_LEN]; // Decimal string
    int i, j, len, dec_len; // Loop variables and string lengths
    int hex_val, dec_val; // Hexadecimal and decimal values

    // Prompt user for hexadecimal string
    printf("Enter a hexadecimal string: ");
    fgets(hex_str, MAX_HEX_LEN, stdin);

    // Remove newline character from input string
    len = strlen(hex_str);
    hex_str[len - 1] = '\0';

    // Convert hexadecimal string to decimal string
    for (i = 0, j = 0; i < len; i++) {
        if (isxdigit(hex_str[i])) { // Check if character is hexadecimal
            hex_val = 0;
            if (isdigit(hex_str[i])) { // Check if character is decimal digit
                hex_val = hex_str[i] - '0';
            } else { // Character is hexadecimal digit
                if (hex_str[i] >= 'A' && hex_str[i] <= 'F') {
                    hex_val = hex_str[i] - 'A' + 10;
                } else if (hex_str[i] >= 'a' && hex_str[i] <= 'f') {
                    hex_val = hex_str[i] - 'a' + 10;
                }
            }
            dec_val = hex_val * 16; // Convert hexadecimal value to decimal value
            if (j >= MAX_DEC_LEN - 1) { // Check if decimal string is full
                printf("Error: Decimal string is too long.\n");
                exit(1);
            }
            dec_str[j++] = dec_val + '0'; // Append decimal digit to decimal string
        }
    }
    dec_str[j] = '\0'; // Terminate decimal string

    // Print decimal string
    printf("Decimal string: %s\n", dec_str);

    return 0;
}