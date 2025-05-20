//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: scalable
#include <stdio.h>

void rgb_to_hex(int r, int g, int b, char *hex) {
    int rgb_hex[3] = {r * 2, g * 2, b * 2};
    int len = 3;
    for (int i = 0; i < len; i++) {
        if (rgb_hex[i] < 10) {
            hex[i] = '0' + rgb_hex[i];
        } else {
            hex[i] = 'A' - 10 + rgb_hex[i];
        }
    }
}

int main() {
    char hex_color[6] = "";
    printf("Enter the hexadecimal color code: ");
    scanf("%s", hex_color);

    int r, g, b;
    int len = 3;
    for (int i = 0; i < len; i++) {
        if (hex_color[i] >= '0' && hex_color[i] <= '9') {
            r += (hex_color[i] - '0') * 16;
        } else if (hex_color[i] >= 'A' && hex_color[i] <= 'F') {
            r += (hex_color[i] - 'A') * 10;
        } else if (hex_color[i] == 'F') {
            r = 255;
        }
    }

    for (int i = 0; i < len; i++) {
        if (hex_color[i] >= '0' && hex_color[i] <= '9') {
            g += (hex_color[i] - '0') * 16;
        } else if (hex_color[i] >= 'A' && hex_color[i] <= 'F') {
            g += (hex_color[i] - 'A') * 10;
        } else if (hex_color[i] == 'F') {
            g = 255;
        }
    }

    for (int i = 0; i < len; i++) {
        if (hex_color[i] >= '0' && hex_color[i] <= '9') {
            b += (hex_color[i] - '0') * 16;
        } else if (hex_color[i] >= 'A' && hex_color[i] <= 'F') {
            b += (hex_color[i] - 'A') * 10;
        } else if (hex_color[i] == 'F') {
            b = 255;
        }
    }

    rgb_to_hex(r, g, b, hex_color);

    printf("The RGB values of the color are: %d, %d, %d\n", r, g, b);

    return 0;
}