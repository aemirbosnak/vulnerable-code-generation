//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Structure to store RGB values
typedef struct RGB {
    int red;
    int green;
    int blue;
} RGB;

// Structure to store HSL values
typedef struct HSL {
    float hue;
    float saturation;
    float lightness;
} HSL;

// Function to convert RGB to HSL
HSL RGBtoHSL(RGB rgb) {
    HSL hsl;

    // Calculate hue
    if (rgb.red == rgb.green && rgb.green == rgb.blue) {
        hsl.hue = 0;
    } else if (rgb.red >= rgb.green && rgb.red >= rgb.blue) {
        hsl.hue = 60 * (rgb.green - rgb.blue) / (rgb.red - rgb.blue);
    } else if (rgb.green >= rgb.red && rgb.green >= rgb.blue) {
        hsl.hue = 60 * (rgb.blue - rgb.red) / (rgb.green - rgb.red) + 120;
    } else {
        hsl.hue = 60 * (rgb.red - rgb.green) / (rgb.blue - rgb.green) + 240;
    }

    // Calculate saturation
    if (rgb.red == rgb.green && rgb.green == rgb.blue) {
        hsl.saturation = 0;
    } else {
        hsl.saturation = (rgb.red - rgb.green + rgb.red - rgb.blue) / (3 * rgb.red + 3 * rgb.green + 3 * rgb.blue);
    }

    // Calculate lightness
    hsl.lightness = (rgb.red + rgb.green + rgb.blue) / (3 * 255);

    return hsl;
}

// Function to convert HSL to RGB
RGB HSLtoRGB(HSL hsl) {
    RGB rgb;

    float c = (1 - abs(2 * hsl.lightness - 1)) * hsl.saturation;
    float x = c * (1 - abs(fmod(hsl.hue / 60, 2) - 1));
    float m = hsl.lightness - c / 2;

    if (hsl.hue >= 0 && hsl.hue < 60) {
        rgb.red = (c + m) * 255;
        rgb.green = (x + m) * 255;
        rgb.blue = m * 255;
    } else if (hsl.hue >= 60 && hsl.hue < 120) {
        rgb.red = (x + m) * 255;
        rgb.green = (c + m) * 255;
        rgb.blue = m * 255;
    } else if (hsl.hue >= 120 && hsl.hue < 180) {
        rgb.red = m * 255;
        rgb.green = (c + m) * 255;
        rgb.blue = (x + m) * 255;
    } else if (hsl.hue >= 180 && hsl.hue < 240) {
        rgb.red = m * 255;
        rgb.green = (x + m) * 255;
        rgb.blue = (c + m) * 255;
    } else if (hsl.hue >= 240 && hsl.hue < 300) {
        rgb.red = (x + m) * 255;
        rgb.green = m * 255;
        rgb.blue = (c + m) * 255;
    } else {
        rgb.red = (c + m) * 255;
        rgb.green = m * 255;
        rgb.blue = (x + m) * 255;
    }

    return rgb;
}

// Main function
int main() {
    // Get RGB values from user
    int red, green, blue;
    printf("Enter RGB values (0-255): ");
    scanf("%d %d %d", &red, &green, &blue);

    // Convert RGB to HSL
    HSL hsl = RGBtoHSL((RGB) { .red = red, .green = green, .blue = blue });

    // Print HSL values
    printf("HSL values: %.2f %.2f %.2f\n", hsl.hue, hsl.saturation, hsl.lightness);

    // Convert HSL to RGB
    RGB rgb = HSLtoRGB(hsl);

    // Print RGB values
    printf("RGB values: %d %d %d\n", rgb.red, rgb.green, rgb.blue);

    return 0;
}