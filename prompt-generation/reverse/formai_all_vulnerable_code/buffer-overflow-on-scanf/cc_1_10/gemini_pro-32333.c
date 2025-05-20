//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

// Define the RGB color struct
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} color_t;

// Define the HSV color struct
typedef struct {
    float h;
    float s;
    float v;
} hsv_t;

// Define the conversion functions
color_t hsv_to_rgb(hsv_t hsv);
hsv_t rgb_to_hsv(color_t rgb);

// Main function
int main() {
    // Declare the RGB and HSV color variables
    color_t rgb;
    hsv_t hsv;

    // Get the RGB color from the user
    printf("Enter the RGB color (r, g, b): ");
    scanf("%hhu, %hhu, %hhu", &rgb.r, &rgb.g, &rgb.b);

    // Convert the RGB color to HSV
    hsv = rgb_to_hsv(rgb);

    // Print the HSV color
    printf("The HSV color is (h, s, v): (%.2f, %.2f, %.2f)\n", hsv.h, hsv.s, hsv.v);

    return 0;
}

// Convert RGB to HSV
hsv_t rgb_to_hsv(color_t rgb) {
    hsv_t hsv;

    // Calculate the maximum and minimum values of the RGB components
    uint8_t max = fmax(rgb.r, fmax(rgb.g, rgb.b));
    uint8_t min = fmin(rgb.r, fmin(rgb.g, rgb.b));

    // Calculate the hue
    hsv.h = 0.0f;
    if (max == rgb.r) {
        hsv.h = (rgb.g - rgb.b) / (max - min);
    } else if (max == rgb.g) {
        hsv.h = 2.0f + (rgb.b - rgb.r) / (max - min);
    } else if (max == rgb.b) {
        hsv.h = 4.0f + (rgb.r - rgb.g) / (max - min);
    }
    hsv.h *= 60.0f;
    if (hsv.h < 0.0f) {
        hsv.h += 360.0f;
    }

    // Calculate the saturation
    hsv.s = 0.0f;
    if (max != 0) {
        hsv.s = (max - min) / max;
    }

    // Calculate the value
    hsv.v = max / 255.0f;

    return hsv;
}

// Convert HSV to RGB
color_t hsv_to_rgb(hsv_t hsv) {
    color_t rgb;

    float c = hsv.s * hsv.v;
    float x = c * (1 - fabs(fmod(hsv.h / 60.0f, 2) - 1));
    float m = hsv.v - c;

    if (hsv.h < 60.0f) {
        rgb.r = c + m;
        rgb.g = x + m;
        rgb.b = m;
    } else if (hsv.h < 120.0f) {
        rgb.r = x + m;
        rgb.g = c + m;
        rgb.b = m;
    } else if (hsv.h < 180.0f) {
        rgb.r = m;
        rgb.g = c + m;
        rgb.b = x + m;
    } else if (hsv.h < 240.0f) {
        rgb.r = m;
        rgb.g = x + m;
        rgb.b = c + m;
    } else if (hsv.h < 300.0f) {
        rgb.r = x + m;
        rgb.g = m;
        rgb.b = c + m;
    } else {
        rgb.r = c + m;
        rgb.g = m;
        rgb.b = x + m;
    }

    rgb.r *= 255.0f;
    rgb.g *= 255.0f;
    rgb.b *= 255.0f;

    return rgb;
}