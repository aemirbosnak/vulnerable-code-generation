//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the RGB color structure
typedef struct RGBColor {
    int red;
    int green;
    int blue;
} RGBColor;

// Define the HSV color structure
typedef struct HSVColor {
    float hue;
    float saturation;
    float value;
} HSVColor;

// Define the conversion functions
RGBColor HSVtoRGB(HSVColor hsv);
HSVColor RGBtoHSV(RGBColor rgb);

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has entered the correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <hue> <saturation> <value>\n", argv[0]);
        return 1;
    }

    // Parse the user's input
    float hue = atof(argv[1]);
    float saturation = atof(argv[2]);
    float value = atof(argv[3]);

    // Convert the HSV color to an RGB color
    RGBColor rgb = HSVtoRGB((HSVColor) {hue, saturation, value});

    // Print the RGB color to the console
    printf("RGB: (%d, %d, %d)\n", rgb.red, rgb.green, rgb.blue);

    return 0;
}

// Convert HSV to RGB
RGBColor HSVtoRGB(HSVColor hsv) {
    // Check if the HSV values are valid
    if (hsv.hue < 0.0f || hsv.hue > 360.0f) {
        printf("Invalid hue value\n");
        return (RGBColor) {0, 0, 0};
    }
    if (hsv.saturation < 0.0f || hsv.saturation > 1.0f) {
        printf("Invalid saturation value\n");
        return (RGBColor) {0, 0, 0};
    }
    if (hsv.value < 0.0f || hsv.value > 1.0f) {
        printf("Invalid value value\n");
        return (RGBColor) {0, 0, 0};
    }

    // Calculate the RGB values
    float C = hsv.value * hsv.saturation;
    float X = C * (1 - abs(fmod(hsv.hue / 60.0f, 2) - 1));
    float m = hsv.value - C;
    float r, g, b;
    if (hsv.hue >= 0.0f && hsv.hue < 60.0f) {
        r = C;
        g = X;
        b = 0;
    } else if (hsv.hue >= 60.0f && hsv.hue < 120.0f) {
        r = X;
        g = C;
        b = 0;
    } else if (hsv.hue >= 120.0f && hsv.hue < 180.0f) {
        r = 0;
        g = C;
        b = X;
    } else if (hsv.hue >= 180.0f && hsv.hue < 240.0f) {
        r = 0;
        g = X;
        b = C;
    } else if (hsv.hue >= 240.0f && hsv.hue < 300.0f) {
        r = X;
        g = 0;
        b = C;
    } else if (hsv.hue >= 300.0f && hsv.hue < 360.0f) {
        r = C;
        g = 0;
        b = X;
    }

    // Return the RGB color
    return (RGBColor) {
        (int) ((r + m) * 255),
        (int) ((g + m) * 255),
        (int) ((b + m) * 255)
    };
}

// Convert RGB to HSV
HSVColor RGBtoHSV(RGBColor rgb) {
    // Check if the RGB values are valid
    if (rgb.red < 0 || rgb.red > 255) {
        printf("Invalid red value\n");
        return (HSVColor) {0.0f, 0.0f, 0.0f};
    }
    if (rgb.green < 0 || rgb.green > 255) {
        printf("Invalid green value\n");
        return (HSVColor) {0.0f, 0.0f, 0.0f};
    }
    if (rgb.blue < 0 || rgb.blue > 255) {
        printf("Invalid blue value\n");
        return (HSVColor) {0.0f, 0.0f, 0.0f};
    }

    // Calculate the HSV values
    float r = rgb.red / 255.0f;
    float g = rgb.green / 255.0f;
    float b = rgb.blue / 255.0f;
    float max = fmax(r, fmax(g, b));
    float min = fmin(r, fmin(g, b));
    float C = max - min;
    float V = max;
    float H;
    if (C == 0.0f) {
        H = 0.0f;
    } else if (max == r) {
        H = 60.0f * (0.0f + (g - b) / C);
    } else if (max == g) {
        H = 60.0f * (2.0f + (b - r) / C);
    } else if (max == b) {
        H = 60.0f * (4.0f + (r - g) / C);
    }
    if (H < 0.0f) {
        H += 360.0f;
    }
    float S;
    if (V == 0.0f) {
        S = 0.0f;
    } else {
        S = C / V;
    }

    // Return the HSV color
    return (HSVColor) {
        H,
        S,
        V
    };
}