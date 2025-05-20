//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX_CHARS 50

void die(const char *msg) {
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

int hex_str_to_bin(const char *hex_str, unsigned char *bin_arr, size_t len) {
    if (len % 2 != 0) die("Invalid hex string length.\n");

    for (size_t i = 0; i < len; i += 2) {
        int hex = strtol(&hex_str[i], NULL, 16);
        if (i + 2 > len) die("Invalid hex string format.\n");

        bin_arr[i / 2] = (hex >> 4) & 0x0F;
        bin_arr[i / 2] |= (hex & 0x0F) << 4;

        if (isdigit(hex_str[i + 1])) bin_arr[i / 2] <<= 1;

        hex_str += i + 2;
    }

    return 0;
}

void print_bin(const unsigned char *bin_arr, size_t len) {
    printf("Binary: ");
    for (size_t i = 0; i < len; ++i) {
        printf("%c", i % 8 == 0 ? ' ' : '0' + (bin_arr[i] >> 7));
        printf("%c", i % 8 == 7 || i == len - 1 ? '\n' : ' ');
        for (size_t j = 0; j < 8; ++j) {
            printf("%c", '0' + (bin_arr[i] >> j & 0x01));
        }
    }
}

int main() {
    char hex_str[MAX_HEX_CHARS];
    unsigned char bin_arr[MAX_HEX_CHARS / 2];

    printf("Radiosonde Hexadecimal to Binary Converter v1.0.0\n");
    printf("=============================================\n");

    printf("Enter a hexadecimal string: ");
    scanf("%s", hex_str);

    size_t len = strlen(hex_str);
    if (hex_str_to_bin(hex_str, bin_arr, len)) die("Error converting hexadecimal to binary.\n");

    printf("Input hexadecimal: %s\n", hex_str);
    printf("Output binary: ");
    print_bin(bin_arr, len / 2);

    free(bin_arr);

    return EXIT_SUCCESS;
}