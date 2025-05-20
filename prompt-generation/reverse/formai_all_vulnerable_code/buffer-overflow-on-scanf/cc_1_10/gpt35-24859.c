//FormAI DATASET v1.0 Category: Color Code Converter ; Style: active
#include <stdio.h>

int main() {
    int r, g, b;

    // Taking input from user
    printf("Enter the RGB color code (0-255): ");
    scanf("%d %d %d", &r, &g, &b);

    // Converting RGB to HEX
    int hex = (r << 16) | (g << 8) | b;
    printf("The HEX color code for RGB (%d,%d,%d) is #%02X\n", r, g, b, hex);

    // Converting RGB to CMYK
    float c, m, y, k;
    c = 1 - (float)r / 255;
    m = 1 - (float)g / 255;
    y = 1 - (float)b / 255;
    float minCMY = fmin(c, fmin(m, y));
    c = (c - minCMY) / (1 - minCMY);
    m = (m - minCMY) / (1 - minCMY);
    y = (y - minCMY) / (1 - minCMY);
    k = minCMY;
    printf("The CMYK color code for RGB (%d,%d,%d) is (%.2f,%.2f,%.2f,%.2f)\n", r, g, b, c, m, y, k);

    // Converting RGB to HSV
    float h, s, v;
    float maxRGB = fmax(r, fmax(g, b)), minRGB = fmin(r, fmin(g, b));
    float delta = maxRGB - minRGB;

    if (delta == 0) {
        h = 0;
    } else if (maxRGB == r) {
        h = 60 * (((float)g - b) / delta);
    } else if (maxRGB == g) {
        h = 60 * (((float)b - r) / delta + 2.0);
    } else {
        h = 60 * (((float)r - g) / delta + 4.0);
    }

    if (h < 0) {
        h += 360;
    }

    s = maxRGB == 0 ? 0 : delta / maxRGB;
    v = maxRGB / 255.0;

    printf("The HSV color code for RGB (%d,%d,%d) is (%.2f,%.2f,%.2f)\n", r, g, b, h, s, v);

    return 0;
}