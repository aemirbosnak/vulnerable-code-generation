//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the RGB color model
struct rgb {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

// Define the HSV color model
struct hsv {
    float hue;
    float saturation;
    float value;
};

// Convert RGB to HSV
void rgb_to_hsv(struct rgb *rgb, struct hsv *hsv) {
    float r = (float)rgb->red / 255.0;
    float g = (float)rgb->green / 255.0;
    float b = (float)rgb->blue / 255.0;
    float max = fmax(fmax(r, g), b);
    float min = fmin(fmin(r, g), b);
    float delta = max - min;

    hsv->value = max;

    if (max != 0.0) {
        hsv->saturation = delta / max;
    } else {
        hsv->saturation = 0.0;
    }

    if (hsv->saturation == 0.0) {
        hsv->hue = 0.0;
    } else {
        if (r == max) {
            hsv->hue = (g - b) / delta;
        } else if (g == max) {
            hsv->hue = 2 + (b - r) / delta;
        } else {
            hsv->hue = 4 + (r - g) / delta;
        }

        hsv->hue *= 60.0;

        if (hsv->hue < 0.0) {
            hsv->hue += 360.0;
        }
    }
}

// Convert HSV to RGB
void hsv_to_rgb(struct hsv *hsv, struct rgb *rgb) {
    float h = hsv->hue / 60.0;
    float s = hsv->saturation;
    float v = hsv->value;
    int i = (int)h;
    float f = h - i;

    float p = v * (1.0 - s);
    float q = v * (1.0 - (s * f));
    float t = v * (1.0 - (s * (1.0 - f)));

    switch (i) {
        case 0:
            rgb->red = v * 255;
            rgb->green = t * 255;
            rgb->blue = p * 255;
            break;
        case 1:
            rgb->red = q * 255;
            rgb->green = v * 255;
            rgb->blue = p * 255;
            break;
        case 2:
            rgb->red = p * 255;
            rgb->green = v * 255;
            rgb->blue = t * 255;
            break;
        case 3:
            rgb->red = p * 255;
            rgb->green = q * 255;
            rgb->blue = v * 255;
            break;
        case 4:
            rgb->red = t * 255;
            rgb->green = p * 255;
            rgb->blue = v * 255;
            break;
        case 5:
            rgb->red = v * 255;
            rgb->green = p * 255;
            rgb->blue = q * 255;
            break;
    }
}

// Print the RGB color values
void print_rgb(struct rgb *rgb) {
    printf("Red:   %3d\n", rgb->red);
    printf("Green: %3d\n", rgb->green);
    printf("Blue:  %3d\n", rgb->blue);
}

// Print the HSV color values
void print_hsv(struct hsv *hsv) {
    printf("Hue:      %6.2f\n", hsv->hue);
    printf("Saturation:%6.2f\n", hsv->saturation);
    printf("Value:    %6.2f\n", hsv->value);
}

// Convert a hex string to an RGB color
struct rgb hex_to_rgb(char *hex) {
    struct rgb rgb;

    rgb.red = (unsigned char)strtol(hex, NULL, 16);
    rgb.green = (unsigned char)strtol(hex + 2, NULL, 16);
    rgb.blue = (unsigned char)strtol(hex + 4, NULL, 16);

    return rgb;
}

// Convert an RGB color to a hex string
char *rgb_to_hex(struct rgb *rgb) {
    char *hex = malloc(7);

    sprintf(hex, "#%02X%02X%02X", rgb->red, rgb->green, rgb->blue);

    return hex;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <hex color>\n", argv[0]);
        return 1;
    }

    // Convert the hex string to an RGB color
    struct rgb rgb = hex_to_rgb(argv[1]);

    // Convert the RGB color to an HSV color
    struct hsv hsv;
    rgb_to_hsv(&rgb, &hsv);

    // Print the RGB color values
    printf("RGB:\n");
    print_rgb(&rgb);

    // Print the HSV color values
    printf("\nHSV:\n");
    print_hsv(&hsv);

    return 0;
}