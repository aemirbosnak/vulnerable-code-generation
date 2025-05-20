//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: complete
/*
 * Color Code Converter
 *
 * This program converts a color code from one format to another.
 *
 * Usage:
 *      ./color_code_converter <from_format> <to_format> <color_code>
 *
 *      <from_format>  : The format of the input color code
 *      <to_format>    : The format of the output color code
 *      <color_code>   : The color code to be converted
 *
 * Example:
 *      ./color_code_converter hex rgb #ff0000
 *
 * Output:
 *      RGB: (255, 0, 0)
 *
 * Supported formats:
 *      - hex : Hexadecimal (#ff0000)
 *      - rgb : Red, Green, Blue (255, 0, 0)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 256

typedef struct {
    int red;
    int green;
    int blue;
} RGB;

typedef struct {
    char hex[MAX_COLOR_CODE_LENGTH];
} Hex;

void convert_hex_to_rgb(Hex *hex, RGB *rgb) {
    char *color_code = hex->hex;
    int red, green, blue;

    if (color_code[0] != '#') {
        fprintf(stderr, "Invalid hex color code\n");
        exit(1);
    }

    sscanf(color_code, "#%02x%02x%02x", &red, &green, &blue);

    rgb->red = red;
    rgb->green = green;
    rgb->blue = blue;
}

void convert_rgb_to_hex(RGB *rgb, Hex *hex) {
    sprintf(hex->hex, "#%02x%02x%02x", rgb->red, rgb->green, rgb->blue);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <from_format> <to_format> <color_code>\n", argv[0]);
        exit(1);
    }

    Hex hex;
    RGB rgb;

    if (strcmp(argv[1], "hex") == 0) {
        strcpy(hex.hex, argv[3]);
        convert_hex_to_rgb(&hex, &rgb);
    } else if (strcmp(argv[1], "rgb") == 0) {
        sscanf(argv[3], "%d,%d,%d", &rgb.red, &rgb.green, &rgb.blue);
        convert_rgb_to_hex(&rgb, &hex);
    } else {
        fprintf(stderr, "Unsupported format: %s\n", argv[1]);
        exit(1);
    }

    if (strcmp(argv[2], "hex") == 0) {
        printf("Hex: %s\n", hex.hex);
    } else if (strcmp(argv[2], "rgb") == 0) {
        printf("RGB: (%d, %d, %d)\n", rgb.red, rgb.green, rgb.blue);
    } else {
        fprintf(stderr, "Unsupported format: %s\n", argv[2]);
        exit(1);
    }

    return 0;
}