//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 3

typedef struct {
    unsigned char r, g, b;
} RGB;

void rgb_to_hex(RGB color) {
    unsigned char hex[3][2];
    for (int i = 0; i < SIZE; i++) {
        hex[i][0] = (color.r >> (4 * (2 - i))) & 0xF;
        hex[i][0] = hex[i][0] < 10 ? '0' + hex[i][0] : hex[i][0] + 'A' - 10;
        hex[i][1] = color.r >> (4 * i) & 0xF;
        hex[i][1] = hex[i][1] < 10 ? '0' + hex[i][1] : hex[i][1] + 'A' - 10;
    }
    printf("%s%s%s\n", hex[0], hex[1], hex[2]);
}

void hex_to_rgb(char hex[7]) {
    RGB color;
    unsigned char c;
    int index = 0;

    for (int i = 0; i < SIZE; i++) {
        color.r = 0;
        color.g = 0;
        color.b = 0;

        if (hex[index++] != '#') return;

        c = hex[index++] & 0xF;
        color.r |= c << (4 * (2 - SIZE + i));

        c = hex[index++] & 0xF;
        color.g |= c << (4 * i);

        if (i < SIZE - 1) continue;

        c = hex[index++] & 0xF;
        color.b |= c << (4 * (SIZE - 1 - i));

        rgb_to_hex(color);
        break;
    }
}

int main() {
    char hex_input[8];
    RGB rgb_output;

    printf("Enter HEX color code: ");
    scanf("%s", hex_input);

    hex_to_rgb(hex_input);

    return 0;
}