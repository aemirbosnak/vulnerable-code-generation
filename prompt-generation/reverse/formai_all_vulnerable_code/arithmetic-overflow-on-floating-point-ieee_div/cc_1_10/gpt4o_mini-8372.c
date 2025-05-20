//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct RGB {
    int r;
    int g;
    int b;
};

struct HSL {
    double h;
    double s;
    double l;
};

struct Color {
    struct RGB rgb;
    struct HSL hsl;
    char hex[7];
};

struct Color convertHexToRGB(const char* hex) {
    struct Color color;
    sscanf(hex, "%2x%2x%2x", &color.rgb.r, &color.rgb.g, &color.rgb.b);
    return color;
}

struct Color convertRGBToHSL(struct Color color) {
    double r = color.rgb.r / 255.0;
    double g = color.rgb.g / 255.0;
    double b = color.rgb.b / 255.0;

    double max = fmax(fmax(r, g), b);
    double min = fmin(fmin(r, g), b);
    
    color.hsl.l = (max + min) / 2.0;

    if(max == min) {
        color.hsl.h = color.hsl.s = 0; // achromatic
    } else {
        double d = max - min;
        color.hsl.s = color.hsl.l > 0.5 ? d / (2 - max - min) : d / (max + min);

        if(max == r) {
            color.hsl.h = fmod(((g - b) / d), 6);
        } else if(max == g) {
            color.hsl.h = ((b - r) / d) + 2;
        } else {
            color.hsl.h = ((r - g) / d) + 4;
        }
        color.hsl.h *= 60;
        if(color.hsl.h < 0) color.hsl.h += 360;
    }
    return color;
}

void convertAndDisplayColors(char* hex) {
    struct Color color = convertHexToRGB(hex);
    color = convertRGBToHSL(color);

    printf("Hex: #%s\n", hex);
    printf("RGB: (%d, %d, %d)\n", color.rgb.r, color.rgb.g, color.rgb.b);
    printf("HSL: (%.1f, %.2f, %.2f)\n", color.hsl.h, color.hsl.s * 100, color.hsl.l * 100);
}

int isValidHex(const char* hex) {
    return (strlen(hex) == 6) && (strspn(hex, "0123456789abcdefABCDEF") == 6);
}

int main() {
    char hex[7];
    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter a hex color code (6 characters, e.g., ff5733): ");
    scanf("%6s", hex);

    if (isValidHex(hex)) {
        convertAndDisplayColors(hex);
    } else {
        printf("Invalid hex color code! Please use a six-character hex code.\n");
    }

    return 0;
}