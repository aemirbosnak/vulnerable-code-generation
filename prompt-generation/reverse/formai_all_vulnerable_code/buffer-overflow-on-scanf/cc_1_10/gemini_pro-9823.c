//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the RGB color code structure
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGB;

// Define the HSV color code structure
typedef struct {
    unsigned char hue;
    unsigned char saturation;
    unsigned char value;
} HSV;

// Function to convert RGB to HSV
void RGBtoHSV(RGB rgb, HSV *hsv) {
    unsigned char max, min, delta;
    max = rgb.red > rgb.green ? rgb.red : rgb.green;
    max = max > rgb.blue ? max : rgb.blue;
    min = rgb.red < rgb.green ? rgb.red : rgb.green;
    min = min < rgb.blue ? min : rgb.blue;
    hsv->value = max;
    delta = max - min;
    if (delta == 0) {
        hsv->hue = 0;
        hsv->saturation = 0;
    } else {
        if (max == rgb.red) {
            hsv->hue = (unsigned char)((60 * ((rgb.green - rgb.blue) / delta) + 360) % 360);
        } else if (max == rgb.green) {
            hsv->hue = (unsigned char)((60 * ((rgb.blue - rgb.red) / delta) + 120) % 360);
        } else {
            hsv->hue = (unsigned char)((60 * ((rgb.red - rgb.green) / delta) + 240) % 360);
        }
        hsv->saturation = (unsigned char)((100 * delta) / max);
    }
}

// Function to convert HSV to RGB
void HSVtoRGB(HSV hsv, RGB *rgb) {
    unsigned char h, s, v;
    h = hsv.hue;
    s = hsv.saturation;
    v = hsv.value;
    if (s == 0) {
        rgb->red = rgb->green = rgb->blue = v;
    } else {
        h = (h % 360) / 60;
        unsigned char i = h;
        unsigned char f = h - i;
        unsigned char p = v * (1 - s);
        unsigned char q = v * (1 - s * f);
        unsigned char t = v * (1 - s * (1 - f));
        switch (i) {
            case 0:
                rgb->red = v;
                rgb->green = t;
                rgb->blue = p;
                break;
            case 1:
                rgb->red = q;
                rgb->green = v;
                rgb->blue = p;
                break;
            case 2:
                rgb->red = p;
                rgb->green = v;
                rgb->blue = t;
                break;
            case 3:
                rgb->red = p;
                rgb->green = q;
                rgb->blue = v;
                break;
            case 4:
                rgb->red = t;
                rgb->green = p;
                rgb->blue = v;
                break;
            case 5:
                rgb->red = v;
                rgb->green = p;
                rgb->blue = q;
                break;
        }
    }
}

int main() {
    // Get the RGB color code from the user
    RGB rgb;
    printf("Enter the RGB color code (red, green, blue): ");
    scanf("%hhd, %hhd, %hhd", &rgb.red, &rgb.green, &rgb.blue);

    // Convert RGB to HSV
    HSV hsv;
    RGBtoHSV(rgb, &hsv);

    // Print the HSV color code
    printf("The HSV color code is (hue, saturation, value): %hhu, %hhu, %hhu\n", hsv.hue, hsv.saturation, hsv.value);

    // Convert HSV to RGB
    RGB rgb2;
    HSVtoRGB(hsv, &rgb2);

    // Print the original RGB color code and the converted RGB color code
    printf("The original RGB color code is: (%hhu, %hhu, %hhu)\n", rgb.red, rgb.green, rgb.blue);
    printf("The converted RGB color code is: (%hhu, %hhu, %hhu)\n", rgb2.red, rgb2.green, rgb2.blue);

    return 0;
}