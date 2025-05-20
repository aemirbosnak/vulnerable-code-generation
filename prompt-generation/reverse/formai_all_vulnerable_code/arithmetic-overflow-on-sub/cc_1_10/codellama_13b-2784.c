//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: optimized
/*
 * C Color Code Converter Example Program
 *
 * This program takes a color code in RGB format and converts it to HSV and HSL formats.
 */

#include <stdio.h>
#include <stdlib.h>

// RGB to HSV conversion function
void rgb_to_hsv(int r, int g, int b, float *h, float *s, float *v) {
    float min, max, delta;

    min = fmin(r, fmin(g, b));
    max = fmax(r, fmax(g, b));
    delta = max - min;

    *h = (max == r) ? (g - b) / delta : (max == g) ? 2 + (b - r) / delta : 4 + (r - g) / delta;
    *h *= 60;
    if (*h < 0) *h += 360;

    *s = (max == 0) ? 0 : delta / max;
    *v = max;
}

// RGB to HSL conversion function
void rgb_to_hsl(int r, int g, int b, float *h, float *s, float *l) {
    float min, max, delta;

    min = fmin(r, fmin(g, b));
    max = fmax(r, fmax(g, b));
    delta = max - min;

    *h = (max == r) ? (g - b) / delta : (max == g) ? 2 + (b - r) / delta : 4 + (r - g) / delta;
    *h *= 60;
    if (*h < 0) *h += 360;

    *s = (max == 0) ? 0 : delta / max;
    *l = (max + min) / 2;
}

int main() {
    int r, g, b;
    float h, s, v;

    // Get input from user
    printf("Enter RGB values: ");
    scanf("%d %d %d", &r, &g, &b);

    // Convert RGB to HSV
    rgb_to_hsv(r, g, b, &h, &s, &v);

    // Print HSV values
    printf("HSV values: H = %f, S = %f, V = %f\n", h, s, v);

    // Convert RGB to HSL
    rgb_to_hsl(r, g, b, &h, &s, &v);

    // Print HSL values
    printf("HSL values: H = %f, S = %f, L = %f\n", h, s, v);

    return 0;
}