//FormAI DATASET v1.0 Category: Color Code Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert a hex string to an integer
int hexToInt(char* hex) {
    int result = 0;
    int len = strlen(hex);

    for (int i = 0; i < len; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            result = result * 16 + (hex[i] - '0');
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            result = result * 16 + (hex[i] - 'A' + 10);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            result = result * 16 + (hex[i] - 'a' + 10);
        }
    }

    return result;
}

int main() {
    char hex[8];
    printf("Enter a hex color code: ");
    scanf("%s", hex);

    // convert hex color code to RGB values
    int red = hexToInt(hex);
    int green = hexToInt(hex + 2);
    int blue = hexToInt(hex + 4);

    // print the RGB values
    printf("RGB code: (%d, %d, %d)\n", red, green, blue);

    // convert RGB values to CMYK values
    float c = 1.0 - red / 255.0;
    float m = 1.0 - green / 255.0;
    float y = 1.0 - blue / 255.0;
    float k = 0.0;
    if (c < k) {
        k = c;
    }
    if (m < k) {
        k = m;
    }
    if (y < k) {
        k = y;
    }
    if (k == 1.0) {
        c = 0.0;
        m = 0.0;
        y = 0.0;
    } else {
        c = (c - k) / (1.0 - k);
        m = (m - k) / (1.0 - k);
        y = (y - k) / (1.0 - k);
    }

    // print the CMYK values
    printf("CMYK code: (%.2f, %.2f, %.2f, %.2f)\n", c, m, y, k);

    return 0;
}