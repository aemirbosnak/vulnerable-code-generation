//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGB;

typedef struct {
    float h;
    float s;
    float v;
} HSV;

// Function to convert RGB to HSV
HSV rgbToHsv(RGB rgb) {
    HSV hsv;
    float r = rgb.r / 255.0f;
    float g = rgb.g / 255.0f;
    float b = rgb.b / 255.0f;
    float max = fmaxf(fmaxf(r, g), b);
    float min = fminf(fminf(r, g), b);
    
    // Calculate Value
    hsv.v = max;

    // Calculate Saturation
    if (max == 0) {
        hsv.s = 0;
    } else {
        hsv.s = (max - min) / max;
    }

    // Calculate Hue
    if (max == min) {
        hsv.h = 0; // achromatic
    } else {
        if (max == r) {
            hsv.h = (g - b) / (max - min);
        } else if (max == g) {
            hsv.h = 2.0f + (b - r) / (max - min);
        } else {
            hsv.h = 4.0f + (r - g) / (max - min);
        }
        hsv.h *= 60.0f; // degrees
        if (hsv.h < 0) hsv.h += 360.0f;
    }

    return hsv;
}

// Function to convert HSV to RGB
RGB hsvToRgb(HSV hsv) {
    RGB rgb;
    float r, g, b;

    float c = hsv.v * hsv.s;  // Chroma
    float x = c * (1 - fabsf(fmod(hsv.h / 60.0f, 2) - 1));
    float m = hsv.v - c;

    if (0 <= hsv.h && hsv.h < 60) {
        r = c; g = x; b = 0;
    } else if (60 <= hsv.h && hsv.h < 120) {
        r = x; g = c; b = 0;
    } else if (120 <= hsv.h && hsv.h < 180) {
        r = 0; g = c; b = x;
    } else if (180 <= hsv.h && hsv.h < 240) {
        r = 0; g = x; b = c;
    } else if (240 <= hsv.h && hsv.h < 300) {
        r = x; g = 0; b = c;
    } else {
        r = c; g = 0; b = x;
    }

    rgb.r = (unsigned char)((r + m) * 255);
    rgb.g = (unsigned char)((g + m) * 255);
    rgb.b = (unsigned char)((b + m) * 255);

    return rgb;
}

// Function to display the color
void displayColor(RGB rgb) {
    printf("RGB: (%d, %d, %d)\n", rgb.r, rgb.g, rgb.b);
}

// Function to display the HSV color
void displayColorHSV(HSV hsv) {
    printf("HSV: (%.2f, %.2f, %.2f)\n", hsv.h, hsv.s, hsv.v);
}

int main() {
    RGB rgbInput;
    HSV hsvOutput;

    // Input RGB values
    printf("Enter RGB values (0-255) separated by spaces: ");
    if (scanf("%hhu %hhu %hhu", &rgbInput.r, &rgbInput.g, &rgbInput.b) != 3) {
        fprintf(stderr, "Invalid input. Please enter three numbers (0-255).\n");
        return EXIT_FAILURE;
    }

    // Convert RGB to HSV
    hsvOutput = rgbToHsv(rgbInput);
    printf("Converted ");
    displayColor(rgbInput);
    displayColorHSV(hsvOutput);

    // Convert back to RGB to validate conversion
    RGB rgbOutput = hsvToRgb(hsvOutput);
    printf("Converted back to RGB: ");
    displayColor(rgbOutput);

    return EXIT_SUCCESS;
}