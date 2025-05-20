//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char r, g, b;
} Color;

Color hex2rgb(char hex[3]) {
    Color rgb;
    int dec;

    hex[0] = toupper(hex[0]);
    hex[1] = toupper(hex[1]);

    dec = strtol(&hex[0], NULL, 16);
    rgb.r = (dec >> 4) * 17 / 16;
    rgb.b = dec % 16 * 17 / 16;

    dec = strtol(&hex[2], NULL, 16);
    rgb.g = (dec >> 4) * 17 / 16;
    rgb.b += rgb.g;

    return rgb;
}

char* rgb2hex(Color rgb) {
    static char hex[3][3] = {"00", "0A", "10", "1E", "26", "32", "3C", "46", "4C", "54",
                              "5E", "68", "74", "7C", "86", "91", "9E", "A8", "AA", "B2",
                              "BB", "C1", "C9", "D3", "DA", "E1", "E8", "EE", "F4", "FA",
                              "FF"};

    char* hex_str = malloc(3 * sizeof(char));

    hex_str[0] = hex[(rgb.r / 17) % 16][0];
    hex_str[1] = hex[(rgb.r % 17) / 16][0];
    hex_str[2] = hex[rgb.r % 17][0];

    hex_str[1] = (hex_str[1] < 'A' ? hex_str[1] + '0' : hex_str[1] + 'A' - 10);
    hex_str[2] = (hex_str[2] < 'A' ? hex_str[2] + '0' : hex_str[2] + 'A' - 10);

    return hex_str;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <HEX color>\n", argv[0]);
        return 1;
    }

    Color color = hex2rgb(argv[1]);
    char* hex_str = rgb2hex(color);

    printf("RGB(%d, %d, %d) -> #%s\n", (int)color.r, (int)color.g, (int)color.b, hex_str);
    free(hex_str);
    return 0;
}