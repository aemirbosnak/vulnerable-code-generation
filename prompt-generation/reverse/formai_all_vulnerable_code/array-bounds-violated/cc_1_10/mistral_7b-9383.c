//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define B0 0x00
#define B1 0x01
#define B2 0x02
#define B3 0x03
#define B4 0x04
#define B5 0x05
#define B6 0x06
#define B7 0x07
#define B8 0x08
#define B9 0x09
#define BA 0x0A
#define BB 0x0B
#define BC 0x0C
#define BD 0x0D
#define BE 0x0E
#define BF 0x0F

typedef struct {
    uint8_t bytes[4];
} hex_t;

hex_t dec_to_hex(uint32_t dec) {
    hex_t hex;
    uint8_t i;

    for (i = 0; dec > 0; dec >>= 4) {
        hex.bytes[3 - (dec & 0xF)] |= (dec & 0xF) << (4 * (3 - (dec & 0xF)));
        dec >>= 4;
    }

    for (i = 0; i < 3; i++) {
        if (hex.bytes[i] > 9) {
            putchar(hex.bytes[i] + 0x37);
            hex.bytes[i] -= 0x10;
        } else {
            putchar(hex.bytes[i] + 0x30);
        }
    }

    putchar(hex.bytes[3]);
    putchar(' ');

    return hex;
}

int main(void) {
    uint32_t decimal;

    printf("Enter a decimal number: ");
    scanf("%u", &decimal);

    dec_to_hex(decimal);

    putchar('\n');

    return EXIT_SUCCESS;
}