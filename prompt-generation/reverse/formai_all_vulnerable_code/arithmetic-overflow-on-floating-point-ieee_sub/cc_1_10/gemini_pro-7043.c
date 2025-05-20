//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the color space structures
typedef struct {
    float r, g, b;
} RGB;

typedef struct {
    float h, s, v;
} HSV;

// Define the conversion functions
RGB HSVtoRGB(HSV hsv) {
    float c = hsv.v * hsv.s;
    float x = c * (1 - fabs(fmod(hsv.h / 60.0, 2) - 1));
    float m = hsv.v - c;

    RGB rgb;
    if (hsv.h < 60) {
        rgb.r = c;
        rgb.g = x;
        rgb.b = 0;
    } else if (hsv.h < 120) {
        rgb.r = x;
        rgb.g = c;
        rgb.b = 0;
    } else if (hsv.h < 180) {
        rgb.r = 0;
        rgb.g = c;
        rgb.b = x;
    } else if (hsv.h < 240) {
        rgb.r = 0;
        rgb.g = x;
        rgb.b = c;
    } else if (hsv.h < 300) {
        rgb.r = x;
        rgb.g = 0;
        rgb.b = c;
    } else {
        rgb.r = c;
        rgb.g = 0;
        rgb.b = x;
    }

    rgb.r += m;
    rgb.g += m;
    rgb.b += m;

    return rgb;
}

HSV RGBtoHSV(RGB rgb) {
    float max = fmax(rgb.r, fmax(rgb.g, rgb.b));
    float min = fmin(rgb.r, fmin(rgb.g, rgb.b));
    float delta = max - min;

    HSV hsv;
    if (delta == 0) {
        hsv.h = 0;
        hsv.s = 0;
    } else {
        hsv.h = fmod((60 * ((rgb.g - rgb.b) / delta) + 360), 360);
        hsv.s = delta / max;
    }

    hsv.v = max;

    return hsv;
}

// Define the main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s <r> <g> <b>\n", argv[0]);
        return 1;
    }

    // Parse the RGB values
    RGB rgb;
    rgb.r = atof(argv[1]);
    rgb.g = atof(argv[2]);
    rgb.b = atof(argv[3]);

    // Convert the RGB values to HSV
    HSV hsv = RGBtoHSV(rgb);

    // Print the HSV values
    printf("Hue: %.2f\n", hsv.h);
    printf("Saturation: %.2f\n", hsv.s);
    printf("Value: %.2f\n", hsv.v);

    return 0;
}