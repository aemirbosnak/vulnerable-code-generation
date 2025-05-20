//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGB;

typedef struct {
    float hue;
    float saturation;
    float lightness;
} HSL;

void rgbToHsl(RGB rgb, HSL *hsl) {
    float r = rgb.red / 255.0;
    float g = rgb.green / 255.0;
    float b = rgb.blue / 255.0;
    float max = fmax(r, fmax(g, b));
    float min = fmin(r, fmin(g, b));
    float delta = max - min;

    // Calculate hue
    if (delta == 0) {
        hsl->hue = 0;
    } else if (max == r) {
        hsl->hue = fmod(((g - b) / delta), 6) * 60;
    } else if (max == g) {
        hsl->hue = (((b - r) / delta) + 2) * 60;
    } else {
        hsl->hue = (((r - g) / delta) + 4) * 60;
    }

    if (hsl->hue < 0) hsl->hue += 360;

    // Calculate lightness
    hsl->lightness = (max + min) / 2;

    // Calculate saturation
    if (delta == 0) {
        hsl->saturation = 0;
    } else {
        hsl->saturation = delta / (1 - fabs(2 * hsl->lightness - 1));
    }
}

void hslToRgb(HSL hsl, RGB *rgb) {
    float r, g, b;
    float c = (1 - fabs(2 * hsl.lightness - 1)) * hsl.saturation;
    float x = c * (1 - fabs(fmod(hsl.hue / 60, 2) - 1));
    float m = hsl.lightness - c / 2;

    // Determine RGB values based on the hue
    if (hsl.hue >= 0 && hsl.hue < 60) {
        r = c; g = x; b = 0;
    } else if (hsl.hue >= 60 && hsl.hue < 120) {
        r = x; g = c; b = 0;
    } else if (hsl.hue >= 120 && hsl.hue < 180) {
        r = 0; g = c; b = x;
    } else if (hsl.hue >= 180 && hsl.hue < 240) {
        r = 0; g = x; b = c;
    } else if (hsl.hue >= 240 && hsl.hue < 300) {
        r = x; g = 0; b = c;
    } else {
        r = c; g = 0; b = x;
    }

    rgb->red = (unsigned char)((r + m) * 255);
    rgb->green = (unsigned char)((g + m) * 255);
    rgb->blue = (unsigned char)((b + m) * 255);
}

void printColor(RGB rgb, HSL hsl){
    printf("RGB: (%d, %d, %d) | HSL: (%.2f°, %.2f%%, %.2f%%)\n", 
           rgb.red, rgb.green, rgb.blue, 
           hsl.hue, hsl.saturation * 100, hsl.lightness * 100);
}

int main() {
    RGB rgb;
    HSL hsl;

    printf("Welcome to the Color Converter!\n");
    printf("Enter the Red, Green, and Blue values (0-255) separated by spaces: ");
    if (scanf("%hhu %hhu %hhu", &rgb.red, &rgb.green, &rgb.blue) != 3) {
        fprintf(stderr, "Invalid input. Please enter three numbers.\n");
        return EXIT_FAILURE;
    }

    rgbToHsl(rgb, &hsl);
    printf("\nColor conversion successful!\n");
    printColor(rgb, hsl);

    printf("\nEnter the Hue, Saturation (0-1), and Lightness (0-1) separated by spaces to convert back to RGB: ");
    if (scanf("%f %f %f", &hsl.hue, &hsl.saturation, &hsl.lightness) != 3) {
        fprintf(stderr, "Invalid input. Please enter three numbers.\n");
        return EXIT_FAILURE;
    }

    hslToRgb(hsl, &rgb);
    printf("\nColor conversion successful!\n");
    printColor(rgb, hsl);

    return EXIT_SUCCESS;
}