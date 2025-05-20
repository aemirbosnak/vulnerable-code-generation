//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Declare a structure to represent a color in RGB format
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGBColor;

// Declare a structure to represent a color in HSV format
typedef struct {
    unsigned char hue;
    unsigned char saturation;
    unsigned char value;
} HSVColor;

// Convert an RGB color to an HSV color
void RGBtoHSV(RGBColor rgb, HSVColor *hsv) {
    // Calculate the maximum, minimum, and difference of the RGB values
    unsigned char max = rgb.red;
    if (rgb.green > max) max = rgb.green;
    if (rgb.blue > max) max = rgb.blue;
    unsigned char min = rgb.red;
    if (rgb.green < min) min = rgb.green;
    if (rgb.blue < min) min = rgb.blue;
    unsigned char diff = max - min;

    // Calculate the hue
    if (diff == 0) {
        hsv->hue = 0;
    } else if (max == rgb.red) {
        hsv->hue = (60 * ((rgb.green - rgb.blue) / diff) + 360) % 360;
    } else if (max == rgb.green) {
        hsv->hue = (60 * ((rgb.blue - rgb.red) / diff) + 120) % 360;
    } else {
        hsv->hue = (60 * ((rgb.red - rgb.green) / diff) + 240) % 360;
    }

    // Calculate the saturation
    if (max == 0) {
        hsv->saturation = 0;
    } else {
        hsv->saturation = (diff * 100) / max;
    }

    // Calculate the value
    hsv->value = max;
}

// Convert an HSV color to an RGB color
void HSVtoRGB(HSVColor hsv, RGBColor *rgb) {
    // Calculate the chroma
    unsigned char chroma = (hsv.saturation * hsv.value) / 100;

    // Calculate the hue sector
    unsigned char sector = hsv.hue / 60;

    // Calculate the offset
    unsigned char offset = hsv.value - chroma;

    // Calculate the RGB values
    switch (sector) {
        case 0:
            rgb->red = chroma + offset;
            rgb->green = hsv.value;
            rgb->blue = offset;
            break;
        case 1:
            rgb->red = hsv.value;
            rgb->green = chroma + offset;
            rgb->blue = offset;
            break;
        case 2:
            rgb->red = offset;
            rgb->green = chroma + offset;
            rgb->blue = hsv.value;
            break;
        case 3:
            rgb->red = offset;
            rgb->green = hsv.value;
            rgb->blue = chroma + offset;
            break;
        case 4:
            rgb->red = chroma + offset;
            rgb->green = offset;
            rgb->blue = hsv.value;
            break;
        case 5:
            rgb->red = hsv.value;
            rgb->green = offset;
            rgb->blue = chroma + offset;
            break;
    }
}

// Print a color in RGB format
void printRGBColor(RGBColor color) {
    printf("RGB: (%d, %d, %d)\n", color.red, color.green, color.blue);
}

// Print a color in HSV format
void printHSVColor(HSVColor color) {
    printf("HSV: (%d, %d, %d)\n", color.hue, color.saturation, color.value);
}

// Get a color in RGB format from the user
void getRGBColor(RGBColor *color) {
    printf("Enter the red value (0-255): ");
    scanf("%d", &color->red);
    printf("Enter the green value (0-255): ");
    scanf("%d", &color->green);
    printf("Enter the blue value (0-255): ");
    scanf("%d", &color->blue);
}

// Get a color in HSV format from the user
void getHSVColor(HSVColor *color) {
    printf("Enter the hue value (0-360): ");
    scanf("%d", &color->hue);
    printf("Enter the saturation value (0-100): ");
    scanf("%d", &color->saturation);
    printf("Enter the value value (0-100): ");
    scanf("%d", &color->value);
}

// Main function
int main() {
    // Get the color in RGB format from the user
    RGBColor rgb;
    getRGBColor(&rgb);

    // Convert the RGB color to HSV format
    HSVColor hsv;
    RGBtoHSV(rgb, &hsv);

    // Print the RGB and HSV colors
    printf("RGB: ");
    printRGBColor(rgb);
    printf("HSV: ");
    printHSVColor(hsv);

    return 0;
}