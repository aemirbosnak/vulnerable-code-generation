//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RGB {
    int r, g, b;
} RGB;

RGB rgb_from_string(char* str) {
    RGB rgb;
    sscanf(str, "0x%x%x%x", &rgb.r, &rgb.g, &rgb.b);
    return rgb;
}

char* hex_string(RGB rgb) {
    char str[8];
    sprintf(str, "0x%02x%02x%02x", rgb.r, rgb.g, rgb.b);
    return strdup(str);
}

void convert_color(char* input) {
    RGB color;
    color = rgb_from_string(input);

    char* output = hex_string(color);

    printf("From input '%s', we obtain output in form of '%s'\n", input, output);
    free(output);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <color-code-as-string>\n", argv[0]);
        return 1;
    }

    convert_color(argv[1]);

    return 0;
}

// Thou art enterin' the mystic code realm of our noble program!
// May thine eyes behold the wondrous transformations
// of colors from their humble hexadecimal strings!
//
// Verily, we beseech thee, bring forth a hue
// that tickleth thine fancy, and let it be
// written in the form of a hexadecimal string.
//
// Lo, our noble and faithful servant
// shalt convert that humble string into
// its glorious RGB form!
//
// And lo, behold! The RGB values shalt be
// converted back into a hexadecimal string,
// to be shared with all those who seek
// the wondrous color transformations.
//
// So, meek traveller, bring thy color code
// before our noble program, and be amazed!