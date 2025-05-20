//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// RGB struct
typedef struct {
    int r, g, b;
} RGB;

// Function to convert a hexadecimal color code to RGB values
RGB convertColor(char* color) {
    RGB rgb;
    rgb.r = rgb.g = rgb.b = 0;

    for (int i = 0; i < 6; i++) {
        char c = color[i];
        if (c >= '0' && c <= '9') {
            rgb.r = (rgb.r * 16) + (c - '0');
        } else if (c >= 'a' && c <= 'f') {
            rgb.r = (rgb.r * 16) + (c - 'a' + 10);
        } else if (c >= 'A' && c <= 'F') {
            rgb.r = (rgb.r * 16) + (c - 'A' + 10);
        } else {
            return rgb;
        }

        if (i < 5) {
            c = color[i + 1];
            if (c >= '0' && c <= '9') {
                rgb.g = (rgb.g * 16) + (c - '0');
            } else if (c >= 'a' && c <= 'f') {
                rgb.g = (rgb.g * 16) + (c - 'a' + 10);
            } else if (c >= 'A' && c <= 'F') {
                rgb.g = (rgb.g * 16) + (c - 'A' + 10);
            } else {
                return rgb;
            }

            if (i < 4) {
                c = color[i + 2];
                if (c >= '0' && c <= '9') {
                    rgb.b = (rgb.b * 16) + (c - '0');
                } else if (c >= 'a' && c <= 'f') {
                    rgb.b = (rgb.b * 16) + (c - 'a' + 10);
                } else if (c >= 'A' && c <= 'F') {
                    rgb.b = (rgb.b * 16) + (c - 'A' + 10);
                } else {
                    return rgb;
                }
            }
        }
    }

    return rgb;
}

int main() {
    char color[6];
    scanf("%s", color);

    RGB rgb;
    rgb = convertColor(color);

    printf("RGB: %d, %d, %d\n", rgb.r, rgb.g, rgb.b);

    return 0;
}