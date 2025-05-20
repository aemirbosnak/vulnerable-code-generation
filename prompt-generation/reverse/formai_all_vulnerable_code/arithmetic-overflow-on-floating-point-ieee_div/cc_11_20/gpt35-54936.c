//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int hex1, hex2, hex3;

    printf("Enter the RGB color values in HEX codes (without the # symbol):\n");
    printf("First two digits: ");
    scanf("%02X", &hex1);
    printf("Next two digits: ");
    scanf("%02X", &hex2);
    printf("Last two digits: ");
    scanf("%02X", &hex3);

    printf("The RGB color codes are: (%d, %d, %d)", hex1, hex2, hex3);

    int red = hex1;
    int green = hex2;
    int blue = hex3;

    float r = (float) red / 255;
    float g = (float) green / 255;
    float b = (float) blue / 255;

    float max = r > g ? r : g;
    max = max > b ? max : b;

    float min = r < g ? r : g;
    min = min < b ? min : b;

    float delta = max - min;

    float hue = 0;
    if (max == r && g >= b) {
        hue = 60 * ((g - b) / delta);
    } else if (max == r && g < b) {
        hue = 60 * ((g - b) / delta) + 360;
    } else if (max == g) {
        hue = 60 * ((b - r) / delta) + 120;
    } else if (max == b) {
        hue = 60 * ((r - g) / delta) + 240;
    }

    float saturation = delta / max;

    float lightness = (max + min) / 2;

    printf("\nHSL color codes:\n");
    printf("Hue: %.2f\nSaturation: %.2f\nLightness: %.2f", hue, saturation * 100, lightness * 100);

    return 0;
}