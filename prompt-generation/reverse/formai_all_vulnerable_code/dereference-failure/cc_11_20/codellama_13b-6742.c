//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
/*
 * Hexadecimal Converter
 *
 * This program converts a hexadecimal number to its decimal equivalent.
 *
 * Usage:
 * 1. Run the program with a hexadecimal number as the first argument.
 * 2. The program will output the decimal equivalent of the hexadecimal number.
 *
 * Example:
 * ./hexconv 0xFF
 * Output: 255
 *
 * Author: Linus Torvalds
 * Date: 2023-02-20
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hexadecimal number>\n", argv[0]);
        return 1;
    }

    char *hex_str = argv[1];
    if (strlen(hex_str) != 2 || hex_str[0] != '0' || hex_str[1] != 'x') {
        fprintf(stderr, "Invalid hexadecimal number: %s\n", hex_str);
        return 1;
    }

    int dec_num = 0;
    for (int i = 2; i < strlen(hex_str); i++) {
        if (hex_str[i] >= '0' && hex_str[i] <= '9') {
            dec_num = (dec_num * 16) + (hex_str[i] - '0');
        } else if (hex_str[i] >= 'A' && hex_str[i] <= 'F') {
            dec_num = (dec_num * 16) + (hex_str[i] - 'A' + 10);
        } else if (hex_str[i] >= 'a' && hex_str[i] <= 'f') {
            dec_num = (dec_num * 16) + (hex_str[i] - 'a' + 10);
        } else {
            fprintf(stderr, "Invalid hexadecimal number: %s\n", hex_str);
            return 1;
        }
    }

    printf("Decimal equivalent of %s is %d\n", hex_str, dec_num);

    return 0;
}