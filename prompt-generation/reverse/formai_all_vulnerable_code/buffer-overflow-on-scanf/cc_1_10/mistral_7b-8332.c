//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void hex_string_to_bin(char *hex_str, unsigned char *bin_arr, int len) {
    int i, j;
    char hex_char;
    unsigned char bin_byte = 0;

    for (i = 0; i < len; i++) {
        hex_char = hex_str[i];

        if (isxdigit(hex_char)) {
            hex_char = isdigit(hex_char) ? hex_char - '0' : hex_char - 'A' + 10;
            for (j = 0; j < 4; j++) {
                bin_arr[i * 4 + j] = (hex_char >> (3 * (3 - j))) & 1;
            }
        }
    }
}

void print_binary(unsigned char *bin_arr, int len) {
    int i;

    for (i = 0; i < len; i++) {
        printf("%c", (i % 8 == 0) ? ' ' : (bin_arr[i] == 0) ? '0' : '1');

        if ((i + 1) % 8 == 0 || i == len - 1) {
            printf(" ");
        }
    }

    printf("\n");
}

int main() {
    char hex_str[128];
    unsigned char bin_arr[32];
    int len;

    printf("Enter a hexadecimal string: ");
    scanf("%s", hex_str);

    len = strlen(hex_str);

    if (len % 2 == 1) {
        printf("Error: Hexadecimal string must have an even number of characters.\n");
        return 1;
    }

    hex_string_to_bin(hex_str, bin_arr, len / 2);
    print_binary(bin_arr, len / 2);

    return 0;
}

// Shocked style:
// O_o!!! Enter a hexadecimal string: O_o
// !!! O_o Hexadecimal string must have an even number of characters. O_o
// !!! !!! 10101101 11011001 11110110 11111111 O_o
// !!! !!! !!!