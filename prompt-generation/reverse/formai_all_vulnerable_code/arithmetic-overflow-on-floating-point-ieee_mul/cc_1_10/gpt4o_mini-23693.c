//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int r, g, b;
} RGB;

typedef struct {
    float h, s, l;
} HSL;

typedef struct {
    char hex[7];
} HEX;

RGB hexToRGB(const char *hex) {
    RGB rgb;
    sscanf(hex, "%2x%2x%2x", &rgb.r, &rgb.g, &rgb.b);
    return rgb;
}

HEX rgbToHEX(RGB rgb) {
    HEX hex;
    sprintf(hex.hex, "%02X%02X%02X", rgb.r, rgb.g, rgb.b);
    return hex;
}

HSL rgbToHSL(RGB rgb) {
    HSL hsl;
    float r = rgb.r / 255.0;
    float g = rgb.g / 255.0;
    float b = rgb.b / 255.0;

    float max = fmax(r, fmax(g, b));
    float min = fmin(r, fmin(g, b));
    float delta = max - min;

    // Hue calculation
    if (delta == 0) {
        hsl.h = 0; // undefined
    } else if (max == r) {
        hsl.h = 60 * fmod((g - b) / delta, 6);
    } else if (max == g) {
        hsl.h = 60 * ((b - r) / delta + 2);
    } else {
        hsl.h = 60 * ((r - g) / delta + 4);
    }
    
    if (hsl.h < 0) {
        hsl.h += 360;
    }

    // Lightness calculation
    hsl.l = (max + min) / 2;

    // Saturation calculation
    if (delta == 0) {
        hsl.s = 0; // undefined
    } else {
        hsl.s = delta / (1 - fabs(2 * hsl.l - 1));
    }

    return hsl;
}

RGB hslToRGB(HSL hsl) {
    RGB rgb;
    float c = (1 - fabs(2 * hsl.l - 1)) * hsl.s; // Chroma
    float x = c * (1 - fabs(fmod(hsl.h / 60, 2) - 1)); // Second largest component
    float m = hsl.l - c / 2; // Match value
    float r, g, b;

    if (hsl.h < 60) {
        r = c; g = x; b = 0;
    } else if (hsl.h < 120) {
        r = x; g = c; b = 0;
    } else if (hsl.h < 180) {
        r = 0; g = c; b = x;
    } else if (hsl.h < 240) {
        r = 0; g = x; b = c;
    } else if (hsl.h < 300) {
        r = x; g = 0; b = c;
    } else {
        r = c; g = 0; b = x;
    }
    
    rgb.r = (r + m) * 255;
    rgb.g = (g + m) * 255;
    rgb.b = (b + m) * 255;

    return rgb;
}

void displayMenu() {
    printf("Color Code Converter\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("3. RGB to HSL\n");
    printf("4. HSL to RGB\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    RGB rgb;
    HSL hsl;
    HEX hex;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter RGB values (0-255) separated by space: ");
                scanf("%d %d %d", &rgb.r, &rgb.g, &rgb.b);
                hex = rgbToHEX(rgb);
                printf("HEX: #%s\n", hex.hex);
                break;

            case 2:
                printf("Enter HEX value (without #): ");
                char hexInput[7];
                scanf("%s", hexInput);
                rgb = hexToRGB(hexInput);
                printf("RGB: (%d, %d, %d)\n", rgb.r, rgb.g, rgb.b);
                break;

            case 3:
                printf("Enter RGB values (0-255) separated by space: ");
                scanf("%d %d %d", &rgb.r, &rgb.g, &rgb.b);
                hsl = rgbToHSL(rgb);
                printf("HSL: (%.2f, %.2f, %.2f)\n", hsl.h, hsl.s, hsl.l);
                break;

            case 4:
                printf("Enter HSL values (0-360, 0-1, 0-1) separated by space: ");
                scanf("%f %f %f", &hsl.h, &hsl.s, &hsl.l);
                rgb = hslToRGB(hsl);
                printf("RGB: (%d, %d, %d)\n", rgb.r, rgb.g, rgb.b);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;
            
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}