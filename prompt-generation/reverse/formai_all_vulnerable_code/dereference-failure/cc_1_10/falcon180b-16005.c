//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 1000
#define HEX_DIGITS "0123456789ABCDEF"

int main(int argc, char *argv[]) {
    char *hex_str = NULL;
    int hex_len = 0;
    char *output_str = NULL;
    int output_len = 0;

    if (argc!= 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        return 1;
    }

    hex_str = argv[1];
    hex_len = strlen(hex_str);

    if (hex_len % 2!= 0) {
        printf("Error: Input string must be an even number of characters.\n");
        return 1;
    }

    output_len = hex_len / 2;
    output_str = malloc(output_len + 1);

    if (output_str == NULL) {
        printf("Error: Unable to allocate memory.\n");
        return 1;
    }

    for (int i = 0; i < hex_len; i += 2) {
        char hex_digit = hex_str[i];

        if (!isxdigit(hex_digit)) {
            printf("Error: Invalid hexadecimal character at position %d.\n", i);
            free(output_str);
            return 1;
        }

        char ascii_digit = (hex_digit >= '0' && hex_digit <= '9')? hex_digit - '0' : hex_digit - 'A' + 10;
        output_str[i / 2] = ascii_digit;
    }

    output_str[output_len] = '\0';

    printf("Hexadecimal string: %s\n", hex_str);
    printf("ASCII string: %s\n", output_str);

    free(output_str);
    return 0;
}