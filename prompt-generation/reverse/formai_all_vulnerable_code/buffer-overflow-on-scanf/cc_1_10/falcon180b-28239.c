//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX_CHARS 8

char *hex_to_str(int num) {
    char hex_str[MAX_HEX_CHARS + 1];
    char *hex_ptr = hex_str;
    int i;

    for (i = 0; i < MAX_HEX_CHARS; i++) {
        int digit = num & 0x000F;
        if (digit < 10) {
            *hex_ptr = digit + '0';
        } else {
            *hex_ptr = digit - 10 + 'A';
        }
        hex_ptr++;
        num >>= 4;
    }

    *hex_ptr = '\0';

    return hex_str;
}

int str_to_hex(char *str) {
    int hex = 0;
    int i;

    for (i = 0; i < strlen(str); i++) {
        char ch = tolower(str[i]);
        if (isdigit(ch)) {
            hex = (hex << 4) | (ch - '0');
        } else if (isalpha(ch)) {
            if (ch >= 'a') {
                hex = (hex << 4) | (ch - 'a' + 10);
            } else {
                hex = (hex << 4) | (ch - '0');
            }
        } else {
            return -1;
        }
    }

    return hex;
}

int main() {
    char input_str[MAX_HEX_CHARS + 1];
    int input_hex;
    char *output_str;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input_str);

    input_hex = str_to_hex(input_str);

    if (input_hex == -1) {
        printf("Invalid input.\n");
        exit(1);
    }

    output_str = hex_to_str(input_hex);

    printf("The hexadecimal number is: %s\n", output_str);

    return 0;
}