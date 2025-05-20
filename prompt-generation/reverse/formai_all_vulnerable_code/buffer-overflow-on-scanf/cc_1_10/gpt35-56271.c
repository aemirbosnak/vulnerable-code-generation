//FormAI DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Color Code struct */
typedef struct {
    int red, green, blue;
} ColorCode;

/* Function prototypes */
ColorCode hexToRgb(char* hexCode);
ColorCode hsvToRgb(int hue, int saturation, int value);
void printRgb(ColorCode code);
void printHex(ColorCode code);

/* Main function */
int main() {

    /* User input */
    char input[7];
    printf("Enter a valid Hex color code: ");
    scanf("%s", input);

    /* Convert hex to rgb */
    ColorCode rgbCode = hexToRgb(input);

    /* Print rgb color code */
    printf("RGB color code: ");
    printRgb(rgbCode);

    /* Convert rgb to hsv */
    int h, s, v;
    int max = rgbCode.red > rgbCode.green ? (rgbCode.red > rgbCode.blue ? rgbCode.red : rgbCode.blue) : (rgbCode.green > rgbCode.blue ? rgbCode.green : rgbCode.blue);
    int min = rgbCode.red < rgbCode.green ? (rgbCode.red < rgbCode.blue ? rgbCode.red : rgbCode.blue) : (rgbCode.green < rgbCode.blue ? rgbCode.green : rgbCode.blue);
    if (max == min) {
        h = 0;
    } else if (max == rgbCode.red && rgbCode.green >= rgbCode.blue) {
        h = 60 * (rgbCode.green - rgbCode.blue) / (max - min) + 0;
    } else if (max == rgbCode.red && rgbCode.green < rgbCode.blue) {
        h = 60 * (rgbCode.green - rgbCode.blue) / (max - min) + 360;
    } else if (max == rgbCode.green) {
        h = 60 * (rgbCode.blue - rgbCode.red) / (max - min) + 120;
    } else if (max == rgbCode.blue) {
        h = 60 * (rgbCode.red - rgbCode.green) / (max - min) + 240;
    }
    s = max == 0 ? 0 : (max - min) * 100 / max;
    v = max * 100 / 255;

    /* Convert hsv to rgb */
    ColorCode hsvCode = {h, s, v};
    ColorCode rgbCode2 = hsvToRgb(hsvCode.red, hsvCode.green, hsvCode.blue);

    /* Print hsv and rgb color codes */
    printf("HSV color code: %d %d %d\n", hsvCode.red, hsvCode.green, hsvCode.blue);
    printf("RGB color code: ");
    printRgb(rgbCode2);

    /* Convert rgb to hex */
    char hexCode[7];
    sprintf(hexCode, "#%02X%02X%02X", rgbCode2.red, rgbCode2.green, rgbCode2.blue);

    /* Print hex color code */
    printf("Hex color code: %s\n", hexCode);

    return 0;
}

/* Function to convert hex to rgb */
ColorCode hexToRgb(char* hexCode) {
    ColorCode code;
    sscanf(hexCode, "#%02X%02X%02X", &code.red, &code.green, &code.blue);
    return code;
}

/* Function to convert hsv to rgb */
ColorCode hsvToRgb(int hue, int saturation, int value) {
    float s = saturation / 100.0;
    float v = value / 100.0;
    float c = s * v;
    float x = c * (1 - abs(fmod(hue / 60.0, 2) - 1));
    float m = v - c;
    float r, g, b;
    if (hue >= 0 && hue < 60) {
        r = c, g = x, b = 0;
    } else if (hue >= 60 && hue < 120) {
        r = x, g = c, b = 0;
    } else if (hue >= 120 && hue < 180) {
        r = 0, g = c, b = x;
    } else if (hue >= 180 && hue < 240) {
        r = 0, g = x, b = c;
    } else if (hue >= 240 && hue < 300) {
        r = x, g = 0, b = c;
    } else {
        r = c, g = 0, b = x;
    }
    return (ColorCode){(int)((r + m) * 255), (int)((g + m) * 255), (int)((b + m) * 255)};
}

/* Function to print rgb color code */
void printRgb(ColorCode code) {
    printf("(%d, %d, %d)\n", code.red, code.green, code.blue);
}

/* Function to print hex color code */
void printHex(ColorCode code) {
    printf("#%02X%02X%02X\n", code.red, code.green, code.blue);
}