//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: calm
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the RGB color space
typedef struct {
    float r;
    float g;
    float b;
} rgb_color;

// Define the HSL color space
typedef struct {
    float h;
    float s;
    float l;
} hsl_color;

// Convert RGB to HSL
hsl_color rgb_to_hsl(rgb_color rgb) {
    hsl_color hsl;

    // Calculate the hue
    float r = rgb.r / 255.0;
    float g = rgb.g / 255.0;
    float b = rgb.b / 255.0;

    float max = fmax(r, fmax(g, b));
    float min = fmin(r, fmin(g, b));

    float hue;
    if (max == min) {
        hue = 0.0;
    } else if (max == r) {
        hue = (60.0 * (g - b) / (max - min) + 360.0) / 360.0;
    } else if (max == g) {
        hue = (60.0 * (b - r) / (max - min) + 120.0) / 360.0;
    } else {
        hue = (60.0 * (r - g) / (max - min) + 240.0) / 360.0;
    }

    // Calculate the saturation
    float saturation;
    if (max == 0.0) {
        saturation = 0.0;
    } else {
        saturation = (max - min) / max;
    }

    // Calculate the lightness
    float lightness = (max + min) / 2.0;

    // Return the HSL color
    hsl.h = hue;
    hsl.s = saturation;
    hsl.l = lightness;
    return hsl;
}

// Convert HSL to RGB
rgb_color hsl_to_rgb(hsl_color hsl) {
    rgb_color rgb;

    // Calculate the red, green, and blue components
    float h = hsl.h;
    float s = hsl.s;
    float l = hsl.l;

    float r, g, b;
    if (s == 0.0) {
        r = g = b = l;
    } else {
        float q = l < 0.5 ? l * (1.0 + s) : l + s - l * s;
        float p = 2.0 * l - q;

        float hk = h / 360.0;
        float t[3] = {hk + 1.0 / 3.0, hk, hk - 1.0 / 3.0};

        for (int i = 0; i < 3; i++) {
            if (t[i] < 0.0) {
                t[i] += 1.0;
            }
            if (t[i] > 1.0) {
                t[i] -= 1.0;
            }

            if (t[i] < 1.0 / 6.0) {
                t[i] = p + ((q - p) * 6.0 * t[i]);
            } else if (t[i] < 1.0 / 2.0) {
                t[i] = q;
            } else if (t[i] < 2.0 / 3.0) {
                t[i] = p + ((q - p) * 6.0 * (2.0 / 3.0 - t[i]));
            } else {
                t[i] = p;
            }
        }

        r = t[0] * 255.0;
        g = t[1] * 255.0;
        b = t[2] * 255.0;
    }

    // Return the RGB color
    rgb.r = r;
    rgb.g = g;
    rgb.b = b;
    return rgb;
}

// Print the RGB color
void print_rgb_color(rgb_color rgb) {
    printf("RGB: (%f, %f, %f)\n", rgb.r, rgb.g, rgb.b);
}

// Print the HSL color
void print_hsl_color(hsl_color hsl) {
    printf("HSL: (%f, %f, %f)\n", hsl.h, hsl.s, hsl.l);
}

// Get the RGB color from the user
rgb_color get_rgb_color() {
    rgb_color rgb;

    printf("Enter the red component (0-255): ");
    scanf("%f", &rgb.r);

    printf("Enter the green component (0-255): ");
    scanf("%f", &rgb.g);

    printf("Enter the blue component (0-255): ");
    scanf("%f", &rgb.b);

    return rgb;
}

// Get the HSL color from the user
hsl_color get_hsl_color() {
    hsl_color hsl;

    printf("Enter the hue (0-360): ");
    scanf("%f", &hsl.h);

    printf("Enter the saturation (0-1): ");
    scanf("%f", &hsl.s);

    printf("Enter the lightness (0-1): ");
    scanf("%f", &hsl.l);

    return hsl;
}

// Main function
int main() {
    // Get the RGB color from the user
    rgb_color rgb = get_rgb_color();

    // Convert the RGB color to HSL
    hsl_color hsl = rgb_to_hsl(rgb);

    // Print the RGB and HSL colors
    print_rgb_color(rgb);
    print_hsl_color(hsl);

    return 0;
}