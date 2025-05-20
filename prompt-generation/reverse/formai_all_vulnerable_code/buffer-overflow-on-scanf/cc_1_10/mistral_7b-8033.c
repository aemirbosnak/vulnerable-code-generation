//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 32

void hex_to_bin(unsigned char hex, unsigned char bin[4]) {
    int i;

    for (i = 0; i < 4; i++) {
        bin[3 - i] = (hex & (0x1 << (4 * i))) ? '1' : '0';
        hex >>= 4;
    }
}

void print_bin(unsigned char bin[4]) {
    int i;

    for (i = 0; i < 4; i++)
        printf("%c", bin[i]);
}

void hex_to_binary(char hex[]) {
    unsigned char bin[4];
    int i, len = strlen(hex);

    if (len != 2) {
        printf("Invalid hexadecimal value.\n");
        return;
    }

    for (i = 0; i < len; i++) {
        if (isdigit(hex[i]))
            hex[i] += '0' - '0' + 10;
        hex_to_bin(hex[i], bin);
        memmove(bin + 1, bin, 3);
    }

    print_bin(bin);
    printf("\n");
}

int main() {
    char hex[3];

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    hex_to_binary(hex);

    return 0;
}