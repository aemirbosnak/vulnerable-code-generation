//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10

void rgb_to_hex(unsigned char r, unsigned char g, unsigned char b, char hex[7]) {
    char hex_digits[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    hex[0] = hex_digits[(r >> 4) & 0xF];
    hex[1] = hex_digits[r & 0xF];
    hex[2] = hex_digits[(g >> 4) & 0xF];
    hex[3] = hex_digits[g & 0xF];
    hex[4] = hex_digits[(b >> 4) & 0xF];
    hex[5] = hex_digits[b & 0xF];
    hex[6] = '\0';
}

int main(void) {
    char c_color[MAX_LENGTH];
    unsigned char r, g, b;

    printf("Enter a C color code: ");
    scanf("%s", c_color);

    if (strlen(c_color) != 2 || (c_color[0] < '0' || c_color[0] > '9') || (c_color[1] < '0' || c_color[1] > '9')) {
        printf("Invalid C color code.\n");
        return 1;
    }

    r = (unsigned char)strtoul(&c_color[0], NULL, 16);
    g = (unsigned char)strtoul(&c_color[1], NULL, 16);

    rgb_to_hex(r, g, 0, "r: ");
    printf("R: ");
    putchar('0');
    putchar(r >> 4);
    putchar(r & 0xF);
    putchar(' ');

    rgb_to_hex(0, g, 0, "g: ");
    printf("G: ");
    putchar('0');
    putchar(g >> 4);
    putchar(g & 0xF);
    putchar(' ');

    rgb_to_hex(0, 0, 0, "b: ");
    printf("B: ");
    putchar('0');
    putchar(r & 0xF);
    putchar('\n');

    return 0;
}